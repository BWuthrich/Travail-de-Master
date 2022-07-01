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
		self.count = 0
	
	def getPosPL(self, msg):
		self.newPosPL = True
		self.PosPL = msg

	
	def getOriOE(self, msg):
		pass
	
	def getPosPA(self, msg):
		pass
			
	def getStaSW(self, msg):
		pass		

	def getAccAA(self, msg):
		self.newAccAA = True
		self.AccAA = msg
	
	def getAngWR(self, msg):
		self.AngWR = msg
	
	def getGnsNP(self, msg):
		self.count += 1
		if self.count == 1:
			self.GnsNP = msg
			self.newGnsNP = True	
			self.count = 0
		
		if self.init_filter:
			self.init_kalman_filter_2 (msg)
	
	
# state: dictionnaire {Position, Velocity, Attitude, Acceleration ,Biais gyr, Biais acc}
# Position [lat, lon, h]
# Velocity [velE, velN, velU]


	def kalman_filter_2(self):
		
		# Update state vector with new INS data
		if self.newAccAA:
			print('INS')
			self.t_new = 3600*self.AccAA.stamp[0] + 60*self.AccAA.stamp[1] + self.AccAA.stamp[2] + self.AccAA.stamp[3]/1e9
			dt_INS = self.t_new - self.t_old_INS
			self.t_old_INS = self.t_new
        
			gyr = np.array([[self.AngWR.gyrx], [self.AngWR.gyry], [self.AngWR.gyrz]])
			acc = np.array([[self.AccAA.accx], [self.AccAA.accy], [self.AccAA.accz]])
			self.INS_mechanization(gyr, acc, dt_INS)
			
		else:
			print('NO INS')
			self.t_new = self.t_old_KF + (time.time() - self.t_last_update)
			self.t_last_update = time.time()
		
    
    # Use new INS position or if no new data last estimated position
		#print('** STATE')
		#print(self.state)
		#print()
		lat = self.state['Position'][0,0]
		lon = self.state['Position'][1,0]
		alti = self.state['Position'][2,0]
		velE = self.state['Velocity'][0,0]
		velN = self.state['Velocity'][1,0]
		velU = self.state['Velocity'][2,0]
		accE = self.state['Acceleration'][0,0]
		accN = self.state['Acceleration'][1,0]
		accH = self.state['Acceleration'][2,0]
    
    # Update time and dt
		dt_KF = self.t_new - self.t_old_KF
		self.t_old_KF = self.t_new
    
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
		F2 = np.concatenate((np.zeros((3,3)), np.identity(3), Fv*dt_KF, np.zeros((3,3)), self.Rbl*dt_KF), axis=1)
		F3 = np.concatenate((np.zeros((3,3)), Fe*dt_KF, np.identity(3), self.Rbl*dt_KF, np.zeros((3,3))), axis=1)
		F4 = np.concatenate((np.zeros((3,9)), np.identity(3)+Fw*dt_KF, np.zeros((3,3))), axis=1)
		F5 = np.concatenate((np.zeros((3,12)), np.identity(3)+Ff*dt_KF), axis=1)
		
		#F2 = np.concatenate((np.zeros((3,3)), np.identity(3), Fv*dt_KF, np.zeros((3,6))), axis=1)
		#F3 = np.concatenate((np.zeros((3,3)), Fe*dt_KF, np.identity(3), np.zeros((3,6))), axis=1)

		F = np.concatenate((F1, F2, F3, F4, F5), axis=0)

		# Noise distribution matrix
		G1 = np.concatenate((Fr*0.5*dt_KF**2, np.zeros((3,9))), axis=1)
		G2 = np.concatenate((np.identity(3)*dt_KF, np.zeros((3,9))), axis=1)  
		G3 = np.concatenate((np.zeros((3,3)), np.identity(3)*dt_KF, np.zeros((3,6))), axis=1)   
		G4 = np.concatenate((np.zeros((3,6)), np.identity(3)*dt_KF, np.zeros((3,3))), axis=1)  
		G5 = np.concatenate((np.zeros((3,9)), np.identity(3)*dt_KF), axis=1)  
		G = np.concatenate((G1, G2, G3, G4, G5), axis=0)

		# Measurement design matrix
		A = np.concatenate((np.identity(6), np.zeros((6,9))), axis=1)

		# Process noise uncertainty
		Q = G@self.Kww@G.T

		# Measurment covariance matrix [sigma_lat_GNSS, sigma_lon_GNSS, sigma_alt_GNSS, sigma_velE_GNSS, sigma_velN_GNSS, sigma_velU_GNSS]
		Kll = np.diag([9999**2, 9999**2, 9999**2, 9999**2, 9999**2, 9999**2])
		l = np.array([[0.0],[0.0],[0.0],[0.0],[0.0],[0.0]])
    
		if self.newPosPL:
			self.newPosPL = False
			self.lines_imu.set_xdata(np.append(self.lines_imu.get_xdata(), self.PosPL.longitude))
			self.lines_imu.set_ydata(np.append(self.lines_imu.get_ydata(), self.PosPL.latitude))    
    
		if self.newGnsNP:
			l[0] = lat - self.GnsNP.lat
			l[1] = lon - self.GnsNP.lon
			l[2] = alti - self.GnsNP.height/1000 # [m]
			l[3] = velE - self.GnsNP.vel_e/1000 # [m/s]
			l[4] = velN - self.GnsNP.vel_n/1000 # [m/s]
			l[5] = velU + self.GnsNP.vel_d/1000 # Xsens give Velocity down => sign "+" # [m/s]
			
			Kll = np.diag([self.sigma_lat_GNSS**2, self.sigma_lon_GNSS**2, self.sigma_alt_GNSS**2,
						         self.sigma_velE_GNSS**2, self.sigma_velN_GNSS**2, self.sigma_velU_GNSS**2])
			self.newGnsNP = False

			self.lines_obs.set_xdata(np.append(self.lines_obs.get_xdata(), self.GnsNP.lon))
			self.lines_obs.set_ydata(np.append(self.lines_obs.get_ydata(), self.GnsNP.lat))

		# Prediction
		x_pred = F@self.x
		Kxx_pred = F@self.Kxx@F.T + Q

		# Update
		K = Kxx_pred@A.T@np.linalg.inv(A@Kxx_pred@A.T+Kll)
		self.x = x_pred + K@(l-A@x_pred)
		self.Kxx = Kxx_pred - K@A@Kxx_pred

		# Update state with Kalman error estimates
		#self.state['Position'] = self.state['Position'] - np.array([[self.x[0,0]],[self.x[1,0]],[self.x[2,0]]])
		#self.state['Attitude'] = self.state['Attitude'] - np.array([[self.x[6,0]],[self.x[7,0]],[self.x[8,0]]])
		#self.state['Velocity'] = self.state['Velocity'] - np.array([[self.x[3,0]],[self.x[4,0]],[self.x[5,0]]])
		#self.state['Biais gyr'] = self.state['Biais gyr'] - np.array([[self.x[9,0]],[self.x[10,0]],[self.x[11,0]]])
		#self.state['Biais acc'] = self.state['Biais acc'] - np.array([[self.x[12,0]],[self.x[13,0]],[self.x[14,0]]])

		#Update plot data
		self.lines.set_xdata(np.append(self.lines.get_xdata(), self.state['Position'][1,0]))
		self.lines.set_ydata(np.append(self.lines.get_ydata(), self.state['Position'][0,0]))
		self.ax.set_ylim(self.state['Position'][0,0]-0.00002, self.state['Position'][0,0]+0.00002)
		self.ax.set_xlim(self.state['Position'][1,0]-0.00002, self.state['Position'][1,0]+0.00002)
		#self.ax.set_ylim(46.7799, 46.7801)
		#self.ax.set_xlim(6.6609, 6.6611)

		self.figure.canvas.draw()
		self.figure.canvas.flush_events()



	def init_kalman_filter_2 (self, data):
		# Initial state - a récupérer depuis la wb app?
		lat0 = 46.780 #[deg]
		lon0 = 6.661 #[deg]
		h0 = 450 #[m]
		p0 = 0 #[rad]
		r0 = 0 #[rad]
		y0 = 0 #[rad]
		b_gyr0 = np.array([[0],[0],[0]]) # to get by calibration
		b_acc0 = np.array([[0],[0],[0]]) # to get by calibration
			
		self.state = {'Position': np.array([[lat0],[lon0],[h0]]), 'Attitude': np.array([[p0],[r0],[y0]]),
							    'Velocity': np.array([[0],[0],[0]]), 'Acceleration': np.array([[0],[0],[0]]),
							    'Biais gyr': b_gyr0, 'Biais acc': b_acc0}

		self.Rbl = np.array([[np.cos(y0)*np.cos(r0)-np.sin(y0)*np.sin(p0)*np.sin(r0), -np.sin(y0)*np.cos(p0), np.cos(y0)*np.sin(r0)+np.sin(y0)*np.sin(p0)*np.cos(r0)],
							           [np.sin(y0)*np.cos(r0)+np.cos(y0)*np.sin(p0)*np.sin(r0), np.cos(y0)*np.cos(p0), np.sin(y0)*np.sin(r0)-np.cos(y0)*np.sin(p0)*np.cos(r0)],
							           [-np.cos(p0)*np.sin(r0), np.sin(p0), np.cos(p0)*np.cos(r0)]])

		q4 = 0.5*pow(1 + self.Rbl[0,0] + self.Rbl[1,1] + self.Rbl[2,2], 0.5)
		q1 = 0.25*(self.Rbl[2,1] + self.Rbl[1,2])/q4
		q2 = 0.25*(self.Rbl[0,2] + self.Rbl[2,0])/q4
		q3 = 0.25*(self.Rbl[1,0] + self.Rbl[0,1])/q4

		self.Quat = np.array([[q1],[q2],[q3],[q4]])

		# Initial system state [lat, lon, alti, VelE, VelN, velU, pitch, roll, yaw, wx, wy, wz, fx, fy, fz]
		self.x = np.array([[lat0],[lon0],[h0],[0.0],[0.0],[0.0],[p0],[r0],[y0],[0.0],[0.0],[0.0],[0.0],[0.0],[0.0]])
		
		# Initial variance covariance matrix
		self.Kxx = np.diag([9999**2, 9999**2, 9999**2, 9999**2, 9999**2, 9999**2, 9999**2, 9999**2,
				                9999**2, 9999**2, 9999**2, 9999**2, 9999**2, 9999**2, 9999**2])

		# Process noise
		self.sigma_accE = 120
		self.sigma_accN = 120
		self.sigma_accH = 120
		self.sigma_d_pitch = 10
		self.sigma_d_roll = 10
		self.sigma_d_yaw = 10
		self.sigma_d_wx = 300
		self.sigma_d_wy = 300
		self.sigma_d_wz = 300
		self.sigma_d_fx = 300
		self.sigma_d_fy = 300
		self.sigma_d_fz = 300

		self.Kww = np.diag([self.sigma_accE**2, self.sigma_accN**2, self.sigma_accH**2, self.sigma_d_pitch**2,
				            self.sigma_d_roll**2, self.sigma_d_yaw**2, self.sigma_d_wx**2, self.sigma_d_wy**2,
				            self.sigma_d_wz**2, self.sigma_d_fx**2, self.sigma_d_fy**2, self.sigma_d_fz**2])

		# !!!!!
		self.beta_wx = 0.01 #######################
		self.beta_wy = 0.01 #######################
		self.beta_wz = 0.01 #######################
		self.beta_fx = 0.01 #######################
		self.beta_fy = 0.01 #######################
		self.beta_fz = 0.01 #######################

		# Observation noise
		self.sigma_lat_GNSS = 10e-8
		self.sigma_lon_GNSS = 10e-8
		self.sigma_alt_GNSS = 3
		self.sigma_velE_GNSS = 0.0001
		self.sigma_velN_GNSS = 0.0001
		self.sigma_velU_GNSS = 0.0001


		# Init time
		self.t_old_KF = 3600*data.stamp[0] + 60*data.stamp[1] + data.stamp[2] + data.stamp[3]/1e9 - 2 #[sec] -2 to have a delay t_old and t_new first iteration
		self.t_old_INS = self.t_old_KF
		self.t_last_update = time.time() # To compute dt_KF without new data
		self.init_filter = False
		
		# Start filter
		filter_freq = 1/10	# Filter update frequency [s]
		self.timer = self.create_timer(filter_freq, self.kalman_filter_2)

		# Init figure
		self.figure, self.ax = plt.subplots()
		self.lines, = self.ax.plot([],[], '-r')
		self.lines_obs, = self.ax.plot([],[], '+k')
		self.lines_imu, = self.ax.plot([],[], '.b')
		self.ax.grid()





