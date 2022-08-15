#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import time
import numpy as np
import matplotlib.pyplot as plt
from xsens_msgs.msg import OriOE, PosPL, PosPA, StaSW, AccAA, AngWR, GnsNP

plt.ion()

class CollectData(Node):
	
	def __init__(self):
		super().__init__('CollectData')
		
		self.e = 0.08181919 # eccentricity
		self.a = 6378137.0 # equatorial radius

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
		
		# Rate of turn
		self.ang_wr_sub = self.create_subscription(AngWR,
			'mti/rate_of_turn',
			self.getAngWR,
			10)
		self.ang_wr_sub

		# GNSS PVT data
		self.gns_np_sub = self.create_subscription(GnsNP,
			'mti/gnss_pvt_data',
			self.getGnsNP,
			10)
		self.gns_np_sub	
	
		self.init_filter = True
		self.newPosPL = False
		self.newPosPA = False
		self.newGnsNP = False
		self.newOriOE = False
		self.newAccAA = False
		self.newAngWR = False
		self.count = 0
	
	def getPosPL(self, msg):
		self.newPosPL = True
		self.PosPL = msg

#		Export data to file				
#		f0 = open("PosPL.txt", "a")
#		f0.write(str([[3600*msg.stamp[0] + 60*msg.stamp[1] + msg.stamp[2] + msg.stamp[3]/1e9],[msg.latitude], [msg.longitude]])+'\n')
#		f0.close()

	
	def getOriOE(self, msg):
		self.newOriOE = True
		self.OriOE = msg

#		Export data to file				
#		fp = open("OriOE.txt", "a")
#		fp.write(str([[3600*msg.stamp[0] + 60*msg.stamp[1] + msg.stamp[2] + msg.stamp[3]/1e9],[msg.pitch], [msg.roll], [msg.yaw]])+'\n')
#		fp.close()
		
	
	def getPosPA(self, msg):
		self.newPosPA = True
		self.PosPA = msg

#		Export data to file				
#		fl = open("PosPA.txt", "a")
#		fl.write(str([[3600*msg.stamp[0] + 60*msg.stamp[1] + msg.stamp[2] + msg.stamp[3]/1e9],[msg.alt_ell]])+'\n')
#		fl.close()
		
			
	def getStaSW(self, msg):
		pass		

	def getAccAA(self, msg):
		self.newAccAA = True
		self.AccAA = msg

#		Export data to file		
#		fa = open("AccAA.txt", "a")
#		fa.write(str([[3600*msg.stamp[0] + 60*msg.stamp[1] + msg.stamp[2] + msg.stamp[3]/1e9],[msg.accx], [msg.accy], [msg.accz]])+'\n')
#		fa.close()
		
	
	def getAngWR(self, msg):
		self.newAngWR = True
		self.AngWR = msg

#		Export data to file				
#		fg = open("AngWR.txt", "a")
#		fg.write(str([[3600*msg.stamp[0] + 60*msg.stamp[1] + msg.stamp[2] + msg.stamp[3]/1e9],[msg.gyrx], [msg.gyry], [msg.gyrz]])+'\n')
#		fg.close()
	
	def getGnsNP(self, msg):
		self.GnsNP = msg
		self.newGnsNP = True

#		Export data to file				
#		fn = open("GnsNP.txt", "a")
#		fn.write(str([[3600*msg.stamp[0] + 60*msg.stamp[1] + msg.stamp[2] + msg.stamp[3]/1e9],[msg.lat], [msg.lon], [msg.height], [msg.vel_e], [msg.vel_n], [msg.vel_d]])+'\n')
#		fn.close()


