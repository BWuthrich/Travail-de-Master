// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/ConfigXsens.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'configuration'
// Member 'port_name'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/ConfigXsens in the package xsens_msgs.
typedef struct xsens_msgs__msg__ConfigXsens
{
  rosidl_runtime_c__String configuration;
  uint32_t baudrate;
  rosidl_runtime_c__String port_name;
  uint16_t rtcm_refresh_dist;
} xsens_msgs__msg__ConfigXsens;

// Struct for a sequence of xsens_msgs__msg__ConfigXsens.
typedef struct xsens_msgs__msg__ConfigXsens__Sequence
{
  xsens_msgs__msg__ConfigXsens * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__ConfigXsens__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__STRUCT_H_
