#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import time
import cv2
import numpy as np
import os.path as op
import tifffile as tif
from cv_bridge import CvBridge

from xsens_msgs.msg import ConfigCam, StaCT, CamImage, CamBatch
from .utils.myTIS import TIS, SinkFormats, listCamerasAvailable

class Camera(Node):
	def __init__(self, cameraName, serial, outputDir, height, width, framerate):
	  
	  super().__init__(cameraName)
	  self.imageCounter = 0
	  self.cameraName = cameraName
	  self.outputDir = outputDir
	  self.busy = True
	  self.tis = TIS()
	  self.tis.showLive(False)
	  self.bridge = CvBridge()
	  
	  if serial is not None:
	      cam_format = SinkFormats.GRAY16_LE
	      if serial.startswith("41"):
	          cam_format = SinkFormats.BGRA
	      self.tis.openDevice(serial, width, height, framerate, cam_format)
		
	  # Set Callback - trigger - start pipeline
	  self.tis.setProperty("Trigger Mode", False)
	  self.tis.setImageCallback(self.onNewImage)
	  self.tis.startPipeline()
	  self.tis.setProperty("Trigger Mode", True)
	  
	  # Create publisher for images
	  self.img_msg = CamImage()
	  self.Image_pub = self.create_publisher(CamImage, 'cam/image', 10)

  
	def onNewImage(self, tis):
      
		# Avoid being called, while the callback is busy
		if self.busy is True:
			return
		start = time.time()
		self.busy = True
		image = tis.getImage()

		# Publish image
		self.imageCounter += 1
		self.img_msg.cam_id = int(self.cameraName[-1])
		self.img_msg.data = self.bridge.cv2_to_imgmsg(np.array(image), "mono8")
		self.Image_pub.publish(self.img_msg)
		print(f"camera {self.cameraName[-1]} image n°{self.imageCounter} temps {time.time()-start}")
		
		
		filename = op.join(self.outputDir, f"{self.cameraName}_{self.imageCounter:04}.tif")
		print("NewImage", filename)
		tif.imsave(filename, image)
		self.busy = False

	def startLog(self, outputDir=None):
		print("startLog", outputDir)
		if outputDir:
			self.outputDir = outputDir
		self.imageCounter = 0
		self.busy = False        
     

class camClient(Node):

	def __init__(self):
		super().__init__('camClient')
		
		self.data_dir = None
		self.height = None
		self.width = None
		self.framerate = None
		self.cam_status = 'Inactive'
		self.cam_config = []
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
		
    # Create publisher for images batch
		self.Images_pub = self.create_publisher(CamBatch, 'cam/image_batch', 10)
	
	def setConfig(self, msg):
		self.get_logger().info("cameras initialisation")
		self.publishStatus("Connecting")
		self.lstCam = []
		self.data_dir = msg.save_file
		self.height = msg.height
		self.width = msg.width
		self.framerate = msg.framerate
		
		
		lstCamTemp = listCamerasAvailable()
		self.get_logger().info(f"listCamerasAvailable {lstCamTemp}")
		if len(lstCamTemp) == 0:
			self.get_logger().error('pipeline not started')
			return
    
    # If not all camera connected   
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
		
		
def main(args=None):
	
	rclpy.init(args=args)
	cc = camClient()
		
	# Waiting for connection and configuration data
	while cc.cam_status == "Inactive":
		rclpy.spin_once(cc, timeout_sec=5)
	
	# Activate callbak function
	for mc in cc.lstCam:
		mc.busy = False  
	
	while True:
		pass
	

		
	cc.destroy_node()
	rclpy.shutdown()
    
    


if __name__ == '__main__':
    main()