# state: dictionnaire {Position, Velocity, Attitude, Acceleration, Biais gyr, Biais acc}
# Position [lat, lon, h]
# Velocity [velE, velN, velU]

	def kalman_filter_2(self, gnss, dt_KF):
    
    # Use new INS position or if no new data last estimated position
		lat = self.ObsPathParameters['State']['Position'][0,0]
		lon = self.ObsPathParameters['State']['Position'][1,0]
		alti = self.ObsPathParameters['State']['Position'][2,0]
		velE = self.ObsPathParameters['State']['Velocity'][0,0]
		velN = self.ObsPathParameters['State']['Velocity'][1,0]
		velU = self.ObsPathParameters['State']['Velocity'][2,0]
		accE = self.ObsPathParameters['State']['Acceleration'][0,0]
		accN = self.ObsPathParameters['State']['Acceleration'][1,0]
		accH = self.ObsPathParameters['State']['Acceleration'][2,0]
		Rbl = self.ObsPathParameters['Rbl']
    
    # dynamic model matrix
		Fr = np.array([[0.0, 1/(self.Rm+alti), 0.0],
				           [1/((self.Rn + alti) * np.cos(np.radians(lat))), 0.0, 0.0],
				           [0.0, 0.0, 1.0]])

		Fv = np.array([[0.0, accH, -accN],
				           [-accH, 0.0, accE], 
				           [accN, -accE, 0.0]])

		Fe = np.array([[0.0, 1/(self.Rm+alti), 0.0],
				           [-1/(self.Rn+alti), 0.0, 0.0],
				           [-np.tan(np.radians(lat))/(self.Rn+alti), 0.0, 0.0]])
			
		Ff = np.diag([-self.beta_fx, -self.beta_fy, -self.beta_fz])    
		Fw = np.diag([-self.beta_wx, -self.beta_wy, -self.beta_wz])
			

		# Dynamic coefficient matrix
		F1 = np.concatenate((np.identity(3), Fr*dt_KF, np.zeros((3,9))), axis=1)
		F2 = np.concatenate((np.zeros((3,3)), np.identity(3), Fv*dt_KF, np.zeros((3,3)), Rbl*dt_KF), axis=1)
		F3 = np.concatenate((np.zeros((3,3)), Fe*dt_KF, np.identity(3), Rbl*dt_KF, np.zeros((3,3))), axis=1)
		F4 = np.concatenate((np.zeros((3,9)), np.identity(3)+Fw*dt_KF, np.zeros((3,3))), axis=1)
		F5 = np.concatenate((np.zeros((3,12)), np.identity(3)+Ff*dt_KF), axis=1)
		F = np.concatenate((F1, F2, F3, F4, F5), axis=0)

		# Noise distribution matrix
		Gdw = np.diag([np.sqrt(2*self.beta_wx),np.sqrt(2*self.beta_wy),np.sqrt(2*self.beta_wz)])
		Gdf = np.diag([np.sqrt(2*self.beta_fx),np.sqrt(2*self.beta_fy),np.sqrt(2*self.beta_fz)])
			
		G1 = np.concatenate((Fr*0.5*dt_KF**2, np.zeros((3,9))), axis=1)
		G2 = np.concatenate((np.identity(3)*dt_KF, np.zeros((3,9))), axis=1)  
		G3 = np.concatenate((np.zeros((3,3)), np.identity(3)*dt_KF, np.zeros((3,6))), axis=1)   
		G4 = np.concatenate((np.zeros((3,6)), Gdw*dt_KF, np.zeros((3,3))), axis=1)  
		G5 = np.concatenate((np.zeros((3,9)), Gdf*dt_KF), axis=1) 
		G = np.concatenate((G1, G2, G3, G4, G5), axis=0)

		# Measurement design matrix
		A = np.concatenate((np.identity(6), np.zeros((6,9))), axis=1)

		# Process noise uncertainty
		Q = G@self.Kww@G.T

		# Measurment covariance matrix [sigma_lat_GNSS, sigma_lon_GNSS, sigma_alt_GNSS, sigma_velE_GNSS, sigma_velN_GNSS, sigma_velU_GNSS]
		l = np.array([[0.0],[0.0],[0.0],[0.0],[0.0],[0.0]])
		Kll = np.diag([9999**2, 9999**2, 9999**2, 9999**2, 9999**2, 9999**2])
        
		if not gnss==[]:
			l[0] = lat - gnss[0]
			l[1] = lon - gnss[1]
			l[2] = alti - gnss[2]
			l[3] = velE - gnss[3]
			l[4] = velN - gnss[4]
			l[5] = velU + gnss[5]        
				
			Kll = np.diag([self.sigma_lat_GNSS**2, self.sigma_lon_GNSS**2, self.sigma_alt_GNSS**2,
				 self.sigma_velE_GNSS**2, self.sigma_velN_GNSS**2, self.sigma_velU_GNSS**2])

		# Maintain Kxx symmetry
		self.Kxx = 1/2*(self.Kxx+(self.Kxx).T)

		# Prediction

		Kxx_pred = F@self.Kxx@F.T + Q

		# Update
		K = Kxx_pred @ A.T @ np.linalg.inv( A @ Kxx_pred @ A.T + Kll)        
		self.Kxx = Kxx_pred - K@A@Kxx_pred

		#fp = open("POS.txt", "a")
		#fp.write(str([[self.ObsPathParameters['State']['Position'][0,0]], [self.ObsPathParameters['State']['Position'][1,0]], [self.ObsPathParameters['State']['Position'][2,0]]])+'\n')
		#fp.close()

		if not gnss==[]:

			self.x[:] = 0.0
			# Prediction
			x_pred = F@self.x
			# Update
			self.x = x_pred + K@(l-A@x_pred)

			# update state with Kalman error estimates
			self.ObsPathParameters['State']['Position'] = self.ObsPathParameters['State']['Position'] - np.array([[self.x[0,0]],[self.x[1,0]],[self.x[2,0]]])
			self.ObsPathParameters['State']['Attitude'] = self.ObsPathParameters['State']['Attitude'] - np.array([[self.x[6,0]],[self.x[7,0]],[self.x[8,0]]])
			self.ObsPathParameters['State']['Velocity'] = self.ObsPathParameters['State']['Velocity'] - np.array([[self.x[3,0]],[self.x[4,0]],[self.x[5,0]]])
			self.ObsPathParameters['State']['Biais gyr'] = np.array([[self.x[9,0]],[self.x[10,0]],[self.x[11,0]]])
			self.ObsPathParameters['State']['Biais acc'] = np.array([[self.x[12,0]],[self.x[13,0]],[self.x[14,0]]])

			# Update Rbl and Quaternion
			p0 = self.ObsPathParameters['State']['Attitude'][0,0]
			r0 = self.ObsPathParameters['State']['Attitude'][1,0]
			y0 = self.ObsPathParameters['State']['Attitude'][2,0]

			Rbl = np.array([[np.cos(y0)*np.cos(r0)-np.sin(y0)*np.sin(p0)*np.sin(r0), -np.sin(y0)*np.cos(p0), np.cos(y0)*np.sin(r0)+np.sin(y0)*np.sin(p0)*np.cos(r0)],
					[np.sin(y0)*np.cos(r0)+np.cos(y0)*np.sin(p0)*np.sin(r0), np.cos(y0)*np.cos(p0), np.sin(y0)*np.sin(r0)-np.cos(y0)*np.sin(p0)*np.cos(r0)],
					[-np.cos(p0)*np.sin(r0), np.sin(p0), np.cos(p0)*np.cos(r0)]])

			if 1 + Rbl[0,0] + Rbl[1,1] + Rbl[2,2] > 0:
				q4 = 0.5*pow(1 + Rbl[0,0] + Rbl[1,1] + Rbl[2,2], 0.5)
				q1 = 0.25*(Rbl[2,1] - Rbl[1,2])/q4
				q2 = 0.25*(Rbl[0,2] - Rbl[2,0])/q4
				q3 = 0.25*(Rbl[1,0] - Rbl[0,1])/q4
				self.ObsPathParameters['Quaternion'] = np.array([[q1],[q2],[q3],[q4]])
				self.ObsPathParameters['Rbl'] = Rbl
			else:
				print('No quaternion and Rbl update')


	def init_kalman_filter_2 (self, data):
    
		####### Initial state #######
		lat0 = 46.7804607 #[deg]
		lon0 = 6.6614091 #[deg]
		h0 = 497.3 #[m]
		r0 = 0.028616236 #[rad]
		p0 = 0.010533153 #[rad]
		y0 = -0.922994599 #[rad]
		b_gyr0 = np.array([[0],[0],[0]]) # to get by calibration
		b_acc0 = np.array([[0],[0],[0]]) # to get by calibration
		self.e = 0.08181919 # eccentricity
		self.a = 6378137.0 # equatorial radius

		state_o = {'Position': np.array([[lat0],[lon0],[h0]]), 'Attitude': np.array([[p0],[r0],[y0]]),
				'Velocity': np.array([[0.0],[0.0],[0.0]]), 'Acceleration': np.array([[0.0],[0.0],[0.0]]),
				'Biais gyr': b_gyr0, 'Biais acc': b_acc0}



		Rbl = np.array([[np.cos(y0)*np.cos(r0)-np.sin(y0)*np.sin(p0)*np.sin(r0), -np.sin(y0)*np.cos(p0), np.cos(y0)*np.sin(r0)+np.sin(y0)*np.sin(p0)*np.cos(r0)],
				[np.sin(y0)*np.cos(r0)+np.cos(y0)*np.sin(p0)*np.sin(r0), np.cos(y0)*np.cos(p0), np.sin(y0)*np.sin(r0)-np.cos(y0)*np.sin(p0)*np.cos(r0)],
				[-np.cos(p0)*np.sin(r0), np.sin(p0), np.cos(p0)*np.cos(r0)]])

		q4 = 0.5*pow(1 + Rbl[0,0] + Rbl[1,1] + Rbl[2,2], 0.5)
		q1 = 0.25*(Rbl[2,1] - Rbl[1,2])/q4
		q2 = 0.25*(Rbl[0,2] - Rbl[2,0])/q4
		q3 = 0.25*(Rbl[1,0] - Rbl[0,1])/q4

		Quat = np.array([[q1],[q2],[q3],[q4]])

		self.ObsPathParameters = {'State': state_o, 'Rbl': Rbl, 'Quaternion': Quat}
 
 
    
    ####### Init Kalman Filter #######
        
		# Initial system state [lat, lon, alti, VelE, VelN, velU, pitch, roll, yaw, wx, wy, wz, fx, fy, fz]
		self.x = np.array([[0.0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0]])

		# Initial variance covariance matrix
		self.Kxx = np.diag([99999**2, 99999**2, 99999**2, 99999**2, 99999**2, 99999**2, 99999**2, 99999**2,
				                99999**2, 99999**2, 99999**2, 99999**2, 99999**2, 99999**2, 99999**2])

		# Process noise
		self.sigma_accE = 7.2e2
		self.sigma_accN = 7.2e2
		self.sigma_accH = 1e3
		self.sigma_d_pitch = 5e-1
		self.sigma_d_roll = 5e-1
		self.sigma_d_yaw = 5e-1
		self.sigma_d_wx = 1e-1
		self.sigma_d_wy = 1e-1
		self.sigma_d_wz = 1e-1
		self.sigma_d_fx = 1e-1
		self.sigma_d_fy = 1e-1
		self.sigma_d_fz = 1e-1


		self.Kww = np.diag([self.sigma_accE**2, self.sigma_accN**2, self.sigma_accH**2, self.sigma_d_pitch**2,
				        self.sigma_d_roll**2, self.sigma_d_yaw**2, self.sigma_d_wx**2, self.sigma_d_wy**2,
				        self.sigma_d_wz**2, self.sigma_d_fx**2, self.sigma_d_fy**2, self.sigma_d_fz**2])

		# Biais Gauss-Markov
		self.beta_wx = 60
		self.beta_wy = 60
		self.beta_wz = 60
		self.beta_fx = 60
		self.beta_fy = 60
		self.beta_fz = 60

		# Observation noise
		self.sigma_lat_GNSS = 8e-7
		self.sigma_lon_GNSS = 8e-7
		self.sigma_alt_GNSS = 8e-1
		self.sigma_velE_GNSS = 3e-3
		self.sigma_velN_GNSS = 3e-3
		self.sigma_velU_GNSS = 3e-3    


		####### Init figure #######

		self.Ex = np.array([[0.25e-6],[0],[0]])
		self.Ey = np.array([[0],[0.25e-6],[0]])
		self.Ez = np.array([[0],[0],[0.25e-6]])
		self.Ex_t_o = np.zeros([3,2])
		self.Ey_t_o = np.zeros([3,2])
		self.Ez_t_o = np.zeros([3,2])

		self.figure, self.ax = plt.subplots(2,1)
		self.lines, = self.ax[0].plot([],[], '-r')
		self.lines_obs, = self.ax[0].plot([],[], '--k')
		self.lines_gnss, = self.ax[0].plot([],[], '+k')
		self.lines_alti, = self.ax[1].plot([],[], '-r')
		self.lines_alti_obs, = self.ax[1].plot([],[], '--k')
		self.lines_alti_gnss, = self.ax[1].plot([],[], '+k')
		self.ax[0].set_xlabel('Longitude [deg]')
		self.ax[0].set_ylabel('Latitude [deg]')
		self.ax[1].set_ylabel('Altitude')
		self.ax[1].set_xlabel('Iteration')

		self.figure2, self.ax2 = plt.subplots(3,1)
		self.lines_attitude_pitch, = self.ax2[0].plot([],[], '-r')
		self.lines_attitude_roll, = self.ax2[1].plot([],[], '-r')
		self.lines_attitude_yaw, = self.ax2[2].plot([],[], '-r')
		self.lines_attitude_obs_pitch, = self.ax2[0].plot([],[], '--k')
		self.lines_attitude_obs_roll, = self.ax2[1].plot([],[], '--k')
		self.lines_attitude_obs_yaw, = self.ax2[2].plot([],[], '--k')

		self.ax2[0].set_xlabel('Iteration')
		self.ax2[0].set_ylabel('Pitch [rad]')
		self.ax2[1].set_xlabel('Iteration')
		self.ax2[1].set_ylabel('Roll [rad]')
		self.ax2[2].set_xlabel('Iteration')
		self.ax2[2].set_ylabel('Yaw [rad]')

		# self.fig = plt.figure()
		# # self.ax3 = self.fig.add_subplot(111, projection='3d')
		# self.ax3 = self.fig.gca(projection='3d')
		# self.ax3.set_xlabel('axe X')
		# self.ax3.set_ylabel('axe Y')
		# self.ax3.set_zlabel('axe Z')
		# self.X_o = []
		# self.Y_o = []
		# self.Z_o = []
		# self.X_t = []
		# self.Y_t = []
		# self.Z_t = []
				    
		self.ax[0].axis('equal')
		self.ax[0].grid()
		self.ax[1].grid()
		self.ax2[0].grid()
		self.ax2[1].grid()
		self.ax2[2].grid()

		####### Init time ####### 
		self.t_old_INS = 3600*data.stamp[0] + 60*data.stamp[1] + data.stamp[2] + data.stamp[3]/1e9 - 2 #[sec] -2 to have a delay t_old and t_new first iteration
		


	def INS_mechanization(self, gyr, acc, dt_INS):

		state = self.ObsPathParameters['State']
		Quat = self.ObsPathParameters['Quaternion']
		Rbl = self.ObsPathParameters['Rbl']
					      
		lat = state['Position'][0,0]
		lon = state['Position'][1,0]
		alti = state['Position'][2,0]
		velE = state['Velocity'][0,0]
		velN = state['Velocity'][1,0]
		velU = state['Velocity'][2,0]
		b_gyr = state['Biais gyr']
		b_acc = state['Biais acc']
		s_gyr = 0 # to get by calibration
		s_acc = [[1.0],[0.96],[1]] # to get by calibration

		# Paramerters
		omega_e = np.radians(15/3600) # Earth rotation rate [rad/s]
		self.Rn = self.a/pow(1-pow(self.e*np.sin(np.radians(lat)),2),1/2)
		self.Rm = self.a*(1-self.e**2)/pow(1-pow(self.e*np.sin(np.radians(lat)),2),3/2)
		 

		## NEW ATTITUDE ##  Compute body rotation angular increment

		omega_l_ie = np.array([[0.0],
 				               [omega_e*np.cos(np.radians(lat))],
 				               [omega_e*np.sin(np.radians(lat))]])

		omega_l_el = np.array([[-velN/(self.Rm + alti)],
				           				 [velE/(self.Rn + alti)],
				           				 [velE*np.tan(np.radians(lat))/(self.Rn + alti)]])

		omega_l_il = omega_l_ie + omega_l_el
		omega_b_il = Rbl.T @ omega_l_il  
		omega_b_ib = 1/(1 + s_gyr)*(gyr - b_gyr) # Corrected incremental gyro output
		theta_b_lb = (omega_b_ib - omega_b_il) * dt_INS # Incremental angle [rad]
		theta = np.linalg.norm(theta_b_lb)
			
		if theta==0:
			theta=1e-15

		# Updating quaternion
		s = 2/theta*np.sin(theta/2)
		c = 2*(np.cos(theta/2)-1)

		S = np.array([[c, s*theta_b_lb[2,0], -s*theta_b_lb[1,0], s*theta_b_lb[0,0]],
						      [-s*theta_b_lb[2,0], c, s*theta_b_lb[0,0], s*theta_b_lb[1,0]],
					        [s*theta_b_lb[1,0], -s*theta_b_lb[0,0], c, s*theta_b_lb[2,0]],
					        [-s*theta_b_lb[0,0], -s*theta_b_lb[1,0], -s*theta_b_lb[2,0], c]])

		Quat = Quat + 0.5 * S @ Quat
		q = Quat

		# Updating rotation matrix Rbl
		Rbl = np.array([[q[0,0]**2-q[1,0]**2-q[2,0]**2+q[3,0]**2, 2*(q[0,0]*q[1,0]-q[2,0]*q[3,0]), 2*(q[0,0]*q[2,0]+q[1,0]*q[3,0])],
					         [2*(q[0,0]*q[1,0]+q[2,0]*q[3,0]), -q[0,0]**2+q[1,0]**2-q[2,0]**2+q[3,0]**2, 2*(q[1,0]*q[2,0]-q[0,0]*q[3,0])],
					         [2*(q[0,0]*q[2,0]-q[1,0]*q[3,0]), 2*(q[1,0]*q[2,0]+q[0,0]*q[3,0]), -q[0,0]**2-q[1,0]**2+q[2,0]**2+q[3,0]**2]])

		# Compute new attitude
		pitch = np.arcsin(Rbl[2,1])
		yaw = -np.arctan2(Rbl[0,1], Rbl[1,1])
		roll = -np.arctan2(Rbl[2,0], Rbl[2,2])
			
			
		 ## NEW Velocity ##
		Omega_l_ie = np.array([[0.0, -omega_e*np.sin(np.radians(lat)), omega_e*np.cos(np.radians(lat))],
		 		                   [omega_e*np.sin(np.radians(lat)), 0.0, 0.0],
						               [-omega_e*np.cos(np.radians(lat)), 0.0, 0.0]])


		Omega_l_el = np.array([[0.0, -velE*np.tan(np.radians(lat))/(self.Rn+alti), velE/(self.Rn+alti)],
						                [velE*np.tan(np.radians(lat))/(self.Rn+alti), 0.0, velN/(self.Rm+alti)],
							               [-velE/(self.Rn+alti), -velN/(self.Rm+alti), 0.0]])

		# Accelerometer	
		acc_corr = (acc - b_acc)*(s_acc)
		acc_measure = Rbl @ acc_corr
        
		# Coriolis effect
		acc_coriolis = (2 * Omega_l_ie + Omega_l_el) @ state['Velocity']

		# gravity correction
		a1 = 9.78032677
		a2 = 5.27904e-03
		a3 = 2.327e-05
		a4 = -3.087e-06
		a5 = 4.3977311e-09
		a6 = 7.211e-13

		g_z = a1*(1 + a2*np.sin(np.radians(lat))**2 + a3*np.sin(np.radians(lat))**4) + alti*(a4 + a5*np.sin(np.radians(lat))**2) + a6*alti**2 # Somigliana formula  
		g_z = 9.81
		acc_g = np.array([[0.0], [0.0], [-g_z]])

		acceleration = acc_measure + acc_g - acc_coriolis
		velocity = state['Velocity'] + 0.5 * (state['Acceleration'] + acceleration) * dt_INS

		## NEW POSITION ##
		latitude = np.degrees(np.radians(lat) + 0.5*(velN + velocity[1,0])/(self.Rn + alti) * dt_INS)
		longitude = np.degrees(np.radians(lon) + 0.5*(velE + velocity[0,0])/((self.Rn + alti) * np.cos(np.radians(lat))) * dt_INS)
		altitude = alti + 0.5*(velU + velocity[2,0]) * dt_INS

		## UPDATE STATE AND PLOT WITH INS PARAMETERS
		self.ObsPathParameters['State']['Position'] = np.array([[latitude],[longitude],[altitude]])
		self.ObsPathParameters['State']['Attitude'] = np.array([[pitch],[roll],[yaw]])
		self.ObsPathParameters['State']['Velocity'] = velocity
		self.ObsPathParameters['State']['Acceleration'] = acceleration
		self.ObsPathParameters['Quaternion'] = Quat
		self.ObsPathParameters['Rbl'] = Rbl

		self.lines_obs.set_xdata(np.append(self.lines_obs.get_xdata(), self.ObsPathParameters['State']['Position'][1,0]))
		self.lines_obs.set_ydata(np.append(self.lines_obs.get_ydata(), self.ObsPathParameters['State']['Position'][0,0]))
		
		self.lines_alti_obs.set_xdata(np.append(self.lines_alti_obs.get_xdata(), self.count))
		self.lines_alti_obs.set_ydata(np.append(self.lines_alti_obs.get_ydata(), self.ObsPathParameters['State']['Position'][2,0]))     

		# Display positionin 3D
		# self.X_o.append(self.ObsPathParameters['State']['Position'][1,0])
		# self.Y_o.append(self.ObsPathParameters['State']['Position'][0,0])
		# self.Z_o.append(self.ObsPathParameters['State']['Position'][2,0])
		# self.ax3.plot(np.array(self.X_o), np.array(self.Y_o), np.array(self.Z_o), color='blue')

		# # Display attitude in 3D
		# self.Ex_t_o[:,0] = self.ObsPathParameters['State']['Position'][:,0]
		# self.Ex_t_o[:,1] = (self.ObsPathParameters['State']['Position'] + Rbl@self.Ex)[:,0]
		# self.ax3.plot(self.Ex_t_o[1,:], self.Ex_t_o[0,:], self.Ex_t_o[2,:], color='green')

		# self.Ey_t_o[:,0] = self.ObsPathParameters['State']['Position'][:,0]
		# self.Ey_t_o[:,1] = (self.ObsPathParameters['State']['Position'] + Rbl@self.Ey)[:,0]
		# self.ax3.plot(self.Ey_t_o[1,:], self.Ey_t_o[0,:], self.Ey_t_o[2,:], color='green')

		# self.Ez_t_o[:,0] = self.ObsPathParameters['State']['Position'][:,0]
		# self.Ez_t_o[:,1] = (self.ObsPathParameters['State']['Position'] + Rbl@self.Ez)[:,0]
		# self.ax3.plot(self.Ez_t_o[1,:], self.Ez_t_o[0,:], self.Ez_t_o[2,:], color='green')
		# plt.draw()

		self.lines_attitude_obs_roll.set_xdata(np.append(self.lines_attitude_obs_roll.get_xdata(), self.count))
		self.lines_attitude_obs_roll.set_ydata(np.append(self.lines_attitude_obs_roll.get_ydata(), self.ObsPathParameters['State']['Attitude'][1,0]))
		self.lines_attitude_obs_pitch.set_xdata(np.append(self.lines_attitude_obs_pitch.get_xdata(), self.count))
		self.lines_attitude_obs_pitch.set_ydata(np.append(self.lines_attitude_obs_pitch.get_ydata(), self.ObsPathParameters['State']['Attitude'][0,0]))
		self.lines_attitude_obs_yaw.set_xdata(np.append(self.lines_attitude_obs_yaw.get_xdata(), self.count))
		self.lines_attitude_obs_yaw.set_ydata(np.append(self.lines_attitude_obs_yaw.get_ydata(), self.ObsPathParameters['State']['Attitude'][2,0]))
		
		self.figure.canvas.draw()
		self.figure.canvas.flush_events()
		self.figure2.canvas.draw()
		self.figure2.canvas.flush_events()


