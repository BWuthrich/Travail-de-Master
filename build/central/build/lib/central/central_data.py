#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import time
import numpy as np
import matplotlib.pyplot as plt
from xsens_msgs.msg import OriOE, PosPL, PosPA, StaSW, AccAA

plt.ion()

class CollectData(Node):
	
	def __init__(self):
		super().__init__('CollectData')

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
		
		# Acceleration
		self.acc_aa_sub = self.create_subscription(AccAA,
			'mti/acceleration',
			self.getAccAA,
			10)
		self.acc_aa_sub
	
	
		self.init_filter = True
		self.newPosPL = False
		self.newPosPA = False
		
	def getPosPL(self, msg):
		self.PosPL = msg
		self.newPosPL = True	
		
		if self.init_filter:
			self.init_kalman_filter_1 (msg)
	
	def getOriOE(self, msg):
		pass
	
	def getPosPA(self, msg):
		self.PosPA = msg
		self.newPosPA = True
		
		if self.init_filter:
			self.init_kalman_filter_1 (msg)
			
	def getStaSW(self, msg):
		pass		

	def getAccAA(self, msg):
		pass
		
	
	# Kalman filter on GNSS position only
	def kalman_filter_1 (self):
		dt = time.time() - self.t0
		self.t0 = time.time()
		
		# State transtion matrix
		F = np.array([[1.0, 0.0, 0.0, dt, 0.0, 0.0],
									[0.0, 1.0, 0.0, 0.0, dt, 0.0],
									[0.0, 0.0, 1.0, 0.0, 0.0, dt],
									[0.0, 0.0, 0.0, 1.0, 0.0, 0.0],
									[0.0, 0.0, 0.0, 0.0, 1.0, 0.0],
									[0.0, 0.0, 0.0, 0.0, 0.0, 1.0]])
		
		# Control matrix
		G = np.array([[0.5*dt**2, 0.0, 0.0],
									[0.0, 0.5*dt**2, 0.0],
									[0.0, 0.0, 0.5*dt**2],
									[dt, 0.0, 0.0],
									[0.0, dt, 0.0],
									[0.0, 0.0, dt]])
		
		# Process noise uncertainty
		Kww = np.array([[self.sigma_ax**2, 0.0, 0.0],
                		[0.0, self.sigma_ay, 0.0],
                		[0.0, 0.0, self.sigma_az],])
		Q = G@Kww@G.T

		# Observation	
		l = np.array([[0.0],
                  [0.0], 
                  [0.0]])
                  
		Kll = np.array([[9999.0**2, 0.0, 0.0],
                  	[0.0, 9999.0**2, 0.0],
                  	[0.0, 0.0, 9999.0**2]])
                  			
		if self.newPosPL:
			l[0] = self.PosPL.longitude
			l[1] = self.PosPL.latitude
			Kll[0][0] = self.sigma_x_GNSS**2
			Kll[1][1] = self.sigma_y_GNSS**2
			self.newPosPL = False
			self.lines_obs.set_xdata(np.append(self.lines_obs.get_xdata(), self.PosPL.longitude))
			self.lines_obs.set_ydata(np.append(self.lines_obs.get_ydata(), self.PosPL.latitude))
		
		if self.newPosPA:
			l[2] = self.PosPA.alt_ell
			Kll[2][2] = self.sigma_z_GNSS**2
			self.newPosPA = False
		
		# Observation matrix
		A = np.array([[1.0, 0.0, 0.0, 0.0, 0.0, 0.0],
									[0.0, 1.0, 0.0, 0.0, 0.0, 0.0],
                  [0.0, 0.0, 1.0, 0.0, 0.0, 0.0]])
		
		# Prediction
		x_pred = F@self.x
		Kxx_pred = F@self.Kxx@F.T + Q

		# Update
		K = Kxx_pred@A.T@np.linalg.inv(A@Kxx_pred@A.T+Kll)
		self.x = x_pred + K@(l-A@x_pred)
		self.Kxx = Kxx_pred - K@A@Kxx_pred

		#Update data
		self.lines.set_xdata(np.append(self.lines.get_xdata(), self.x[0]))
		self.lines.set_ydata(np.append(self.lines.get_ydata(), self.x[1]))
		self.ax.set_ylim(self.x[1]-0.00003, self.x[1]+0.00003)
		self.ax.set_xlim(self.x[0]-0.00003, self.x[0]+0.00003)

		self.figure.canvas.draw()
		self.figure.canvas.flush_events()

	
	
	# Init Kalman filter on GNSS position only
	def init_kalman_filter_1 (self, data):
		
		# Initial system state [x, y, z, vx, vy, vz]
		self.x = np.array([[0.0],[0.0],[0.0],[0.0],[0.0],[0.0]])
		
		# Initial variance covariance matrix
		self.Kxx = np.array([[9999**2, 0.0, 0.0, 0.0, 0.0, 0.0],
									 			 [0.0, 9999**2, 0.0, 0.0, 0.0, 0.0], 
									 			 [0.0, 0.0, 9999**2, 0.0, 0.0, 0.0],
									 			 [0.0, 0.0, 0.0, 9999**2, 0.0, 0.0],
									 			 [0.0, 0.0, 0.0, 0.0, 9999**2, 0.0],
									 			 [0.0, 0.0, 0.0, 0.0, 0.0, 9999**2]])
		
		# Observation noise
		self.sigma_x_GNSS = 0.05
		self.sigma_y_GNSS = 0.05
		self.sigma_z_GNSS = 0.05
		
		# Process noise
		self.sigma_ax = 0.1
		self.sigma_ay = 0.1
		self.sigma_az = 0.1
		
		# Init time
		# self.t0 = 3600*data.stamp[0] + 60*data.stamp[1] + data.stamp[2] + data.stamp[3]/1e9
		self.t0 = time.time()
		self.init_filter = False
		
		# Start filter
		filter_freq = 1/10	# Filter update frequency [s]
		self.timer = self.create_timer(filter_freq, self.kalman_filter_1)
		
		# Init figure
		self.figure, self.ax = plt.subplots()
		self.lines, = self.ax.plot([],[], '-g')
		self.lines_obs, = self.ax.plot([],[], 'ob')
		self.ax.grid()
		
	
		
		
		


def main(args=None):

	rclpy.init(args=args)
	cd = CollectData()

	rclpy.spin(cd)
	
	cd.destroy_node()
	rclpy.shutdown()
    
if __name__ == '__main__':
	main()
