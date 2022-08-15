#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import base64
import socket
import serial

from xsens_msgs.srv import RTCMdata
from xsens_msgs.msg import ConfigNtrip, StaNT

class ntripClient(Node):
	RTCMv3_PREAMBLE = bytes.fromhex("D300")
	
	def __init__(self):
		super().__init__('ntripClient')
		
		self.port = None
		self.host = None
		self.username = None
		self.password = None
		self.mountpoint = None
		
		self.rtcm_device = None
		self.rtcm_port = None
		self.rtcm_baudrate = None
		self.RTCMtimer = None
		self.timer = None
		
		self.GGASendRate = 10		# send GGA every NN requests
		self.sendGGA = False
		self.socket_ntrip = None
		self.posIsSet = False
		self.ntrip_status = "Inactive"
		self.rtcm_status = "Inactive"
		# Initial status message
		self.sta_msg = StaNT()
		self.sta_msg.ntrip_status = self.ntrip_status
		self.sta_msg.rtcm_status = self.rtcm_status
		
		self.setPosition(0, 0, 0)
		
		# Create parameters subscriber
		self.ntrip_config_sub = self.create_subscription(ConfigNtrip,
			'config/ntripclient',
			self.setConfig,
			10)
		self.ntrip_config_sub	
    
    # Create publisher for ntrip Status
		self.Status_pub = self.create_publisher(StaNT, 'ntrip/status', 10)
		# Publish "Inactive"
		self.Status_pub.publish(self.sta_msg)
           	
    # Create service to set position on request
		self.RTCMsrv = self.create_service(RTCMdata, 'RTCM_data', self.RTCM_srv_callback)


	def publishStatus(self, status_ntrip, status_rtcm):
		self.ntrip_status = status_ntrip
		self.rtcm_status = status_rtcm
		self.sta_msg.ntrip_status = self.ntrip_status
		self.sta_msg.rtcm_status = self.rtcm_status
		self.Status_pub.publish(self.sta_msg)
		

	def setConfig(self, msg):
		self.publishStatus("Configuring", self.rtcm_status)
		self.timer = None	
		self.mountpoint = msg.mountpoint
		self.port = msg.port
		self.host = msg.host
		self.RTCMtimer = msg.rtcm_timer
		
		if self.username != msg.username or self.password != msg.password:
			self.username = msg.username
			self.password = msg.password
			self.setUserPassword(self.username, self.password)
					
		self.connect_ntrip()
		
		if self.rtcm_port != msg.rtcm_port or self.rtcm_baudrate != msg.rtcm_baudrate:
			self.rtcm_port = msg.rtcm_port
			self.rtcm_baudrate = msg.rtcm_baudrate
			self.connect_rtcm()

	
	# connect rtcm
	def connect_rtcm(self):
		try:		
			self.publishStatus(self.ntrip_status, "Connecting")
			self.rtcm_device = serial.Serial(self.rtcm_port, self.rtcm_baudrate, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE)#, timeout=0.2, writeTimeout=0.2)
			self.publishStatus(self.ntrip_status, "Connected")
		except Exception as e:
			print(e)
			self.publishStatus(self.ntrip_status, "Error")
		

	# connect to ntrip server
	def connect_ntrip(self):
		try:
			self.publishStatus("Connecting", self.rtcm_status)
			self.socket_ntrip = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			self.socket_ntrip.connect((self.host, int(self.port)))
			
			self.socket_ntrip.send(self.getHeaderBytes())			
			data = self.socket_ntrip.recv(1024)
			data_str = data.decode()

			if data_str.startswith("ICY 200 OK"):
				print("ICY 200 OK", "OK")
				self.publishStatus("Connected", self.rtcm_status)
				
			elif data_str.startswith("HTTP/1.1 200 OK"):
				print("HTTP/1.1 200 OK")
				self.publishStatus("Connected", self.rtcm_status)
				self.sendGGA = True
			else:
				self.publishStatus("Error", self.rtcm_status)
			
		except Exception as e:
			print(e)
			self.publishStatus("Error", self.rtcm_status)
			self.socket_ntrip.close()
			self.socket_ntrip = None
	
	
	def setUserPassword(self, username, password):
		self.pwd = base64.b64encode(f"{username}:{password}".encode()).decode()	
        	
	
	def RTCM_callback(self):
		for d in self.readOneSplittedData():	
			try:
				self.rtcm_device.write(d)
			except Exception as e:
				print(e)


			
	def RTCM_srv_callback(self, request, response):
		self.setPosition(request.longitude, request.latitude, request.alti_ell)
		self.get_logger().info("ntrip - new position set")
		for d in self.readOneSplittedData():	
			try:
				self.rtcm_device.write(d)
			except Exception as e:
				print(e)
		return response
		
	
	def getHeaderBytes(self):
		header =\
		    f"GET /{self.mountpoint} HTTP/1.1\r\n" +\
		    f"Host {self.host}\r\n" +\
		    "Ntrip-Version: Ntrip/2.0\r\n" +\
		    "User-Agent: NTRIP python\r\n" +\
		    "Accept: */*" +\
		    "Connection: close\r\n" +\
		    f"Authorization: Basic {self.pwd}\r\n\r\n"
		return header.encode()
		
	
	def setPosition(self, lat, lon, height=0):
		self.flagN = "N"
		self.flagE = "E"
		if lon > 180:
			    lon = (lon-360)*-1
			    self.flagE = "W"
		elif (lon < 0 and lon >= -180):
			    lon *= -1
			    self.flagE = "W"
		elif lon < -180:
			    lon += 360
			    self.flagE = "E"
		else:
		    	self.lon = lon
		if lat < 0:
			    lat *= -1
			    self.flagN = "S"

		self.lonDeg = int(lon)
		self.latDeg = int(lat)
		self.lonMin = (lon-self.lonDeg)*60
		self.latMin = (lat-self.latDeg)*60
		self.height = height
		self.posIsSet = True
		self.i = 0
	
	
	def readOneSplittedData(self):
        	return self.splitRTCM(self.readOneData())
        	
        
	def splitRTCM(self, data):
		begin = data.find(self.RTCMv3_PREAMBLE)
		while True:
			# we have to split RTCM by package
			# if data[begin] == 211:
			l1 = data[begin+1]
			l2 = data[begin+2]
			pkt_len = ((l1 & 0x3) << 8) + l2
			# pkt = data[begin+3:begin+3+pkt_len]
			# parity = data[begin+3+pkt_len:begin+6+pkt_len]
			if data[begin] == 211:
				yield data[begin:begin+6+pkt_len]
			begin += 6 + pkt_len
			id = data[begin:].find(self.RTCMv3_PREAMBLE)
			if id == -1:
				break
			begin += id
			
	
	def readOneData(self):
		if self.sendGGA and not (self.i % self.GGASendRate):
			self.socket_ntrip.sendall(self.getGGABytes())
		self.i += 1
		data = self.socket_ntrip.recv(1024)
		return data
	
	
	def getGGABytes(self):
		gga = ""
		if self.posIsSet:
		    now = datetime.datetime.utcnow()
		    gga = f"GPGGA,{now.hour:02d}{now.minute:02d}{now.second:04.2f}," +\
		        f"{self.latDeg:02d}{self.latMin:011.8f},{self.flagN:1s}," +\
		        f"{self.lonDeg:03d}{self.lonMin:011.8f},{self.flagE:1s}," +\
		        f"1,05,0.19,+00400,M,{self.height:5.3f},M,,"
		    checksum = self.calcultateCheckSum(gga)
		    gga = f"${gga}*{checksum}\r\n\r\n"
		else:
		    print("warning : no position set! \
		        cannot generate GGA without position")
		return gga.encode()
		

	def printHex(self,data):
		tt = data.hex()
		return " ".join([tt[2*i:2*i+2].upper() for i in range(len(tt)//2)])
		

def main(args=None):

	rclpy.init(args=args)
	nc = ntripClient()
	
	while True:
		
		# Waiting for connection and configuration data
		while nc.ntrip_status != "Connected" or nc.rtcm_status != "Connected" :
			rclpy.spin_once(nc, timeout_sec=5)
		
		# Start sending RTCM correction
		nc.timer = nc.create_timer(float(nc.RTCMtimer), nc.RTCM_callback)
		
		while nc.ntrip_status == "Connected" and nc.rtcm_status == "Connected" :
			rclpy.spin_once(nc, timeout_sec=0)
	
	nc.destroy_node()
	rclpy.shutdown()
    
    


if __name__ == '__main__':
	main()