def main(args=None):

	rclpy.init(args=args)
	cd = CollectData()
	
	while cd.init_filter:
		rclpy.spin_once(cd)
		if cd.newAccAA and cd.newAngWR:
			cd.init_kalman_filter_2(cd.AccAA)
			cd.init_filter = False
			print('[INFO] Initialisation OK')

	while True:
		rclpy.spin_once(cd)
		if cd.newAccAA and cd.newAngWR:
		
			time_S = time.time()
			
			# Mechanization with new IMU data	
			cd.newAccAA = False
			cd.newAngWR = False
			t_new = 3600*cd.AccAA.stamp[0] + 60*cd.AccAA.stamp[1] + cd.AccAA.stamp[2] + cd.AccAA.stamp[3]/1e9
			dt_INS = t_new - cd.t_old_INS
			cd.t_old_INS = t_new
			
			gyr = np.array([[cd.AngWR.gyry], [-cd.AngWR.gyrx], [cd.AngWR.gyrz]])
			acc = np.array([[cd.AccAA.accy], [-cd.AccAA.accx], [cd.AccAA.accz]])	
				
			cd.INS_mechanization(gyr, acc, dt_INS/1000) ##################


			if cd.newGnsNP:
				cd.newGnsNP = False
				gnss = np.array([[cd.GnsNP.lat], [cd.GnsNP.lon], [cd.GnsNP.height], [cd.GnsNP.vel_e], [cd.GnsNP.vel_n], [cd.GnsNP.vel_d]])
				
				cd.lines_gnss.set_xdata(np.append(cd.lines_gnss.get_xdata(), gnss[1]))
				cd.lines_gnss.set_ydata(np.append(cd.lines_gnss.get_ydata(), gnss[0]))
				cd.lines_alti_gnss.set_xdata(np.append(cd.lines_alti_gnss.get_xdata(), cd.count))
				cd.lines_alti_gnss.set_ydata(np.append(cd.lines_alti_gnss.get_ydata(), gnss[2]))
			else:
				gnss = []
			
			cd.kalman_filter_2(gnss, dt_INS)

			
			# Update figues with XSENS KF data		
			if cd.newPosPL:
				cd.newPosPL = False
				cd.lines.set_xdata(np.append(cd.lines.get_xdata(), cd.PosPL.longitude))
				cd.lines.set_ydata(np.append(cd.lines.get_ydata(), cd.PosPL.latitude))
				cd.ax[0].set_ylim(cd.PosPL.latitude-1e-5, cd.PosPL.latitude+1e-5)
				cd.ax[0].set_xlim(cd.PosPL.longitude-1e-5, cd.PosPL.longitude+1e-5)
			
			if cd.newPosPA:
				cd.newPosPA = False
				cd.lines_alti.set_xdata(np.append(cd.lines_alti.get_xdata(), cd.count))
				cd.lines_alti.set_ydata(np.append(cd.lines_alti.get_ydata(), cd.PosPA.alt_ell))
				cd.ax[1].set_ylim(cd.PosPA.alt_ell-2, cd.PosPA.alt_ell+2)
				cd.ax[1].set_xlim(cd.count-10, cd.count+10)  
			
			if cd.newOriOE:
				cd.newOriOE = False
				#roll
				cd.lines_attitude_roll.set_xdata(np.append(cd.lines_attitude_roll.get_xdata(), cd.count))
				cd.lines_attitude_roll.set_ydata(np.append(cd.lines_attitude_roll.get_ydata(), np.radians(cd.OriOE.roll)))
				cd.ax2[0].set_ylim(np.radians(cd.OriOE.roll)-0.2, np.radians(cd.OriOE.roll)+0.2)
				cd.ax2[0].set_xlim(cd.count-10, cd.count+10)
				#pitch
				cd.lines_attitude_pitch.set_xdata(np.append(cd.lines_attitude_pitch.get_xdata(), cd.count))
				cd.lines_attitude_pitch.set_ydata(np.append(cd.lines_attitude_pitch.get_ydata(), np.radians(cd.OriOE.pitch)))
				cd.ax2[1].set_ylim(np.radians(cd.OriOE.pitch)-0.2, np.radians(cd.OriOE.pitch)+0.2)
				cd.ax2[1].set_xlim(cd.count-10, cd.count+10) 
				#yaw
				cd.lines_attitude_yaw.set_xdata(np.append(cd.lines_attitude_yaw.get_xdata(), cd.count))
				cd.lines_attitude_yaw.set_ydata(np.append(cd.lines_attitude_yaw.get_ydata(), np.radians(cd.OriOE.yaw)))
				cd.ax2[2].set_ylim(np.radians(cd.OriOE.yaw)-0.2, np.radians(cd.OriOE.yaw)+0.2)
				cd.ax2[2].set_xlim(cd.count-10, cd.count+10)

				cd.figure.canvas.draw()
				cd.figure.canvas.flush_events()
				cd.figure2.canvas.draw()
				cd.figure2.canvas.flush_events()	
			
			print(-1/(time_S-time.time()))

			cd.count += 1

	cd.destroy_node()
	rclpy.shutdown()
	
	
if __name__ == '__main__':
	main()
