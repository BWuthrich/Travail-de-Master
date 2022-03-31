#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from xsens_msgs.msg import ConfigXsens, ConfigNtrip

class MasterConfig(Node):
	RTCMv3_PREAMBLE = bytes.fromhex("D300")
	
	def __init__(self):
		super().__init__('MasterConfig')
		
		# Xsens default parameters
		self.configuration = 'ip10,iu10,oe10be,pl10ae,pa10ae,sw10'
		self.baudrate = 115200
		self.port_name = '/dev/ttyS0'
		self.rtcm_refresh_dist = 3		
		
		# Ntrip default parameters
		self.host = '193.134.218.96'
		self.port = 5001
		self.mountpoint = 'M_04'
		self.username = 'Ecole01'
		self.password = '365heig'
		self.rtcm_timer = 1
		
		# Create publishers
		self.xsens_config_pub = self.create_publisher(ConfigXsens, 'config/xsens', 10)
		self.ntrip_config_pub = self.create_publisher(ConfigNtrip, 'config/ntripclient', 10)
		
	def updateXsens(self):
		xsens_config_msg = ConfigXsens()
		xsens_config_msg.configuration = self.configuration
		xsens_config_msg.baudrate = self.baudrate
		xsens_config_msg.port_name = self.port_name
		xsens_config_msg.rtcm_refresh_dist = self.rtcm_refresh_dist
		self.xsens_config_pub.publish(xsens_config_msg)
			
	def updateNtrip(self):
		ntrip_config_msg = ConfigNtrip()
		ntrip_config_msg.host = self.host
		ntrip_config_msg.port = self.port
		ntrip_config_msg.mountpoint = self.mountpoint
		ntrip_config_msg.username = self.username
		ntrip_config_msg.password = self.password
		self.ntrip_config_pub.publish(ntrip_config_msg)



def main(args=None):

	rclpy.init(args=args)
	mc = MasterConfig()
	
	# A terme pas d'update en continu juste quand une nouvelle config est reçue
	while True:
		mc.updateXsens()
		mc.updateNtrip()
	
	mc.destroy_node()
	rclpy.shutdown()
    
if __name__ == '__main__':
	main()
