// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_msgs:srv/RTCMdata.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__SRV__DETAIL__RTC_MDATA__STRUCT_H_
#define XSENS_MSGS__SRV__DETAIL__RTC_MDATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/RTCMdata in the package xsens_msgs.
typedef struct xsens_msgs__srv__RTCMdata_Request
{
  double longitude;
  double latitude;
  double alti_ell;
} xsens_msgs__srv__RTCMdata_Request;

// Struct for a sequence of xsens_msgs__srv__RTCMdata_Request.
typedef struct xsens_msgs__srv__RTCMdata_Request__Sequence
{
  xsens_msgs__srv__RTCMdata_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__srv__RTCMdata_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/RTCMdata in the package xsens_msgs.
typedef struct xsens_msgs__srv__RTCMdata_Response
{
  uint8_t structure_needs_at_least_one_member;
} xsens_msgs__srv__RTCMdata_Response;

// Struct for a sequence of xsens_msgs__srv__RTCMdata_Response.
typedef struct xsens_msgs__srv__RTCMdata_Response__Sequence
{
  xsens_msgs__srv__RTCMdata_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_msgs__srv__RTCMdata_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__SRV__DETAIL__RTC_MDATA__STRUCT_H_
