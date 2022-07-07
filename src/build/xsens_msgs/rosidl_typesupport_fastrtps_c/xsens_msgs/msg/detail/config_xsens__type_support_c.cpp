// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_msgs:msg/ConfigXsens.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/config_xsens__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_msgs/msg/detail/config_xsens__struct.h"
#include "xsens_msgs/msg/detail/config_xsens__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // sync_config
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // sync_config
#include "rosidl_runtime_c/string.h"  // output_config, port_name
#include "rosidl_runtime_c/string_functions.h"  // output_config, port_name

// forward declare type support functions


using _ConfigXsens__ros_msg_type = xsens_msgs__msg__ConfigXsens;

static bool _ConfigXsens__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ConfigXsens__ros_msg_type * ros_message = static_cast<const _ConfigXsens__ros_msg_type *>(untyped_ros_message);
  // Field name: output_config
  {
    const rosidl_runtime_c__String * str = &ros_message->output_config;
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

  // Field name: baudrate
  {
    cdr << ros_message->baudrate;
  }

  // Field name: port_name
  {
    const rosidl_runtime_c__String * str = &ros_message->port_name;
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

  // Field name: rtcm_refresh_dist
  {
    cdr << ros_message->rtcm_refresh_dist;
  }

  // Field name: sync_config
  {
    size_t size = ros_message->sync_config.size;
    auto array_ptr = ros_message->sync_config.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: dt_freq
  {
    cdr << ros_message->dt_freq;
  }

  return true;
}

static bool _ConfigXsens__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ConfigXsens__ros_msg_type * ros_message = static_cast<_ConfigXsens__ros_msg_type *>(untyped_ros_message);
  // Field name: output_config
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->output_config.data) {
      rosidl_runtime_c__String__init(&ros_message->output_config);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->output_config,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'output_config'\n");
      return false;
    }
  }

  // Field name: baudrate
  {
    cdr >> ros_message->baudrate;
  }

  // Field name: port_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->port_name.data) {
      rosidl_runtime_c__String__init(&ros_message->port_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->port_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'port_name'\n");
      return false;
    }
  }

  // Field name: rtcm_refresh_dist
  {
    cdr >> ros_message->rtcm_refresh_dist;
  }

  // Field name: sync_config
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->sync_config.data) {
      rosidl_runtime_c__uint32__Sequence__fini(&ros_message->sync_config);
    }
    if (!rosidl_runtime_c__uint32__Sequence__init(&ros_message->sync_config, size)) {
      return "failed to create array for field 'sync_config'";
    }
    auto array_ptr = ros_message->sync_config.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: dt_freq
  {
    cdr >> ros_message->dt_freq;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t get_serialized_size_xsens_msgs__msg__ConfigXsens(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ConfigXsens__ros_msg_type * ros_message = static_cast<const _ConfigXsens__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name output_config
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->output_config.size + 1);
  // field.name baudrate
  {
    size_t item_size = sizeof(ros_message->baudrate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name port_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->port_name.size + 1);
  // field.name rtcm_refresh_dist
  {
    size_t item_size = sizeof(ros_message->rtcm_refresh_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sync_config
  {
    size_t array_size = ros_message->sync_config.size;
    auto array_ptr = ros_message->sync_config.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dt_freq
  {
    size_t item_size = sizeof(ros_message->dt_freq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ConfigXsens__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_msgs__msg__ConfigXsens(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t max_serialized_size_xsens_msgs__msg__ConfigXsens(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: output_config
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: baudrate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: port_name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: rtcm_refresh_dist
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: sync_config
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: dt_freq
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ConfigXsens__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_xsens_msgs__msg__ConfigXsens(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ConfigXsens = {
  "xsens_msgs::msg",
  "ConfigXsens",
  _ConfigXsens__cdr_serialize,
  _ConfigXsens__cdr_deserialize,
  _ConfigXsens__get_serialized_size,
  _ConfigXsens__max_serialized_size
};

static rosidl_message_type_support_t _ConfigXsens__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ConfigXsens,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, ConfigXsens)() {
  return &_ConfigXsens__type_support;
}

#if defined(__cplusplus)
}
#endif