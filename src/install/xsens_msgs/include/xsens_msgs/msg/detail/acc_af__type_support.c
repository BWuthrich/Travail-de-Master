// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xsens_msgs:msg/AccAF.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xsens_msgs/msg/detail/acc_af__rosidl_typesupport_introspection_c.h"
#include "xsens_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xsens_msgs/msg/detail/acc_af__functions.h"
#include "xsens_msgs/msg/detail/acc_af__struct.h"


// Include directives for member types
// Member `stamp`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void AccAF__rosidl_typesupport_introspection_c__AccAF_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xsens_msgs__msg__AccAF__init(message_memory);
}

void AccAF__rosidl_typesupport_introspection_c__AccAF_fini_function(void * message_memory)
{
  xsens_msgs__msg__AccAF__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember AccAF__rosidl_typesupport_introspection_c__AccAF_message_member_array[4] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__AccAF, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "accx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__AccAF, accx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "accy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__AccAF, accy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "accz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__AccAF, accz),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers AccAF__rosidl_typesupport_introspection_c__AccAF_message_members = {
  "xsens_msgs__msg",  // message namespace
  "AccAF",  // message name
  4,  // number of fields
  sizeof(xsens_msgs__msg__AccAF),
  AccAF__rosidl_typesupport_introspection_c__AccAF_message_member_array,  // message members
  AccAF__rosidl_typesupport_introspection_c__AccAF_init_function,  // function to initialize message memory (memory has to be allocated)
  AccAF__rosidl_typesupport_introspection_c__AccAF_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t AccAF__rosidl_typesupport_introspection_c__AccAF_message_type_support_handle = {
  0,
  &AccAF__rosidl_typesupport_introspection_c__AccAF_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xsens_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xsens_msgs, msg, AccAF)() {
  if (!AccAF__rosidl_typesupport_introspection_c__AccAF_message_type_support_handle.typesupport_identifier) {
    AccAF__rosidl_typesupport_introspection_c__AccAF_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &AccAF__rosidl_typesupport_introspection_c__AccAF_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
