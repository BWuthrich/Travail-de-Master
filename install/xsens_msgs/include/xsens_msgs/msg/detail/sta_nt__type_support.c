// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xsens_msgs:msg/StaNT.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xsens_msgs/msg/detail/sta_nt__rosidl_typesupport_introspection_c.h"
#include "xsens_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xsens_msgs/msg/detail/sta_nt__functions.h"
#include "xsens_msgs/msg/detail/sta_nt__struct.h"


// Include directives for member types
// Member `ntrip_status`
// Member `rtcm_status`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StaNT__rosidl_typesupport_introspection_c__StaNT_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xsens_msgs__msg__StaNT__init(message_memory);
}

void StaNT__rosidl_typesupport_introspection_c__StaNT_fini_function(void * message_memory)
{
  xsens_msgs__msg__StaNT__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StaNT__rosidl_typesupport_introspection_c__StaNT_message_member_array[2] = {
  {
    "ntrip_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__StaNT, ntrip_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rtcm_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__StaNT, rtcm_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StaNT__rosidl_typesupport_introspection_c__StaNT_message_members = {
  "xsens_msgs__msg",  // message namespace
  "StaNT",  // message name
  2,  // number of fields
  sizeof(xsens_msgs__msg__StaNT),
  StaNT__rosidl_typesupport_introspection_c__StaNT_message_member_array,  // message members
  StaNT__rosidl_typesupport_introspection_c__StaNT_init_function,  // function to initialize message memory (memory has to be allocated)
  StaNT__rosidl_typesupport_introspection_c__StaNT_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StaNT__rosidl_typesupport_introspection_c__StaNT_message_type_support_handle = {
  0,
  &StaNT__rosidl_typesupport_introspection_c__StaNT_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xsens_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xsens_msgs, msg, StaNT)() {
  if (!StaNT__rosidl_typesupport_introspection_c__StaNT_message_type_support_handle.typesupport_identifier) {
    StaNT__rosidl_typesupport_introspection_c__StaNT_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StaNT__rosidl_typesupport_introspection_c__StaNT_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
