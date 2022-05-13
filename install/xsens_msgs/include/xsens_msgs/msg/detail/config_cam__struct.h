// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/ConfigCam.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CONFIG_CAM__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__CONFIG_CAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'save_file'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/ConfigCam in the package xsens_msgs.
typedef struct xsens_msgs__msg__ConfigCam
{
  int32_t height;
  int32_t width;
  int32_t framerate;
  rosidl_runtime_c__String save_file;
  bool stream;
} xsens_msgs__msg__ConfigCam;

// Struct for a sequence of xsens_msgs__msg__ConfigCam.
typedef struct xsens_msgs__msg__ConfigCam__Sequence
{
  xsens_msgs__msg__ConfigCam * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__ConfigCam__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_CAM__STRUCT_H_
