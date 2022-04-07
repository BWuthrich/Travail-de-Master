// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_msgs:msg/StaSW.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/sta_sw__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_msgs/msg/detail/sta_sw__struct.h"
#include "xsens_msgs/msg/detail/sta_sw__functions.h"
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

#include "rosidl_runtime_c/string.h"  // clock_sync, filter_mode, filter_valid, gnss_fix, rtk_status, sync_in, sync_out, xsens_status
#include "rosidl_runtime_c/string_functions.h"  // clock_sync, filter_mode, filter_valid, gnss_fix, rtk_status, sync_in, sync_out, xsens_status

// forward declare type support functions


using _StaSW__ros_msg_type = xsens_msgs__msg__StaSW;

static bool _StaSW__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StaSW__ros_msg_type * ros_message = static_cast<const _StaSW__ros_msg_type *>(untyped_ros_message);
  // Field name: xsens_status
  {
    const rosidl_runtime_c__String * str = &ros_message->xsens_status;
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

  // Field name: filter_valid
  {
    const rosidl_runtime_c__String * str = &ros_message->filter_valid;
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

  // Field name: gnss_fix
  {
    const rosidl_runtime_c__String * str = &ros_message->gnss_fix;
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

  // Field name: clock_sync
  {
    const rosidl_runtime_c__String * str = &ros_message->clock_sync;
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

  // Field name: sync_in
  {
    const rosidl_runtime_c__String * str = &ros_message->sync_in;
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

  // Field name: sync_out
  {
    const rosidl_runtime_c__String * str = &ros_message->sync_out;
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

  // Field name: filter_mode
  {
    const rosidl_runtime_c__String * str = &ros_message->filter_mode;
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

  // Field name: rtk_status
  {
    const rosidl_runtime_c__String * str = &ros_message->rtk_status;
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

static bool _StaSW__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StaSW__ros_msg_type * ros_message = static_cast<_StaSW__ros_msg_type *>(untyped_ros_message);
  // Field name: xsens_status
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->xsens_status.data) {
      rosidl_runtime_c__String__init(&ros_message->xsens_status);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->xsens_status,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'xsens_status'\n");
      return false;
    }
  }

  // Field name: filter_valid
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->filter_valid.data) {
      rosidl_runtime_c__String__init(&ros_message->filter_valid);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->filter_valid,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'filter_valid'\n");
      return false;
    }
  }

  // Field name: gnss_fix
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->gnss_fix.data) {
      rosidl_runtime_c__String__init(&ros_message->gnss_fix);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->gnss_fix,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'gnss_fix'\n");
      return false;
    }
  }

  // Field name: clock_sync
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->clock_sync.data) {
      rosidl_runtime_c__String__init(&ros_message->clock_sync);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->clock_sync,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'clock_sync'\n");
      return false;
    }
  }

  // Field name: sync_in
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->sync_in.data) {
      rosidl_runtime_c__String__init(&ros_message->sync_in);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->sync_in,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'sync_in'\n");
      return false;
    }
  }

  // Field name: sync_out
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->sync_out.data) {
      rosidl_runtime_c__String__init(&ros_message->sync_out);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->sync_out,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'sync_out'\n");
      return false;
    }
  }

  // Field name: filter_mode
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->filter_mode.data) {
      rosidl_runtime_c__String__init(&ros_message->filter_mode);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->filter_mode,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'filter_mode'\n");
      return false;
    }
  }

  // Field name: rtk_status
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->rtk_status.data) {
      rosidl_runtime_c__String__init(&ros_message->rtk_status);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->rtk_status,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'rtk_status'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t get_serialized_size_xsens_msgs__msg__StaSW(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StaSW__ros_msg_type * ros_message = static_cast<const _StaSW__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name xsens_status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->xsens_status.size + 1);
  // field.name filter_valid
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->filter_valid.size + 1);
  // field.name gnss_fix
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->gnss_fix.size + 1);
  // field.name clock_sync
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->clock_sync.size + 1);
  // field.name sync_in
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->sync_in.size + 1);
  // field.name sync_out
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->sync_out.size + 1);
  // field.name filter_mode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->filter_mode.size + 1);
  // field.name rtk_status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->rtk_status.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _StaSW__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_msgs__msg__StaSW(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t max_serialized_size_xsens_msgs__msg__StaSW(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: xsens_status
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: filter_valid
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: gnss_fix
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: clock_sync
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: sync_in
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: sync_out
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: filter_mode
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: rtk_status
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

static size_t _StaSW__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_xsens_msgs__msg__StaSW(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_StaSW = {
  "xsens_msgs::msg",
  "StaSW",
  _StaSW__cdr_serialize,
  _StaSW__cdr_deserialize,
  _StaSW__get_serialized_size,
  _StaSW__max_serialized_size
};

static rosidl_message_type_support_t _StaSW__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StaSW,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, StaSW)() {
  return &_StaSW__type_support;
}

#if defined(__cplusplus)
}
#endif
