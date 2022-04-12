// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_msgs:msg/ConfigNtrip.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/config_ntrip__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_msgs/msg/detail/config_ntrip__struct.h"
#include "xsens_msgs/msg/detail/config_ntrip__functions.h"
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

#include "rosidl_runtime_c/string.h"  // host, mountpoint, password, rtcm_port, username
#include "rosidl_runtime_c/string_functions.h"  // host, mountpoint, password, rtcm_port, username

// forward declare type support functions


using _ConfigNtrip__ros_msg_type = xsens_msgs__msg__ConfigNtrip;

static bool _ConfigNtrip__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ConfigNtrip__ros_msg_type * ros_message = static_cast<const _ConfigNtrip__ros_msg_type *>(untyped_ros_message);
  // Field name: host
  {
    const rosidl_runtime_c__String * str = &ros_message->host;
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

  // Field name: port
  {
    cdr << ros_message->port;
  }

  // Field name: mountpoint
  {
    const rosidl_runtime_c__String * str = &ros_message->mountpoint;
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

  // Field name: username
  {
    const rosidl_runtime_c__String * str = &ros_message->username;
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

  // Field name: password
  {
    const rosidl_runtime_c__String * str = &ros_message->password;
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

  // Field name: rtcm_port
  {
    const rosidl_runtime_c__String * str = &ros_message->rtcm_port;
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

  // Field name: rtcm_baudrate
  {
    cdr << ros_message->rtcm_baudrate;
  }

  // Field name: rtcm_timer
  {
    cdr << ros_message->rtcm_timer;
  }

  return true;
}

static bool _ConfigNtrip__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ConfigNtrip__ros_msg_type * ros_message = static_cast<_ConfigNtrip__ros_msg_type *>(untyped_ros_message);
  // Field name: host
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->host.data) {
      rosidl_runtime_c__String__init(&ros_message->host);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->host,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'host'\n");
      return false;
    }
  }

  // Field name: port
  {
    cdr >> ros_message->port;
  }

  // Field name: mountpoint
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->mountpoint.data) {
      rosidl_runtime_c__String__init(&ros_message->mountpoint);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->mountpoint,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'mountpoint'\n");
      return false;
    }
  }

  // Field name: username
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->username.data) {
      rosidl_runtime_c__String__init(&ros_message->username);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->username,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'username'\n");
      return false;
    }
  }

  // Field name: password
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->password.data) {
      rosidl_runtime_c__String__init(&ros_message->password);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->password,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'password'\n");
      return false;
    }
  }

  // Field name: rtcm_port
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->rtcm_port.data) {
      rosidl_runtime_c__String__init(&ros_message->rtcm_port);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->rtcm_port,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'rtcm_port'\n");
      return false;
    }
  }

  // Field name: rtcm_baudrate
  {
    cdr >> ros_message->rtcm_baudrate;
  }

  // Field name: rtcm_timer
  {
    cdr >> ros_message->rtcm_timer;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t get_serialized_size_xsens_msgs__msg__ConfigNtrip(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ConfigNtrip__ros_msg_type * ros_message = static_cast<const _ConfigNtrip__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name host
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->host.size + 1);
  // field.name port
  {
    size_t item_size = sizeof(ros_message->port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mountpoint
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->mountpoint.size + 1);
  // field.name username
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->username.size + 1);
  // field.name password
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->password.size + 1);
  // field.name rtcm_port
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->rtcm_port.size + 1);
  // field.name rtcm_baudrate
  {
    size_t item_size = sizeof(ros_message->rtcm_baudrate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rtcm_timer
  {
    size_t item_size = sizeof(ros_message->rtcm_timer);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ConfigNtrip__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_msgs__msg__ConfigNtrip(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t max_serialized_size_xsens_msgs__msg__ConfigNtrip(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: host
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: port
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: mountpoint
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: username
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: password
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: rtcm_port
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: rtcm_baudrate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: rtcm_timer
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ConfigNtrip__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_xsens_msgs__msg__ConfigNtrip(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ConfigNtrip = {
  "xsens_msgs::msg",
  "ConfigNtrip",
  _ConfigNtrip__cdr_serialize,
  _ConfigNtrip__cdr_deserialize,
  _ConfigNtrip__get_serialized_size,
  _ConfigNtrip__max_serialized_size
};

static rosidl_message_type_support_t _ConfigNtrip__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ConfigNtrip,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, ConfigNtrip)() {
  return &_ConfigNtrip__type_support;
}

#if defined(__cplusplus)
}
#endif
