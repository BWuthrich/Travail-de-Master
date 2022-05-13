#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import RPi.GPIO as GPIO
import time
from haversine import haversine, Unit

from .utils.mtdevice import find_devices, find_baudrate, MTDevice, get_output_config
from .utils.mtdef import SyncSetting, SyncFunction, SyncLine

from xsens_msgs.msg import AccAA, AccAF, AngWR, OriOE, PosPL, PosPA, StaSW, GnsNP, TrgSP, ConfigXsens
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
		# GPIO trigger connection
		self.gpioSwitch = 24
		self.gpioTrig = 23
		self.dtPulse = 0.001
		self.dtFreq = None			
		GPIO.setmode(GPIO.BCM)
		GPIO.setup(self.gpioSwitch, GPIO.OUT)
		GPIO.setup(self.gpioTrig, GPIO.OUT)
		self.trig_counter = 0

		# Create Publishers
		self.ori_oe_pub = self.create_publisher(OriOE, 'mti/orientation_Euler', 10)
		self.pos_pl_pub = self.create_publisher(PosPL, 'mti/position_lonLat', 10)
		self.pos_pa_pub = self.create_publisher(PosPA, 'mti/position_altEll', 10)
		self.gns_np_pub = self.create_publisher(GnsNP, 'mti/gnss_pvt_data', 10)
		self.acc_aa_pub = self.create_publisher(AccAA, 'mti/acceleration', 10)
		self.acc_af_pub = self.create_publisher(AccAF, 'mti/free_acceleration', 10)
		self.ang_wr_pub = self.create_publisher(AngWR, 'mti/rate_of_turn', 10)
		self.sta_sw_pub = self.create_publisher(StaSW, 'mti/status', 10)
		self.trig_stamp_pub = self.create_publisher(TrgSP, 'mti/trigger_stamp', 10)
		
		# Create messages	
		self.ori_oe_msg = OriOE()
		self.pos_pl_msg = PosPL()
		self.pos_pa_msg = PosPA()
		self.gns_np_msg = GnsNP()
		self.acc_aa_msg = AccAA()
		self.acc_af_msg = AccAF()
		self.ang_wr_msg = AngWR()
		self.trg_sp_msg = TrgSP()
		
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
			#self.device.ChangeBaudrate(460800)
		if self.outputConfig != msg.output_config:
			self.outputConfig = msg.output_config
			self.baudrate = msg.baudrate
			self.publishStatus("Configuring")
			self.configOutput()
		if self.syncConfig != msg.sync_config:
			self.syncConfig = msg.sync_config
			self.baudrate = msg.baudrate
			self.dtFreq = msg.dt_freq
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
			self.device.ReqData() # !!! Ajouté par KNM
			
				
	def configOutput(self):
		self.get_logger().info("xsensClient - output config")
		output_config = get_output_config(self.outputConfig)
		print(self.outputConfig)
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
		settings += [SyncSetting(lst[0],lst[1],lst[2],lst[3],lst[4],lst[5],lst[6],lst[7])]
		self.device.SetSyncSettings(settings)
		
		# If sync on input line - Trigger from RPI
		if lst[1] != 7:
			GPIO.output(self.gpioSwitch, GPIO.HIGH)
			# Start Trigger
			self.timer = self.create_timer(self.dtFreq, self.RPItrig)
		
		# Else sync on output line - Trigger from Xsens
		else:
			self.timer = []
			GPIO.output(self.gpioSwitch, GPIO.LOW)
	
	
	def RPItrig(self):
		GPIO.output(self.gpioTrig, GPIO.HIGH)
		print('TOP-RPI')
		time.sleep(self.dtPulse)
		GPIO.output(self.gpioTrig, GPIO.LOW)		
		
	
	def publishStatus(self, status):
		self.xsens_status = status
		self.sta_sw_msg.xsens_status = self.xsens_status
		self.sta_sw_pub.publish(self.sta_sw_msg)


	def getOneMeasure(self):
		data = None
		try:
			data = self.device.read_measurement()
			#print(data)
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
			self.ori_oe_msg.stamp = Timestamp
			self.ori_oe_msg.roll = data['Orientation Data']['Roll']
			self.ori_oe_msg.pitch = data['Orientation Data']['Pitch']
			self.ori_oe_msg.yaw = data['Orientation Data']['Yaw']
			self.ori_oe_pub.publish(self.ori_oe_msg)				
		
		# Publication - Ellipsoidal height	
		if 'pa' in self.outputConfig and 'Position' in data:
			self.pos_pa_msg.stamp = Timestamp
			self.pos_pa_msg.alt_ell = data['Position']['altEllipsoid']
			self.pos_pa_pub.publish(self.pos_pa_msg)
	
		# Publication - Acceleration	
		if 'aa' in self.outputConfig and 'Acceleration' in data:
			self.acc_aa_msg.stamp = Timestamp
			self.acc_aa_msg.accx = data['Acceleration']['accX']
			self.acc_aa_msg.accy = data['Acceleration']['accY']
			self.acc_aa_msg.accz = data['Acceleration']['accZ']
			self.acc_aa_pub.publish(self.acc_aa_msg)
		
		# Publication - Free Acceleration	
		if 'af' in self.outputConfig and 'Acceleration' in data:
			self.acc_af_msg.stamp = Timestamp
			self.acc_af_msg.accx = data['Acceleration']['freeAccX']
			self.acc_af_msg.accy = data['Acceleration']['freeAccY']
			self.acc_af_msg.accz = data['Acceleration']['freeAccZ']
			self.acc_af_pub.publish(self.acc_af_msg)
		
		# Publication - Rate of turn
		if 'wr' in self.outputConfig and 'Angular Velocity' in data:
			self.ang_wr_msg.stamp = Timestamp
			self.ang_wr_msg.gyrx = data['Angular Velocity']['gyrX']
			self.ang_wr_msg.gyry = data['Angular Velocity']['gyrY']
			self.ang_wr_msg.gyrz = data['Angular Velocity']['gyrZ']
			self.ang_wr_pub.publish(self.ang_wr_msg)
				
		# Publication - GNSS PVT data	
		if 'np' in self.outputConfig and 'GNSS' in data:
			self.gns_np_msg = self.readGNSS(data, self.gns_np_msg)
			self.gns_np_msg.stamp = Timestamp
			self.gns_np_pub.publish(self.gns_np_msg)
		
		# Publication - Xsens status
		if 'Status' in data:
			self.sta_sw_msg.xsens_status = self.xsens_status
			self.sta_sw_msg = self.readStatus(data['Status']['StatusWord'], self.sta_sw_msg)
			self.sta_sw_pub.publish(self.sta_sw_msg)		
			# Publication - Trigger timestamp
			if self.sta_sw_msg.sync_in == '1' or self.sta_sw_msg.sync_out == '1':
				self.trig_counter += 1
				self.trg_sp_msg.stamp = Timestamp
				self.trg_sp_msg.trig_counter = self.trig_counter
				self.trig_stamp_pub.publish(self.trg_sp_msg)
				
		# Publication - Postion longitude/latitude
		if 'pl' in self.outputConfig and 'Position' in data:
			self.pos_pl_msg.stamp = Timestamp
			self.pos_pl_msg.latitude = data['Position']['lat']
			self.pos_pl_msg.longitude = data['Position']['lon']
			self.pos_pl_pub.publish(self.pos_pl_msg)		
			# Compute distance for RTCM position update
			latlon = (data['Position']['lat'], data['Position']['lon'])
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
	
	
	def readGNSS(self, data, msg):
		msg.fixtype = data['GNSS']['fixtype']
		msg.lon = data['GNSS']['lon']	
		msg.lat = data['GNSS']['lat']	
		msg.height = data['GNSS']['height']	
		msg.h_msl = data['GNSS']['hMSL']	
		msg.h_acc = data['GNSS']['hAcc']
		msg.v_acc = data['GNSS']['vAcc']
		msg.vel_n = data['GNSS']['velN']
		msg.vel_e = data['GNSS']['velE']
		msg.vel_d = data['GNSS']['velD']
		msg.s_acc = data['GNSS']['sAcc']
		return msg	
	
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
		return msg		
			

def main(args=None):

	rclpy.init(args=args)
	driver = XSensDriver()
	
	while True:
		
		# Waiting for connection and configuration data
		while driver.xsens_status == "Inactive":
			rclpy.spin_once(driver, timeout_sec=5)
			
		while driver.xsens_status == "Active":
			rclpy.spin_once(driver, timeout_sec=0)
			driver.getOneMeasure()
			
	driver.destroy_node()
	rclpy.shutdown()
    
    


if __name__ == '__main__':
    main()
