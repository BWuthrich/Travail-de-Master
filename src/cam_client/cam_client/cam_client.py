#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import time
import cv2
import numpy as np
import os.path as op
import tifffile as tif
from cv_bridge import CvBridge

from xsens_msgs.msg import ConfigCam, StaCT, CamImage, CamBatch, TrgSP
from .utils.myTIS import TIS, SinkFormats, listCamerasAvailable

class Camera(Node):
	def __init__(self, cameraName, serial, outputDir, height, width, framerate):
	  
	  super().__init__(cameraName)
	  self.imageCounter = 0
	  self.cameraName = cameraName
	  self.outputDir = outputDir
	  self.tis = TIS()
	  self.tis.showLive(False)
	  self.bridge = CvBridge()
	  self.time_xsens = 0
	  self.time_cpu = 0
	  self.time = time.time()
	  
	  if serial is not None:
	      cam_format = SinkFormats.GRAY8
	      if serial.startswith("41"):
	          cam_format = SinkFormats.BGRA
	      self.tis.openDevice(serial, width, height, framerate, cam_format)
	  
	  # Create publisher for images
	  self.img_msg = CamImage()
	  self.Image_pub = self.create_publisher(CamImage, 'cam/image', 10)
	  
	  # Create timestamp subscriber
	  self.cam_time_sub = self.create_subscription(TrgSP, 'mti/timestamp', self.setTime, 10)
	  self.cam_time_sub
	  
	  
	def setTime(self, msg):
	  self.time_xsens = 3600*msg.stamp[0] + 60*msg.stamp[1] + msg.stamp[2] + msg.stamp[3]/1e9
	  self.time_cpu = time.time()


class camClient(Node):

	def __init__(self):
		super().__init__('camClient')
		
		self.data_dir = None
		self.height = None
		self.width = None
		self.framerate = None
		self.cam_status = 'Inactive'
		self.cam_number = 4

		
		# Initial status message
		self.sta_msg = StaCT()
		self.sta_msg.cam_status = self.cam_status
		
		# Create parameters subscriber
		self.cam_config_sub = self.create_subscription(ConfigCam,
			'config/camclient',
			self.setConfig,
			10)
		self.cam_config_sub	
    
    # Create publisher for cam Status
		self.Status_pub = self.create_publisher(StaCT, 'cam/status', 10)
		# Publish "Inactive"
		self.Status_pub.publish(self.sta_msg)
		
    # Create publisher for images batch (not used)
		self.Images_pub = self.create_publisher(CamBatch, 'cam/image_batch', 10)
	
	def setConfig(self, msg):
		self.get_logger().info("cameras initialisation")
		self.publishStatus("Connecting")
		self.lstCam = []
		self.data_dir = msg.save_file
		self.height = msg.height
		self.width = msg.width
		self.framerate = msg.framerate
		
		# Check for cameras availability
		lstCamTemp = listCamerasAvailable()
		self.get_logger().info(f"listCamerasAvailable {lstCamTemp}")
		if len(lstCamTemp) == 0:
			self.get_logger().error('pipeline not started')
			return
    
    # Wait if not all camera connected   
		while len(lstCamTemp) < self.cam_number:
			self.get_logger().info("Connecting... found cameras: " + str(len(lstCamTemp)) + "/" + str(self.cam_number))
			time.sleep(2)
			lstCamTemp = listCamerasAvailable()
    
    # Init all cameras
		self.publishStatus("Configuring")
		for i, serial in enumerate(lstCamTemp):
			self.get_logger().info(f" Init Cam_{i} : " + str(serial))
			mc = Camera(f"Cam_{i}", serial, self.data_dir, self.height, self.width, self.framerate)
			self.lstCam.append(mc)
		time.sleep(0.1)
		self.publishStatus("Connected")

	def publishStatus(self, status):
		self.cam_status = status
		self.sta_msg.cam_status = self.cam_status
		self.Status_pub.publish(self.sta_msg)



def onNewImage(tis, mc):
		
		# Avoid being called, while the callback is busy
		if mc.busy is True:
			return
			
		mc.busy = True
		image = tis.getImage()
		timestamp = mc.time_xsens + (time.time() - mc.time_cpu)

		# Publish image
		mc.imageCounter += 1
		mc.img_msg.cam_id = int(mc.cameraName[-1])
		mc.img_msg.data = mc.bridge.cv2_to_imgmsg(np.array(image), "mono8")
		mc.img_msg.stamp = timestamp
		mc.Image_pub.publish(mc.img_msg)
		
		#print(f"camera {mc.cameraName[-1]} image n°{mc.imageCounter} temps {timestamp}")
		#filename = op.join(mc.outputDir, f"{mc.cameraName}_{mc.imageCounter:04}.tif")
		#tif.imsave(filename, image)
		
		print(1/(time.time()-mc.time)) 
		mc.time = time.time()
		mc.busy = False

	
		
def main(args=None):
	
	rclpy.init(args=args)
	cc = camClient()
		
	# Waiting for connection and configuration data
	while cc.cam_status == "Inactive":
		rclpy.spin_once(cc, timeout_sec=5)
	
	# Activate trigger and set callbak function
	for mc in cc.lstCam:
		
		# Set Set callback - 
		mc.tis.setImageCallback(onNewImage, mc)
		
		# Trigger OFF - start pipeline - trigger ON
		mc.tis.setProperty("Trigger Mode", False) # "Trigger Mode" or "TriggerMode"
		mc.busy = True
		mc.tis.startPipeline()
		mc.tis.setProperty("Trigger Mode", True) # "Trigger Mode" or "TriggerMode"
	  
	  # Wait a moment, for the camera accepting trigger mode and also emptying the pipeline
		time.sleep(1)
	
	# Activate callback
	for mc in cc.lstCam:
		mc.busy = False  
	
	while True:
		for mc in cc.lstCam:
			rclpy.spin_once(mc, timeout_sec=0)

	

		
	cc.destroy_node()
	rclpy.shutdown()
    
    


if __name__ == '__main__':
    main()
