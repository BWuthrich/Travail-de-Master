// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/CamImage.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CAM_IMAGE__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__CAM_IMAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in msg/CamImage in the package xsens_msgs.
typedef struct xsens_msgs__msg__CamImage
{
  int8_t cam_id;
  double stamp;
  sensor_msgs__msg__Image data;
} xsens_msgs__msg__CamImage;

// Struct for a sequence of xsens_msgs__msg__CamImage.
typedef struct xsens_msgs__msg__CamImage__Sequence
{
  xsens_msgs__msg__CamImage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__CamImage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__CAM_IMAGE__STRUCT_H_
