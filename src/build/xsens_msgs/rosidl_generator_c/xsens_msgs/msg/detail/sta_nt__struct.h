// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/StaNT.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_NT__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__STA_NT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ntrip_status'
// Member 'rtcm_status'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/StaNT in the package xsens_msgs.
typedef struct xsens_msgs__msg__StaNT
{
  rosidl_runtime_c__String ntrip_status;
  rosidl_runtime_c__String rtcm_status;
} xsens_msgs__msg__StaNT;

// Struct for a sequence of xsens_msgs__msg__StaNT.
typedef struct xsens_msgs__msg__StaNT__Sequence
{
  xsens_msgs__msg__StaNT * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__StaNT__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__STA_NT__STRUCT_H_
