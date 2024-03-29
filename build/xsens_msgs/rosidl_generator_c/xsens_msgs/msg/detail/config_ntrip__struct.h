// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/ConfigNtrip.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CONFIG_NTRIP__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__CONFIG_NTRIP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'host'
// Member 'mountpoint'
// Member 'username'
// Member 'password'
// Member 'rtcm_port'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/ConfigNtrip in the package xsens_msgs.
typedef struct xsens_msgs__msg__ConfigNtrip
{
  rosidl_runtime_c__String host;
  int16_t port;
  rosidl_runtime_c__String mountpoint;
  rosidl_runtime_c__String username;
  rosidl_runtime_c__String password;
  rosidl_runtime_c__String rtcm_port;
  uint64_t rtcm_baudrate;
  float rtcm_timer;
} xsens_msgs__msg__ConfigNtrip;

// Struct for a sequence of xsens_msgs__msg__ConfigNtrip.
typedef struct xsens_msgs__msg__ConfigNtrip__Sequence
{
  xsens_msgs__msg__ConfigNtrip * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__ConfigNtrip__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_NTRIP__STRUCT_H_
