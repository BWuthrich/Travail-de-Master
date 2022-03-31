import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
#    config = os.path.join(
#        get_package_share_directory('xsens_driver'),
#        'config',
#        'params.yaml'
#        )

    Xsens_node=Node(
        package = 'xsens_driver',
        name = 'xsens_measure',
        executable = 'main',
        output='screen',
	emulate_tty=True
#        parameters = [config]
    )
    
    ntrip_node=Node(
        package = 'ntrip_client',
        name = 'ntrip_pub',
        executable = 'main',
        output='screen',
	emulate_tty=True
    )
    
    central_config_node=Node(
        package = 'central',
        name = 'central_config',
        executable = 'main',
        output='screen',
	emulate_tty=True
    )

    ld.add_action(Xsens_node)
    ld.add_action(ntrip_node)
    ld.add_action(central_config_node)
    return ld
