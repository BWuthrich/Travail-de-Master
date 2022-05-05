// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xsens_msgs:msg/StaCT.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xsens_msgs/msg/detail/sta_ct__rosidl_typesupport_introspection_c.h"
#include "xsens_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xsens_msgs/msg/detail/sta_ct__functions.h"
#include "xsens_msgs/msg/detail/sta_ct__struct.h"


// Include directives for member types
// Member `cam_status`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StaCT__rosidl_typesupport_introspection_c__StaCT_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xsens_msgs__msg__StaCT__init(message_memory);
}

void StaCT__rosidl_typesupport_introspection_c__StaCT_fini_function(void * message_memory)
{
  xsens_msgs__msg__StaCT__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StaCT__rosidl_typesupport_introspection_c__StaCT_message_member_array[1] = {
  {
    "cam_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__StaCT, cam_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StaCT__rosidl_typesupport_introspection_c__StaCT_message_members = {
  "xsens_msgs__msg",  // message namespace
  "StaCT",  // message name
  1,  // number of fields
  sizeof(xsens_msgs__msg__StaCT),
  StaCT__rosidl_typesupport_introspection_c__StaCT_message_member_array,  // message members
  StaCT__rosidl_typesupport_introspection_c__StaCT_init_function,  // function to initialize message memory (memory has to be allocated)
  StaCT__rosidl_typesupport_introspection_c__StaCT_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StaCT__rosidl_typesupport_introspection_c__StaCT_message_type_support_handle = {
  0,
  &StaCT__rosidl_typesupport_introspection_c__StaCT_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xsens_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xsens_msgs, msg, StaCT)() {
  if (!StaCT__rosidl_typesupport_introspection_c__StaCT_message_type_support_handle.typesupport_identifier) {
    StaCT__rosidl_typesupport_introspection_c__StaCT_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StaCT__rosidl_typesupport_introspection_c__StaCT_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
