// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xsens_msgs:msg/CamImage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xsens_msgs/msg/detail/cam_image__rosidl_typesupport_introspection_c.h"
#include "xsens_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xsens_msgs/msg/detail/cam_image__functions.h"
#include "xsens_msgs/msg/detail/cam_image__struct.h"


// Include directives for member types
// Member `data`
#include "sensor_msgs/msg/image.h"
// Member `data`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CamImage__rosidl_typesupport_introspection_c__CamImage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xsens_msgs__msg__CamImage__init(message_memory);
}

void CamImage__rosidl_typesupport_introspection_c__CamImage_fini_function(void * message_memory)
{
  xsens_msgs__msg__CamImage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CamImage__rosidl_typesupport_introspection_c__CamImage_message_member_array[3] = {
  {
    "cam_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__CamImage, cam_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__CamImage, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__CamImage, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CamImage__rosidl_typesupport_introspection_c__CamImage_message_members = {
  "xsens_msgs__msg",  // message namespace
  "CamImage",  // message name
  3,  // number of fields
  sizeof(xsens_msgs__msg__CamImage),
  CamImage__rosidl_typesupport_introspection_c__CamImage_message_member_array,  // message members
  CamImage__rosidl_typesupport_introspection_c__CamImage_init_function,  // function to initialize message memory (memory has to be allocated)
  CamImage__rosidl_typesupport_introspection_c__CamImage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CamImage__rosidl_typesupport_introspection_c__CamImage_message_type_support_handle = {
  0,
  &CamImage__rosidl_typesupport_introspection_c__CamImage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xsens_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xsens_msgs, msg, CamImage)() {
  CamImage__rosidl_typesupport_introspection_c__CamImage_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!CamImage__rosidl_typesupport_introspection_c__CamImage_message_type_support_handle.typesupport_identifier) {
    CamImage__rosidl_typesupport_introspection_c__CamImage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CamImage__rosidl_typesupport_introspection_c__CamImage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
