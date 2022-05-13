// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xsens_msgs:msg/CamBatch.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xsens_msgs/msg/detail/cam_batch__rosidl_typesupport_introspection_c.h"
#include "xsens_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xsens_msgs/msg/detail/cam_batch__functions.h"
#include "xsens_msgs/msg/detail/cam_batch__struct.h"


// Include directives for member types
// Member `stamp`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `data`
#include "xsens_msgs/msg/cam_image.h"
// Member `data`
#include "xsens_msgs/msg/detail/cam_image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CamBatch__rosidl_typesupport_introspection_c__CamBatch_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xsens_msgs__msg__CamBatch__init(message_memory);
}

void CamBatch__rosidl_typesupport_introspection_c__CamBatch_fini_function(void * message_memory)
{
  xsens_msgs__msg__CamBatch__fini(message_memory);
}

size_t CamBatch__rosidl_typesupport_introspection_c__size_function__CamImage__data(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * CamBatch__rosidl_typesupport_introspection_c__get_const_function__CamImage__data(
  const void * untyped_member, size_t index)
{
  const xsens_msgs__msg__CamImage ** member =
    (const xsens_msgs__msg__CamImage **)(untyped_member);
  return &(*member)[index];
}

void * CamBatch__rosidl_typesupport_introspection_c__get_function__CamImage__data(
  void * untyped_member, size_t index)
{
  xsens_msgs__msg__CamImage ** member =
    (xsens_msgs__msg__CamImage **)(untyped_member);
  return &(*member)[index];
}

static rosidl_typesupport_introspection_c__MessageMember CamBatch__rosidl_typesupport_introspection_c__CamBatch_message_member_array[2] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__CamBatch, stamp),  // bytes offset in struct
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
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs__msg__CamBatch, data),  // bytes offset in struct
    NULL,  // default value
    CamBatch__rosidl_typesupport_introspection_c__size_function__CamImage__data,  // size() function pointer
    CamBatch__rosidl_typesupport_introspection_c__get_const_function__CamImage__data,  // get_const(index) function pointer
    CamBatch__rosidl_typesupport_introspection_c__get_function__CamImage__data,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CamBatch__rosidl_typesupport_introspection_c__CamBatch_message_members = {
  "xsens_msgs__msg",  // message namespace
  "CamBatch",  // message name
  2,  // number of fields
  sizeof(xsens_msgs__msg__CamBatch),
  CamBatch__rosidl_typesupport_introspection_c__CamBatch_message_member_array,  // message members
  CamBatch__rosidl_typesupport_introspection_c__CamBatch_init_function,  // function to initialize message memory (memory has to be allocated)
  CamBatch__rosidl_typesupport_introspection_c__CamBatch_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CamBatch__rosidl_typesupport_introspection_c__CamBatch_message_type_support_handle = {
  0,
  &CamBatch__rosidl_typesupport_introspection_c__CamBatch_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xsens_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xsens_msgs, msg, CamBatch)() {
  CamBatch__rosidl_typesupport_introspection_c__CamBatch_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xsens_msgs, msg, CamImage)();
  if (!CamBatch__rosidl_typesupport_introspection_c__CamBatch_message_type_support_handle.typesupport_identifier) {
    CamBatch__rosidl_typesupport_introspection_c__CamBatch_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CamBatch__rosidl_typesupport_introspection_c__CamBatch_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
