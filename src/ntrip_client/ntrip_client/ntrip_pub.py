#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import base64
import socket

from xsens_msgs.srv import RTCMdata
from xsens_msgs.msg import ConfigNtrip, RTCMcorr

class ntripClient(Node):
	RTCMv3_PREAMBLE = bytes.fromhex("D300")
	
	def __init__(self):
		super().__init__('ntripClient')
		
		self.port = None
		self.host = None
		self.username = None
		self.password = None
		self.mountpoint = None
		self.RTCMtimer = None
		
		self.GGASendRate = 10		# send GGA every NN requests
		self.sendGGA = False
		self.socket = None
		self.posIsSet = False
		
		self.setPosition(0, 0, 0)
		
		# Create parameters subscriber
		self.ntrip_config_sub = self.create_subscription(ConfigNtrip,
			'config/ntripclient',
			self.updateConfig,
			10)
		self.ntrip_config_sub	
            	
            	# Create publisher for RTCM correction data
		self.RTCM_pub = self.create_publisher(RTCMcorr, 'ntrip/rtcm_data', 10)
            	
            	# Create service to set position on request
		self.RTCMsrv = self.create_service(RTCMdata, 'RTCM_data', self.RTCM_srv_callback)


	def updateConfig(self, msg):
		self.mountpoint = msg.mountpoint
		if self.RTCMtimer != msg.rtcm_timer:
			self.RTCMtimer = msg.rtcm_timer
			self.timer = self.create_timer(self.RTCMtimer, self.RTCM_pub_callback)	
		
		if self.username != msg.username or self.password != msg.password:
			self.username = msg.username
			self.password = msg.password
			self.setUserPassword(self.username, self.password)
				
		if self.host != msg.host or self.port != msg.port:
			self.port = msg.port
			self.host = msg.host
			if not self.connect():
				RuntimeError("enable to connect to ntrip server")
		self.get_logger().info("ntrip configuration updated")
		
		
	
	def RTCM_pub_callback (self):
		msg = RTCMcorr()		
		# Bytes data needs to be flattened to be send to the client
		data_array=[]
		data_layout = []
		for d in self.readOneSplittedData():
			data_layout.append(len(d))
			for elem in d:
				data_array.append(elem)
		msg.rtcm_data = data_array
		msg.layout = data_layout
		self.RTCM_pub.publish(msg)
		self.get_logger().info("RTCM corrections sent to client")
		
	
	def RTCM_srv_callback(self, request, response):
		self.setPosition(request.longitude, request.latitude, request.alti_ell)
		self.get_logger().info("ntrip - new position set")
		return response
	
	def setUserPassword(self, username, password):
        	self.pwd = base64.b64encode(f"{username}:{password}".encode()).decode()

	def connect(self):
		print("connect")
		if self.socket is not None:
			return
		self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.socket.connect((self.host, int(self.port)))
		self.socket.send(self.getHeaderBytes())
		print("Waiting answer...")
		data = self.socket.recv(1024)
		data_str = data.decode()

		if data_str.startswith("ICY 200 OK"):
			    print("ICY 200 OK", "OK")
			    return True
		elif data_str.startswith("HTTP/1.1 200 OK"):
			    print("HTTP/1.1 200 OK")
			    self.sendGGA = True
			    return True
		else:
			    print("ERROR")
			    self.socket.close()
			    self.socket = None
			    return False

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
		#print("RTCM all - ", self.printHex(data))
		#print()
		#print(data)
		while True:
			# we have to split RTCM by package
			# if data[begin] == 211:
			l1 = data[begin+1]
			l2 = data[begin+2]
			pkt_len = ((l1 & 0x3) << 8) + l2
			# pkt = data[begin+3:begin+3+pkt_len]
			# parity = data[begin+3+pkt_len:begin+6+pkt_len]
			if data[begin] == 211:
				# print("RTCM split -", self.printHex(data[begin:begin+6+pkt_len]))
				yield data[begin:begin+6+pkt_len]
			begin += 6 + pkt_len
			id = data[begin:].find(self.RTCMv3_PREAMBLE)
			if id == -1:
				break
			begin += id
	
	def readOneData(self):
		if self.sendGGA and not (self.i % self.GGASendRate):
			self.socket.sendall(self.getGGABytes())
		self.i += 1
		data = self.socket.recv(1024)
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
	rclpy.spin_once(nc, timeout_sec=5)
	if not nc.connect():
		RuntimeError("enable to connect to ntrip server")
	
	rclpy.spin(nc)	
	
	nc.destroy_node()
	rclpy.shutdown()
    
    


if __name__ == '__main__':
	main()
