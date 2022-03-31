#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

import time

from xsens_msgs.msg import ConfigXsens, ConfigNtrip

class MasterConfig(Node):

	
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
		self.rtcm_timer = 5.0		# RTCM refrsh rate [s]
		
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
		ntrip_config_msg.rtcm_timer = self.rtcm_timer
		self.ntrip_config_pub.publish(ntrip_config_msg)



def main(args=None):

	rclpy.init(args=args)
	need_update = True
	mc = MasterConfig()
	
	# A terme pas d'update en continu juste quand une nouvelle config est reçue
	# Envoi la nouvelle config pendent 5 secondes
	while True:
		if need_update:
			need_update = False
			t_end = time.time() + 3
			while time.time() < t_end:
				mc.updateXsens()
				mc.updateNtrip()
	
	mc.destroy_node()
	rclpy.shutdown()
    
if __name__ == '__main__':
	main()
