import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    cam_node=Node(
        package = 'cam_client',
        name = 'cam_client',
        executable = 'main',
        output='screen',
	emulate_tty=True
    )

    ld.add_action(cam_node)
    return ld