# Update rotation matrix body to local frame
	def INS_mechanization(self, gyr, acc, dt_INS):
    
		lat = self.state['Position'][0,0]
		lon = self.state['Position'][1,0]
		alti = self.state['Position'][2,0]
		velE = self.state['Velocity'][0,0]
		velN = self.state['Velocity'][1,0]
		velU = self.state['Velocity'][2,0]
		b_gyr = self.state['Biais gyr']
		b_acc = self.state['Biais acc']
		s_gyr = 0 # to get by calibration
		s_acc = 0 # to get by calibration

		# Paramerters
		omega_e = np.radians(15/3600) # Earth rotation rate [rad/s]
		e = 0.08181919 # eccentricity
		a = 6378137.0 # equatorial radius
		self.Rn = a/pow(1-pow(e*np.sin(np.radians(lat)),2),1/2)
		self.Rm = a*(1-e**2)/pow(1-pow(e*np.sin(np.radians(lat)),2),3/2)
			 

		## NEW ATTITUDE ##  
		# Compute body rotation angular increment
		omega_l_ie = np.array([[0.0],
				                   [omega_e*np.cos(np.radians(lat))],
				                   [omega_e*np.sin(np.radians(lat))]])
    
		omega_l_el = np.array([[-velN/(self.Rm + alti)],
				                   [velE/(self.Rn + alti)],
				                   [velE*np.tan(np.radians(lat))/(self.Rn + alti)]])

		omega_l_il = omega_l_ie + omega_l_el
		omega_b_il = self.Rbl.T @ omega_l_il  
		omega_b_ib = 1/(1 + s_gyr)*(gyr - b_gyr) # Corrected incremental gyro output
		theta_b_lb = (omega_b_ib - omega_b_il) * dt_INS # Incremental angle [rad]
		theta = np.linalg.norm(theta_b_lb)

		# Updating quaternion
		s = 2/theta*np.sin(theta/2)
		c = 2*(np.cos(theta/2)-1)
		
		S = np.array([[c, s*theta_b_lb[2,0], -s*theta_b_lb[1,0], s*theta_b_lb[0,0]],
				          [-s*theta_b_lb[2,0], c, s*theta_b_lb[0,0], s*theta_b_lb[1,0]],
				          [s*theta_b_lb[1,0], -s*theta_b_lb[0,0], c, s*theta_b_lb[2,0]],
				          [-s*theta_b_lb[0,0], -s*theta_b_lb[1,0], -s*theta_b_lb[2,0], c]])
		
		self.Quat = self.Quat + 0.5 * S @ self.Quat
		q = self.Quat

		# Updating rotation matrix Rbl
		self.Rbl = np.array([[q[0,0]**2-q[1,0]**2-q[2,0]**2+q[3,0]**2, 2*(q[0,0]*q[1,0]-q[2,0]*q[3,0]), 2*(q[0,0]*q[2,0]+q[1,0]*q[3,0])],
				            [2*(q[0,0]*q[1,0]+q[2,0]*q[3,0]), -q[0,0]**2+q[1,0]**2-q[2,0]**2+q[3,0]**2, 2*(q[1,0]*q[2,0]-q[0,0]*q[3,0])],
				            [2*(q[0,0]*q[2,0]-q[1,0]*q[3,0]), 2*(q[1,0]*q[2,0]+q[0,0]*q[3,0]), -q[0,0]**2-q[1,0]**2+q[2,0]**2+q[3,0]**2]])

		# Compute new attitude
		pitch = np.arcsin(self.Rbl[2,1])
		yaw = -np.arctan2(self.Rbl[0,1], self.Rbl[1,1])
		roll = -np.arctan2(self.Rbl[2,0], self.Rbl[2,2])



		## NEW Velocity ##
		Omega_l_ie = np.array([[0.0, -omega_e*np.sin(np.radians(lat)), omega_e*np.cos(np.radians(lat))],
				                   [omega_e*np.sin(np.radians(lat)), 0.0, 0.0],
				                   [-omega_e*np.cos(np.radians(lat)), 0.0, 0.0]])


		Omega_l_el = np.array([[0.0, -velE*np.tan(np.radians(lat))/(self.Rn+alti), velE/(self.Rn+alti)],
				                   [velE*np.tan(np.radians(lat))/(self.Rn+alti), 0.0, velN/(self.Rm+alti)],
				                   [-velE/(self.Rn+alti), -velN/(self.Rm+alti), 0.0]])

		# Accelerometer	
		acc_corr = 1/(1 + s_acc)*(acc - b_acc)
		acc_corr = acc
		acc_measure = self.Rbl @ acc_corr
		
		# Coriolis effect
		acc_coriolis = (2 * Omega_l_ie + Omega_l_el) @ self.state['Velocity']

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
		
		print('ames')
		print(acc_measure)
		print('a coriol')
		print(acc_coriolis)
		print('aG')
		print(acc_g)
		
		
		acceleration = acc_measure - acc_coriolis + acc_g
		velocity = self.state['Velocity'] + 0.5 * (self.state['Acceleration'] + acceleration) * dt_INS
		
		## NEW POSITION ##
		latitude = np.degrees(np.radians(lat) + 0.5*(velN + velocity[1,0])/(self.Rn + alti) * dt_INS)
		longitude = np.degrees(np.radians(lon) + 0.5*(velE + velocity[0,0])/((self.Rn + alti) * np.cos(np.radians(lat))) * dt_INS)
		altitude = alti + 0.5*(velU + velocity[2,0]) * dt_INS

		## UPDATE STATE WITH INS PARAMETERS
		self.state['Position'] = np.array([[latitude],[longitude],[altitude]])
		self.state['Attitude'] = np.array([[pitch],[roll],[yaw]])
		self.state['Velocity'] = velocity
		self.state['Acceleration'] = acceleration


def main(args=None):

	rclpy.init(args=args)
	cd = CollectData()

	rclpy.spin(cd)
	
	cd.destroy_node()
	rclpy.shutdown()
    
if __name__ == '__main__':
	main()
