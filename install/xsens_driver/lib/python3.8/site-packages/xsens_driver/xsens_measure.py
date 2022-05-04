#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import SetParametersResult
from rclpy.parameter import Parameter

import time
from haversine import haversine, Unit

from .utils.mtdevice import find_devices, find_baudrate, MTDevice, get_output_config
from .utils.mtdef import SyncSetting, SyncFunction, SyncLine

from xsens_msgs.msg import AccAA, AccAF, AngWR, OriOE, PosPL, PosPA, StaSW, ConfigXsens
from xsens_msgs.srv import RTCMdata

class XSensDriver(Node):

	def __init__(self):
		super().__init__('XSensDriver')
		
		# Parameters
		self.portName = None
		self.baudrate = None
		self.outputConfig = None
		self.syncConfig = None
		self.lastPos3D = (0, 0, 0)	# Position of last RTCM refresh
		self.xsens_status = "Inactive"
		# Initial status message
		self.sta_sw_msg = StaSW()
		self.sta_sw_msg.xsens_status = self.xsens_status
		self.sta_sw_msg.filter_valid = "0"
		self.sta_sw_msg.gnss_fix = "0"
		self.sta_sw_msg.clock_sync = "0"
		self.sta_sw_msg.sync_in = "0"
		self.sta_sw_msg.sync_out = "0"
		self.sta_sw_msg.filter_mode = "000"
		self.sta_sw_msg.rtk_status = "00"

		# Create Publishers
		self.ori_oe_pub = self.create_publisher(OriOE, 'mti/orientation_Euler', 10)
		self.pos_pl_pub = self.create_publisher(PosPL, 'mti/position_lonLat', 10)
		self.pos_pa_pub = self.create_publisher(PosPA, 'mti/position_altEll', 10)
		self.acc_aa_pub = self.create_publisher(AccAA, 'mti/acceleration', 10)
		self.acc_af_pub = self.create_publisher(AccAF, 'mti/free_acceleration', 10)
		self.ang_wr_pub = self.create_publisher(AngWR, 'mti/rate_of_turn', 10)
		self.sta_sw_pub = self.create_publisher(StaSW, 'mti/status', 10)
		
		# Create parameters subscriber
		self.xsens_config_sub = self.create_subscription(ConfigXsens,
			'config/xsens',
			self.setConfig,
			10)
		self.xsens_config_sub
		
		# Create service client
		self.RTCMcli = self.create_client(RTCMdata, 'RTCM_data')
		while not self.RTCMcli.wait_for_service(timeout_sec=1.0):
			self.get_logger().info('service not available, waiting again...')
		self.RTCMreq = RTCMdata.Request()
		
		# Publish status "Inactive"
		self.sta_sw_pub.publish(self.sta_sw_msg)
		
	
	def setConfig(self, msg):
		
		if self.portName != msg.port_name or self.baudrate != msg.baudrate:
			self.portName = msg.port_name 
			self.baudrate = msg.baudrate
			self.publishStatus("Connecting")
			self.connect()
		if self.outputConfig != msg.output_config:
			self.outputConfig = msg.output_config
			self.baudrate = msg.baudrate
			self.publishStatus("Configuring")
			self.configOutput()
		if self.syncConfig != msg.sync_config:
			self.syncConfig = msg.sync_config
			self.baudrate = msg.baudrate	
			self.publishStatus("Configuring")
			self.configSync()
		
		self.rtcmRefreshDist = msg.rtcm_refresh_dist
		self.publishStatus("Active")
		self.get_logger().info('Xsens configuration updated. Ready to Record.')			
	
		
	def connect(self):
		# autoconnect
		if self.portName is None:
			self.get_logger().info("xsensClient - autoConnect")
			devs = find_devices()
			if devs:
				  self.portName, self.baudrate = devs[0]
				  self.get_logger().info(f"Detected MT device on port {self.portName}\
				        @ {self.baudrate} bps")
			else:
				  self.get_logger().fatal("Fatal: could not find proper MT device.")
				  self.get_logger().fatal("Could not find proper MT device.")
				  return
			if not self.baudrate:
				  self.baudrate = find_baudrate(self.portName)
			if not self.baudrate:
				  self.get_logger().fatal("Fatal: could not find proper baudrate.")
				  self.get_logger().fatal("Could not find proper baudrate.")
				  return
		# normal connect
		else:
			self.get_logger().info("xsensClient - connect")
			timeout = 0.01
			self.device = MTDevice(self.portName, self.baudrate, timeout, True, False)
			
				
	def configOutput(self):
		self.get_logger().info("xsensClient - output config")
		output_config = get_output_config(self.outputConfig)
		self.device.SetOutputConfiguration(output_config)


	def configSync(self):
		self.get_logger().info("xsensClient - syncSetting")
		lst = self.syncConfig

		# clear list of sync settings (msg with polarity at 0)
		settings0 = SyncSetting(0, 0, 0, 0, 0, 0, 0, 0)
		self.device.SetSyncSettings([settings0])
		
		# Send new sync settings
		settings = [
		    SyncSetting(
		        SyncFunction.ClockBiasEstimation, 10, 1, 0, 0, 0, 0, 1000),
		    SyncSetting(
		        SyncFunction.OnePpsTimePulse, 10, 1, 0, 0, 0, 500, 0)
		]	
		settings += [SyncSetting(lst[0], lst[1],lst[2],lst[3],lst[5],lst[5],lst[6],lst[7])]
		self.device.SetSyncSettings(settings)
	
	def publishStatus(self, status):
		self.xsens_status = status
		self.sta_sw_msg.xsens_status = self.xsens_status
		self.sta_sw_pub.publish(self.sta_sw_msg)


	def getOneMeasure(self):
		data = None
		try:
		    if self.device:
		        self.device.ReqData() # !!! Ajouté par KNM
		        data = self.device.read_measurement()
		except Exception as e:
			self.get_logger().error(f"{e}")
			return
		
		if data is None:
			return
		
		# Get timestamp information
		Timestamp = []
		Timestamp.append(data.get('Timestamp')['Hour'])
		Timestamp.append(data.get('Timestamp')['Minute'])
		Timestamp.append(data.get('Timestamp')['Second'])
		Timestamp.append(data.get('Timestamp')['ns'])
		
		# Publication - Orientation Euler's angles	
		if 'oe' in self.outputConfig and 'Orientation Data' in data:
			ori_oe_msg = OriOE()
			ori_oe_data = data.get('Orientation Data')
			ori_oe_msg.stamp = Timestamp
			ori_oe_msg.roll = ori_oe_data['Roll']
			ori_oe_msg.pitch = ori_oe_data['Pitch']
			ori_oe_msg.yaw = ori_oe_data['Yaw']
			self.ori_oe_pub.publish(ori_oe_msg)		
		
		# Publication - Postion longitude/latitude
		if 'pl' in self.outputConfig and 'Position' in data:
			pos_pl_msg = PosPL()
			pos_pl_data = data.get('Position')
			pos_pl_msg.stamp = Timestamp
			pos_pl_msg.latitude = pos_pl_data['lat']
			pos_pl_msg.longitude = pos_pl_data['lon']
			self.pos_pl_pub.publish(pos_pl_msg)
			
			# Compute distance for RTCM position update
			latlon = (pos_pl_data['lat'], pos_pl_data['lon'])
			d = haversine(self.lastPos3D[0:2], latlon, unit=Unit.METERS)
			# Check for RTCM update
			if d > self.rtcmRefreshDist:
				self.get_logger().info('Send new position to ntrip client')
				# Build and send service request
				self.lastPos3D = latlon + (data.get('Position')['altEllipsoid'],)
				self.RTCMreq.latitude = self.lastPos3D[0]
				self.RTCMreq.longitude = self.lastPos3D[1]
				self.RTCMreq.alti_ell = self.lastPos3D[2]
				self.future = self.RTCMcli.call_async(self.RTCMreq)		
		
		# Publication - Ellipsoidal height	
		if 'pa' in self.outputConfig and 'Position' in data:
			pos_pa_msg = PosPA()
			pos_pa_data = data.get('Position')
			pos_pa_msg.stamp = Timestamp
			pos_pa_msg.alt_ell = pos_pa_data['altEllipsoid']
			self.pos_pa_pub.publish(pos_pa_msg)
	
		# Publication - Acceleration	
		if 'aa' in self.outputConfig and 'Acceleration' in data:
			acc_aa_msg = AccAA()
			acc_aa_data = data.get('Acceleration')
			acc_aa_msg.stamp = Timestamp
			acc_aa_msg.accx = acc_aa_data['accX']
			acc_aa_msg.accy = acc_aa_data['accY']
			acc_aa_msg.accz = acc_aa_data['accZ']
			self.acc_aa_pub.publish(acc_aa_msg)
		
		# Publication - Free Acceleration	
		if 'af' in self.outputConfig and 'Acceleration' in data:
			acc_af_msg = AccAF()
			acc_af_data = data.get('Acceleration')
			acc_af_msg.stamp = Timestamp
			acc_af_msg.accx = acc_af_data['freeAccX']
			acc_af_msg.accy = acc_af_data['freeAccY']
			acc_af_msg.accz = acc_af_data['freeAccZ']
			self.acc_af_pub.publish(acc_af_msg)
		
		# Publication - Rate of turn
		if 'wr' in self.outputConfig and 'Angular Velocity' in data:
			ang_wr_msg = AngWR()
			ang_wr_data = data.get('Angular Velocity')
			ang_wr_msg.stamp = Timestamp
			ang_wr_msg.gyrx = ang_wr_data['gyrX']
			ang_wr_msg.gyry = ang_wr_data['gyrY']
			ang_wr_msg.gyrz = ang_wr_data['gyrZ']
			self.ang_wr_pub.publish(ang_wr_msg)
		
		# Publication - Xsens status
		if 'Status' in data:
			self.sta_sw_msg.xsens_status = self.xsens_status
			self.sta_sw_msg = self.readStatus(data['Status']['StatusWord'], self.sta_sw_msg)
			self.sta_sw_pub.publish(self.sta_sw_msg)
	
	def readStatus(self, status, msg):
		# https://www.xsens.com/hubfs/Downloads/Manuals/MT_Low-Level_Documentation.pdf
		# page 53
		decode = f"{status:032b}"[::-1]
		msg.filter_valid = decode[1]
		msg.gnss_fix = decode[2]
		msg.clock_sync = decode[6]
		msg.sync_in = decode[21]
		msg.sync_out = decode[22]

		# 23:25Filter Mode
		# Indicates Filter Mode, currently only available for GNSS/INS devices:
		# 000: Without GNSS (filter profile is in VRU mode)
		# 001: Coastingmode (GNSS has been lost <60 sec ago)
		# 011: With GNSS (default mode)
		msg.filter_mode = decode[23:26][::-1]

		# 27:28 RtkStatus
		# Indicates the availability and status of RTK:
		# 00: No RTK
		# 01: RTK floating
		# 10: RTK fixed
		msg.rtk_status = decode[27:29][::-1]
		# {SyncOut=}, {SyncIn=},
		return msg		
			

def main(args=None):

	rclpy.init(args=args)
	driver = XSensDriver()
	
	while True:
		
		# Waiting for connection and configuration data
		while driver.xsens_status == "Inactive":
			rclpy.spin_once(driver, timeout_sec=5)
			
		while driver.xsens_status == "Active":
			data = driver.device.read_measurement()
			rclpy.spin_once(driver, timeout_sec=0)
			if data:
				driver.getOneMeasure()
				#print(data)
			


	driver.destroy_node()
	rclpy.shutdown()
    
    


if __name__ == '__main__':
    main()
