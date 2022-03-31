#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import time
from xsens_msgs.msg import OriOE, PosPL, PosPA, StaSW

class CollectData(Node):
	
	def __init__(self):
		super().__init__('CollectData')
		print('AGGSAGDFDFDFDFDFD')
		# Create data subscriber
		# Orientation Euler's angles
		self.ori_oe_sub = self.create_subscription(OriOE,
			'mti/orientation_Euler',
			self.getOriOE,
			10)
		self.ori_oe_sub
		
		# Postion longitude/latitude
		self.pos_pl_sub = self.create_subscription(PosPL,
			'mti/position_lonLat',
			self.getPosPL,
			10)
		self.pos_pl_sub
		
		# Ellipsoidal height
		self.pos_pa_sub = self.create_subscription(PosPA,
			'mti/position_altEll',
			self.getPosPA,
			10)
		self.pos_pa_sub
		
		# Xsens status
		self.sta_sw_sub = self.create_subscription(StaSW,
			'mti/status',
			self.getStaSW,
			10)
		self.sta_sw_sub
		
		self.time_old1 = 0
		self.time_old2 = 0
		self.time_old3 = 0
		self.time_old4 = 0
	
	def getOriOE(self, msg):
		time_new = time.time()
		print('OriOE - freq: ' + str(1/(time_new-self.time_old1)) + 'hz')
		self.time_old1 = time_new
	
	def getPosPL(self, msg):
		time_new = time.time()
		print('PosPL - freq: ' + str(1/(time_new-self.time_old2)) + 'hz')
		self.time_old2 = time_new	
	
	def getPosPA(self, msg):
		time_new = time.time()
		print('PosPA - freq: ' + str(1/(time_new-self.time_old3)) + 'hz')
		self.time_old3 = time_new
			
	def getStaSW(self, msg):
		time_new = time.time()
		print('StaSW - freq: ' + str(1/(time_new-self.time_old4)) + 'hz')
		self.time_old4 = time_new		



def main(args=None):

	rclpy.init(args=args)
	cd = CollectData()

	rclpy.spin(cd)
	
	cd.destroy_node()
	rclpy.shutdown()
    
if __name__ == '__main__':
	main()
