#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import select
import math
import pdb
import numpy
from .utils.mtdevice import find_devices, find_baudrate, MTDevice
from std_msgs.msg import Header, Float32, Float64
from sensor_msgs.msg import Imu
from geometry_msgs.msg import TwistStamped, Vector3Stamped, QuaternionStamped
from gps_msgs.msg import GPSFix, GPSStatus
from diagnostic_msgs.msg import DiagnosticArray, DiagnosticStatus, KeyValue
from xsens_msgs.msg import SensorSample, BaroSample, GnssSample
from xsens_msgs.msg import PositionEstimate, VelocityEstimate, OrientationEstimate
# transform Euler angles or matrix into quaternions
from math import pi, radians
from tf_transformations import quaternion_from_matrix, quaternion_from_euler, identity_matrix


class XSensDriver(Node):

	ENU = numpy.identity(3)
	NED = numpy.array([[0, 1, 0], [ 1, 0, 0], [0, 0, -1]])
	NWU = numpy.array([[0, 1, 0], [-1, 0, 0], [0, 0,  1]])

	def __init__(self):
		super().__init__('XSensDriver')
		self.declare_parameters(
		    namespace='',
		    parameters=[
		        ('device', 'auto'),
		        ('baudrate', 0),
		        ('odr', 40),
		        ('output_mode', 2),
		        ('configure_on_startup', False),
		        ('xkf_scenario', 43),
		        ('use_rostime', False),
		        ('frame_id', 'mti/data'),
		        ('frame_local', 'ENU'),
		        ('frame_local_imu', 'ENU')
		    ])

		device = self.get_parameter('device').value
		baudrate = self.get_parameter('baudrate').value
		configure_on_startup = self.get_parameter('configure_on_startup').value
		odr = self.get_parameter('odr').value
		output_mode = self.get_parameter('output_mode').value
		xkf_scenario = self.get_parameter('xkf_scenario').value
		self.use_rostime = self.get_parameter('use_rostime').value
		self.frame_id = self.get_parameter('frame_id').value
		frame_local     = self.get_parameter('frame_local').value
		frame_local_imu = self.get_parameter('frame_local_imu').value
		
		if device=='auto':
			devs = find_devices()
			if devs:
				device, baudrate = devs[0]
				self.get_logger().info("Detected MT device on port %s @ %d bps"%(device,
						baudrate))
			else:
				self.get_logger().err("Fatal: could not find proper MT device.")
				#rospy.signal_shutdown("Could not find proper MT device.")
				return
		if not baudrate:
			baudrate = find_baudrate(device)
		if not baudrate:
			self.get_logger().error("Fatal: could not find proper baudrate.")
			#rospy.signal_shutdown("Could not find proper baudrate.")
			return

		self.get_logger().info("MT node interface: %s at %d bd."%(device, baudrate))
		self.mt = MTDevice(device, baudrate)

		if configure_on_startup:
			self.get_logger().info('Setting ODR (%d) and output mode (%d)' % (odr, output_mode))
			if odr not in [1, 2, 5, 10, 20, 40, 50, 80, 100, 200, 400]:
				raise Exception('Invalid ODR configuraton requested')
			if output_mode not in [1, 2, 3]:
				raise Exception('Invalid output mode requested')
			self.mt.configureMti(odr, output_mode)
			self.mt.ChangeBaudrate(baudrate)
			self.mt.SetCurrentScenario(xkf_scenario)
			self.mt.GoToMeasurement()
		else:
			self.get_logger().info('Using saved odr and output configuration')



		if   frame_local == 'ENU':
			R = XSensDriver.ENU
		elif frame_local == 'NED':
			R = XSensDriver.NED
		elif frame_local == 'NWU':
			R = XSensDriver.NWU

		if   frame_local_imu == 'ENU':
			R_IMU = XSensDriver.ENU
		elif frame_local_imu == 'NED':
			R_IMU = XSensDriver.NED
		elif frame_local_imu == 'NWU':
			R_IMU = XSensDriver.NWU

		self.R = R.dot(R_IMU.transpose())

		self.diag_pub = self.create_publisher(DiagnosticArray, '/diagnostics', 10)
		self.diag_msg = DiagnosticArray()
		self.stest_stat = DiagnosticStatus(name='mtnode: Self Test', level=DiagnosticStatus.OK,
				message='No status information')
		self.xkf_stat = DiagnosticStatus(name='mtnode: XKF Valid', level=DiagnosticStatus.OK,
				message='No status information')
		self.gps_stat = DiagnosticStatus(name='mtnode: GPS Fix', level=DiagnosticStatus.OK,
				message='No status information')
		self.diag_msg.status = [self.stest_stat, self.xkf_stat, self.gps_stat]

		self.imu_pub = self.create_publisher(Imu, 'mti/sensor/imu', 10) #IMU message
		self.ss_pub = self.create_publisher(SensorSample, 'mti/sensor/sample', 10) # SensorSample
		self.mag_pub = self.create_publisher(Vector3Stamped, 'mti/sensor/magnetic', 10) # magnetic
		self.baro_pub = self.create_publisher(BaroSample, 'mti/sensor/pressure', 10) # baro
		self.gnssPvt_pub = self.create_publisher(GnssSample, 'mti/sensor/gnssPvt', 10) # GNSS PVT
		#self.gnssSatinfo_pub = self.create_publisher(GPSStatus, 'mti/sensor/gnssStatus', 10) # GNSS SATINFO
		self.ori_pub = self.create_publisher(OrientationEstimate, 'mti/filter/orientation', 10) # XKF/XEE orientation
		self.vel_pub = self.create_publisher(VelocityEstimate, 'mti/filter/velocity', 10) # XKF/XEE velocity
		self.pos_pub = self.create_publisher(PositionEstimate, 'mti/filter/position', 10) # XKF/XEE position
		self.temp_pub = self.create_publisher(Float32, 'temperature', 10)	# decide type
			
		timer_period = 0.5  # seconds
		self.timer = self.create_timer(timer_period, self.timer_callback)
			

	def timer_callback(self):
		def baroPressureToHeight(value):
			c1 = 44330.0
			c2 = 9.869232667160128300024673081668e-6
			c3 = 0.1901975534856
			intermediate = 1-math.pow(c2*value, c3)
			height = c1*intermediate
			return height
			
		# get data
		data = self.mt.read_measurement()
		print(data)
		# common header
		h = Header()
		h.stamp = self.get_clock().now().to_msg()
		h.frame_id = self.frame_id

		# get data (None if not present)
		#temp = data.get('Temp')	# float
		orient_data = data.get('Orientation Data')
		velocity_data = data.get('Velocity')
		position_data = data.get('Latlon')
		altitude_data = data.get('Altitude')
		acc_data = data.get('Acceleration')
		gyr_data = data.get('Angular Velocity')
		mag_data = data.get('Magnetic')
		pressure_data = data.get('Pressure')
		time_data = data.get('Timestamp')
		gnss_data = data.get('Gnss PVT')
		status = data.get('Status')	# int

		# create messages and default values
		"Imu message supported with Modes 1 & 2"
		imu_msg = Imu()
		pub_imu = False
		"SensorSample message supported with Mode 2"
		ss_msg = SensorSample()
		pub_ss = False
		"Mag message supported with Modes 1 & 2"
		mag_msg = Vector3Stamped()
		pub_mag = False
		"Baro in meters"
		baro_msg = BaroSample()
		pub_baro = False
		"GNSS message supported only with MTi-G-7xx devices"
		"Valid only for modes 1 and 2"
		gnssPvt_msg = GnssSample()
		pub_gnssPvt = False
		#gnssSatinfo_msg = GPSStatus()
		#pub_gnssSatinfo = False		
		# All filter related outputs
		"Supported in mode 3"
		ori_msg = OrientationEstimate()
		pub_ori = False
		"Supported in mode 3 for MTi-G-7xx devices"
		vel_msg = VelocityEstimate()
		pub_vel = False
		"Supported in mode 3 for MTi-G-7xx devices"
		pos_msg = PositionEstimate()
		pub_pos = False
		
		sec = 0
		nanosec = 0
		
		if time_data:
			# first getting the sampleTimeFine
			sec = time_data['Second']
			nanosec= time_data['ns']
			#secs = 100e-6*time
			#nsecs = 1e5*time - 1e9*math.floor(secs)
		
		if acc_data:
			if 'Delta v.x' in acc_data: # found delta-v's
				pub_ss = True
				ss_msg.internal.imu.dv.x = acc_data['Delta v.x']
				ss_msg.internal.imu.dv.y = acc_data['Delta v.y']
				ss_msg.internal.imu.dv.z = acc_data['Delta v.z']			
			elif 'accX' in acc_data: # found acceleration
				pub_imu = True
				imu_msg.linear_acceleration.x = acc_data['accX']
				imu_msg.linear_acceleration.y = acc_data['accY']
				imu_msg.linear_acceleration.z = acc_data['accZ']
			else:
				raise MTException("Unsupported message in XDI_AccelerationGroup.")	
					
		if gyr_data:
			if 'Delta q0' in gyr_data: # found delta-q's
				pub_ss = True
				ss_msg.internal.imu.dq.w = gyr_data['Delta q0']
				ss_msg.internal.imu.dq.x = gyr_data['Delta q1']
				ss_msg.internal.imu.dq.y = gyr_data['Delta q2']
				ss_msg.internal.imu.dq.z = gyr_data['Delta q3']
			elif 'gyrX' in gyr_data: # found rate of turn
				pub_imu = True
				imu_msg.angular_velocity.x = gyr_data['gyrX']
				imu_msg.angular_velocity.y = gyr_data['gyrY']
				imu_msg.angular_velocity.z = gyr_data['gyrZ']
			else:
				raise MTException("Unsupported message in XDI_AngularVelocityGroup.")
		
		if mag_data:
			# magfield
			ss_msg.internal.mag.x = mag_msg.vector.x = mag_data['magX']
			ss_msg.internal.mag.y = mag_msg.vector.y = mag_data['magY']
			ss_msg.internal.mag.z = mag_msg.vector.z = mag_data['magZ']
			pub_mag = True
			
		if pressure_data:
			pub_baro = True
			height = baroPressureToHeight(pressure_data['Pressure'])
			baro_msg.height = ss_msg.internal.baro.height = height
		
		if gnss_data:
			pub_gnssPvt = True
			gnssPvt_msg.itow = gnss_data['iTOW']
			gnssPvt_msg.fix = gnss_data['fix']			
			gnssPvt_msg.latitude = gnss_data['lat']
			gnssPvt_msg.longitude = gnss_data['lon']
			gnssPvt_msg.hEll = gnss_data['hEll']
			gnssPvt_msg.hMsl = gnss_data['hMsl']
			gnssPvt_msg.vel.x = gnss_data['velE']
			gnssPvt_msg.vel.y = gnss_data['velN']
			gnssPvt_msg.vel.z = -gnss_data['velD']
			gnssPvt_msg.hAcc = gnss_data['horzAcc']
			gnssPvt_msg.vAcc = gnss_data['vertAcc']
			gnssPvt_msg.sAcc = gnss_data['speedAcc']
			gnssPvt_msg.pDop = gnss_data['PDOP']
			gnssPvt_msg.hDop = gnss_data['HDOP']
			gnssPvt_msg.vDop = gnss_data['VDOP']
			gnssPvt_msg.numSat = gnss_data['nSat']
			gnssPvt_msg.heading = gnss_data['heading']
			gnssPvt_msg.headingAcc = gnss_data['headingAcc']

		if orient_data:
			if 'Q0' in orient_data:
				pub_imu = True
				imu_msg.orientation.w = orient_data['Q0']
				imu_msg.orientation.x = orient_data['Q1']
				imu_msg.orientation.y = orient_data['Q2']
				imu_msg.orientation.z = orient_data['Q3']
			elif 'Roll' in orient_data:
				pub_ori = True
				ori_msg.roll = orient_data['Roll']
				ori_msg.pitch = orient_data['Pitch']
				ori_msg.yaw = orient_data['Yaw']				
			else:
				raise MTException('Unsupported message in XDI_OrientationGroup')

		if velocity_data:
			pub_vel = True
			vel_msg.velE = velocity_data['velX']
			vel_msg.velN = velocity_data['velY']
			vel_msg.velU = velocity_data['velZ']
										
		if position_data:
			pub_pos = True
			pos_msg.latitude = position_data['lat']
			pos_msg.longitude = position_data['lon']
			
		if altitude_data:
			pub_pos = True	
			tempData = altitude_data['ellipsoid']
			pos_msg.hEll = tempData[0]
			
		#if status is not None:
		#	if status & 0b0001:
		#		self.stest_stat.level = DiagnosticStatus.OK
		#		self.stest_stat.message = "Ok"
		#	else:
		#		self.stest_stat.level = DiagnosticStatus.ERROR
		# 		self.stest_stat.message = "Failed"
		#	if status & 0b0010:
		#		self.xkf_stat.level = DiagnosticStatus.OK
		#		self.xkf_stat.message = "Valid"
		#	else:
		#		self.xkf_stat.level = DiagnosticStatus.WARN
		#		self.xkf_stat.message = "Invalid"
		#	if status & 0b0100:
		#		self.gps_stat.level = DiagnosticStatus.OK
		#		self.gps_stat.message = "Ok"
		#	else:
		#		self.gps_stat.level = DiagnosticStatus.WARN
		#		self.gps_stat.message = "No fix"
		#	self.diag_msg.header = h
		#	self.diag_pub.publish(self.diag_msg)

		
		# publish available information
		if pub_imu:
			imu_msg.header = h
			if not self.use_rostime:
				#all time assignments (overwriting ROS time)
				imu_msg.header.stamp.sec = sec
				imu_msg.header.stamp.nanosec = nanosec	
			self.imu_pub.publish(imu_msg)
		#if pub_gps:
		#	xgps_msg.header = gps_msg.header = h
		#	self.gps_pub.publish(gps_msg)
		#	self.xgps_pub.publish(xgps_msg)
		if pub_mag:
			mag_msg.header = h
			self.mag_pub.publish(mag_msg)
		#if pub_temp:
		#	self.temp_pub.publish(temp_msg)
		if pub_ss:
			ss_msg.header = h
			if not self.use_rostime:
				#all time assignments (overwriting ROS time)
				ss_msg.header.stamp.sec = sec
				ss_msg.header.stamp.nanosec = nanosec	
			self.ss_pub.publish(ss_msg)
		if pub_baro:
			baro_msg.header = h
			if not self.use_rostime:
				#all time assignments (overwriting ROS time)
				baro_msg.header.stamp.sec= sec
				baro_msg.header.stamp.nanosec = nanosec	
			self.baro_pub.publish(baro_msg)
		if pub_gnssPvt:
			gnssPvt_msg.header = h
			if not self.use_rostime:
				#all time assignments (overwriting ROS time)
				baro_msg.header.stamp.sec = sec
				baro_msg.header.stamp.nanosec = nanosec	
			self.gnssPvt_pub.publish(gnssPvt_msg)
		if pub_ori:
			ori_msg.header = h
			if not self.use_rostime:
				#all time assignments (overwriting ROS time)
				ori_msg.header.stamp.sec = sec
				ori_msg.header.stamp.nanosec = nanosec	
			self.ori_pub.publish(ori_msg)
		if pub_vel:
			vel_msg.header = h
			if not self.use_rostime:
				#all time assignments (overwriting ROS time)
				vel_msg.header.stamp.sec = sec
				vel_msg.header.stamp.nanosec = nanosec	
			self.vel_pub.publish(vel_msg)
		if pub_pos:
			pos_msg.header = h
			if not self.use_rostime:
				#all time assignments (overwriting ROS time)
				pos_msg.header.stamp.sec = sec
				pos_msg.header.stamp.nanosec = nanosec	
			self.pos_pub.publish(pos_msg)


def main(args=None):
    '''Create a ROS node and instantiate the class.'''
    rclpy.init(args=args)
    driver = XSensDriver()
    rclpy.spin(driver)
    
    minimal_publisher.destroy_node()
    rclpy.shutdown()
    
    


if __name__ == '__main__':
    main()
