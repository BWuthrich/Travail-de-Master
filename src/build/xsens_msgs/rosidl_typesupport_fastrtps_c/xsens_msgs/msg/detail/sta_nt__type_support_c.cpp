// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_msgs:msg/StaNT.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/sta_nt__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_msgs/msg/detail/sta_nt__struct.h"
#include "xsens_msgs/msg/detail/sta_nt__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // ntrip_status, rtcm_status
#include "rosidl_runtime_c/string_functions.h"  // ntrip_status, rtcm_status

// forward declare type support functions


using _StaNT__ros_msg_type = xsens_msgs__msg__StaNT;

static bool _StaNT__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StaNT__ros_msg_type * ros_message = static_cast<const _StaNT__ros_msg_type *>(untyped_ros_message);
  // Field name: ntrip_status
  {
    const rosidl_runtime_c__String * str = &ros_message->ntrip_status;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: rtcm_status
  {
    const rosidl_runtime_c__String * str = &ros_message->rtcm_status;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _StaNT__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StaNT__ros_msg_type * ros_message = static_cast<_StaNT__ros_msg_type *>(untyped_ros_message);
  // Field name: ntrip_status
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->ntrip_status.data) {
      rosidl_runtime_c__String__init(&ros_message->ntrip_status);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->ntrip_status,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'ntrip_status'\n");
      return false;
    }
  }

  // Field name: rtcm_status
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->rtcm_status.data) {
      rosidl_runtime_c__String__init(&ros_message->rtcm_status);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->rtcm_status,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'rtcm_status'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t get_serialized_size_xsens_msgs__msg__StaNT(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StaNT__ros_msg_type * ros_message = static_cast<const _StaNT__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ntrip_status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ntrip_status.size + 1);
  // field.name rtcm_status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->rtcm_status.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _StaNT__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_msgs__msg__StaNT(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t max_serialized_size_xsens_msgs__msg__StaNT(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: ntrip_status
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: rtcm_status
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _StaNT__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_xsens_msgs__msg__StaNT(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_StaNT = {
  "xsens_msgs::msg",
  "StaNT",
  _StaNT__cdr_serialize,
  _StaNT__cdr_deserialize,
  _StaNT__get_serialized_size,
  _StaNT__max_serialized_size
};

static rosidl_message_type_support_t _StaNT__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StaNT,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, StaNT)() {
  return &_StaNT__type_support;
}

#if defined(__cplusplus)
}
#endif
