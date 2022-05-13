// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:msg/CamBatch.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CAM_BATCH__STRUCT_H_
#define XSENS_MSGS__MSG__DETAIL__CAM_BATCH__STRUCT_H_

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
// Member 'data'
#include "xsens_msgs/msg/detail/cam_image__struct.h"

// Struct defined in msg/CamBatch in the package xsens_msgs.
typedef struct xsens_msgs__msg__CamBatch
{
  rosidl_runtime_c__int32__Sequence stamp;
  xsens_msgs__msg__CamImage data[4];
} xsens_msgs__msg__CamBatch;

// Struct for a sequence of xsens_msgs__msg__CamBatch.
typedef struct xsens_msgs__msg__CamBatch__Sequence
{
  xsens_msgs__msg__CamBatch * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__msg__CamBatch__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__CAM_BATCH__STRUCT_H_
