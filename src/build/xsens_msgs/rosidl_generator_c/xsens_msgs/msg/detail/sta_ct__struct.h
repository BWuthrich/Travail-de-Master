// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/StaCT.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_CT__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__STA_CT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cam_status'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/StaCT in the package xsens_msgs.
typedef struct xsens_msgs__msg__StaCT
{
  rosidl_runtime_c__String cam_status;
} xsens_msgs__msg__StaCT;

// Struct for a sequence of xsens_msgs__msg__StaCT.
typedef struct xsens_msgs__msg__StaCT__Sequence
{
  xsens_msgs__msg__StaCT * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__StaCT__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__STA_CT__STRUCT_H_
