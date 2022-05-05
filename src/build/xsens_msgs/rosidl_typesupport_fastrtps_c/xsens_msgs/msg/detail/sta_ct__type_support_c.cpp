// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_msgs:msg/StaCT.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/sta_ct__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_msgs/msg/detail/sta_ct__struct.h"
#include "xsens_msgs/msg/detail/sta_ct__functions.h"
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

#include "rosidl_runtime_c/string.h"  // cam_status
#include "rosidl_runtime_c/string_functions.h"  // cam_status

// forward declare type support functions


using _StaCT__ros_msg_type = xsens_msgs__msg__StaCT;

static bool _StaCT__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StaCT__ros_msg_type * ros_message = static_cast<const _StaCT__ros_msg_type *>(untyped_ros_message);
  // Field name: cam_status
  {
    const rosidl_runtime_c__String * str = &ros_message->cam_status;
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

static bool _StaCT__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StaCT__ros_msg_type * ros_message = static_cast<_StaCT__ros_msg_type *>(untyped_ros_message);
  // Field name: cam_status
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->cam_status.data) {
      rosidl_runtime_c__String__init(&ros_message->cam_status);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->cam_status,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'cam_status'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t get_serialized_size_xsens_msgs__msg__StaCT(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StaCT__ros_msg_type * ros_message = static_cast<const _StaCT__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name cam_status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->cam_status.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _StaCT__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_msgs__msg__StaCT(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t max_serialized_size_xsens_msgs__msg__StaCT(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: cam_status
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

static size_t _StaCT__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_xsens_msgs__msg__StaCT(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_StaCT = {
  "xsens_msgs::msg",
  "StaCT",
  _StaCT__cdr_serialize,
  _StaCT__cdr_deserialize,
  _StaCT__get_serialized_size,
  _StaCT__max_serialized_size
};

static rosidl_message_type_support_t _StaCT__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StaCT,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, StaCT)() {
  return &_StaCT__type_support;
}

#if defined(__cplusplus)
}
#endif
