// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xsens_msgs:msg/ConfigCam.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xsens_msgs/msg/detail/config_cam__rosidl_typesupport_introspection_c.h"
#include "xsens_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xsens_msgs/msg/detail/config_cam__functions.h"
#include "xsens_msgs/msg/detail/config_cam__struct.h"


// Include directives for member types
// Member `save_file`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xsens_msgs__msg__ConfigCam__init(message_memory);
}

void ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_fini_function(void * message_memory)
{
  xsens_msgs__msg__ConfigCam__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_message_member_array[4] = {
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__ConfigCam, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__ConfigCam, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "framerate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__ConfigCam, framerate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "save_file",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__ConfigCam, save_file),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_message_members = {
  "xsens_msgs__msg",  // message namespace
  "ConfigCam",  // message name
  4,  // number of fields
  sizeof(xsens_msgs__msg__ConfigCam),
  ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_message_member_array,  // message members
  ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_init_function,  // function to initialize message memory (memory has to be allocated)
  ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_message_type_support_handle = {
  0,
  &ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xsens_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xsens_msgs, msg, ConfigCam)() {
  if (!ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_message_type_support_handle.typesupport_identifier) {
    ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ConfigCam__rosidl_typesupport_introspection_c__ConfigCam_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
