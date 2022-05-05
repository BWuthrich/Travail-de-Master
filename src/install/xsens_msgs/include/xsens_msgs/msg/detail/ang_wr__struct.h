// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/AngWR.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ANG_WR__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__ANG_WR__STRUCT_H_

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

// Struct defined in msg/AngWR in the package xsens_msgs.
typedef struct xsens_msgs__msg__AngWR
{
  rosidl_runtime_c__int32__Sequence stamp;
  double gyrx;
  double gyry;
  double gyrz;
} xsens_msgs__msg__AngWR;

// Struct for a sequence of xsens_msgs__msg__AngWR.
typedef struct xsens_msgs__msg__AngWR__Sequence
{
  xsens_msgs__msg__AngWR * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__AngWR__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__ANG_WR__STRUCT_H_
