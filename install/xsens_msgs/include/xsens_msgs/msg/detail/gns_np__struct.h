// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/GnsNP.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__GNS_NP__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__GNS_NP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/GnsNP in the package xsens_msgs.
typedef struct xsens_msgs__msg__GnsNP
{
  rosidl_runtime_c__int32__Sequence stamp;
  int8_t fixtype;
  double lon;
  double lat;
  double height;
  int64_t h_msl;
  int64_t h_acc;
  int64_t v_acc;
  double vel_n;
  double vel_e;
  double vel_d;
  int64_t s_acc;
} xsens_msgs__msg__GnsNP;

// Struct for a sequence of xsens_msgs__msg__GnsNP.
typedef struct xsens_msgs__msg__GnsNP__Sequence
{
  xsens_msgs__msg__GnsNP * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__GnsNP__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__GNS_NP__STRUCT_H_
