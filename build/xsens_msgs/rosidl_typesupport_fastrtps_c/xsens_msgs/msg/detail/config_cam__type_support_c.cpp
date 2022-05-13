// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_msgs:msg/ConfigCam.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/config_cam__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_msgs/msg/detail/config_cam__struct.h"
#include "xsens_msgs/msg/detail/config_cam__functions.h"
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

#include "rosidl_runtime_c/string.h"  // save_file
#include "rosidl_runtime_c/string_functions.h"  // save_file

// forward declare type support functions


using _ConfigCam__ros_msg_type = xsens_msgs__msg__ConfigCam;

static bool _ConfigCam__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ConfigCam__ros_msg_type * ros_message = static_cast<const _ConfigCam__ros_msg_type *>(untyped_ros_message);
  // Field name: height
  {
    cdr << ros_message->height;
  }

  // Field name: width
  {
    cdr << ros_message->width;
  }

  // Field name: framerate
  {
    cdr << ros_message->framerate;
  }

  // Field name: save_file
  {
    const rosidl_runtime_c__String * str = &ros_message->save_file;
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

  // Field name: stream
  {
    cdr << (ros_message->stream ? true : false);
  }

  return true;
}

static bool _ConfigCam__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ConfigCam__ros_msg_type * ros_message = static_cast<_ConfigCam__ros_msg_type *>(untyped_ros_message);
  // Field name: height
  {
    cdr >> ros_message->height;
  }

  // Field name: width
  {
    cdr >> ros_message->width;
  }

  // Field name: framerate
  {
    cdr >> ros_message->framerate;
  }

  // Field name: save_file
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->save_file.data) {
      rosidl_runtime_c__String__init(&ros_message->save_file);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->save_file,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'save_file'\n");
      return false;
    }
  }

  // Field name: stream
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->stream = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t get_serialized_size_xsens_msgs__msg__ConfigCam(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ConfigCam__ros_msg_type * ros_message = static_cast<const _ConfigCam__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name height
  {
    size_t item_size = sizeof(ros_message->height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name width
  {
    size_t item_size = sizeof(ros_message->width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name framerate
  {
    size_t item_size = sizeof(ros_message->framerate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name save_file
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->save_file.size + 1);
  // field.name stream
  {
    size_t item_size = sizeof(ros_message->stream);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ConfigCam__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_msgs__msg__ConfigCam(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t max_serialized_size_xsens_msgs__msg__ConfigCam(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: height
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: width
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: framerate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: save_file
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: stream
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _ConfigCam__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_xsens_msgs__msg__ConfigCam(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ConfigCam = {
  "xsens_msgs::msg",
  "ConfigCam",
  _ConfigCam__cdr_serialize,
  _ConfigCam__cdr_deserialize,
  _ConfigCam__get_serialized_size,
  _ConfigCam__max_serialized_size
};

static rosidl_message_type_support_t _ConfigCam__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ConfigCam,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, ConfigCam)() {
  return &_ConfigCam__type_support;
}

#if defined(__cplusplus)
}
#endif
