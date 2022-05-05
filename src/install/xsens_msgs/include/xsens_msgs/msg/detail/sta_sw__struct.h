// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/StaSW.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_SW__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__STA_SW__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'xsens_status'
// Member 'filter_valid'
// Member 'gnss_fix'
// Member 'clock_sync'
// Member 'sync_in'
// Member 'sync_out'
// Member 'filter_mode'
// Member 'rtk_status'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/StaSW in the package xsens_msgs.
typedef struct xsens_msgs__msg__StaSW
{
  rosidl_runtime_c__String xsens_status;
  rosidl_runtime_c__String filter_valid;
  rosidl_runtime_c__String gnss_fix;
  rosidl_runtime_c__String clock_sync;
  rosidl_runtime_c__String sync_in;
  rosidl_runtime_c__String sync_out;
  rosidl_runtime_c__String filter_mode;
  rosidl_runtime_c__String rtk_status;
} xsens_msgs__msg__StaSW;

// Struct for a sequence of xsens_msgs__msg__StaSW.
typedef struct xsens_msgs__msg__StaSW__Sequence
{
  xsens_msgs__msg__StaSW * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__StaSW__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__STA_SW__STRUCT_H_
