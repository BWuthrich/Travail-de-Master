// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xsens_msgs:msg/ConfigCam.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/config_cam__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xsens_msgs/msg/detail/config_cam__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace xsens_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_serialize(
  const xsens_msgs::msg::ConfigCam & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: height
  cdr << ros_message.height;
  // Member: width
  cdr << ros_message.width;
  // Member: framerate
  cdr << ros_message.framerate;
  // Member: save_file
  cdr << ros_message.save_file;
  // Member: stream
  cdr << (ros_message.stream ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsens_msgs::msg::ConfigCam & ros_message)
{
  // Member: height
  cdr >> ros_message.height;

  // Member: width
  cdr >> ros_message.width;

  // Member: framerate
  cdr >> ros_message.framerate;

  // Member: save_file
  cdr >> ros_message.save_file;

  // Member: stream
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.stream = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
get_serialized_size(
  const xsens_msgs::msg::ConfigCam & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: height
  {
    size_t item_size = sizeof(ros_message.height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: width
  {
    size_t item_size = sizeof(ros_message.width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: framerate
  {
    size_t item_size = sizeof(ros_message.framerate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: save_file
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.save_file.size() + 1);
  // Member: stream
  {
    size_t item_size = sizeof(ros_message.stream);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
max_serialized_size_ConfigCam(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: height
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: width
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: framerate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: save_file
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: stream
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _ConfigCam__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xsens_msgs::msg::ConfigCam *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ConfigCam__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xsens_msgs::msg::ConfigCam *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ConfigCam__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xsens_msgs::msg::ConfigCam *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ConfigCam__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ConfigCam(full_bounded, 0);
}

static message_type_support_callbacks_t _ConfigCam__callbacks = {
  "xsens_msgs::msg",
  "ConfigCam",
  _ConfigCam__cdr_serialize,
  _ConfigCam__cdr_deserialize,
  _ConfigCam__get_serialized_size,
  _ConfigCam__max_serialized_size
};

static rosidl_message_type_support_t _ConfigCam__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ConfigCam__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xsens_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xsens_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<xsens_msgs::msg::ConfigCam>()
{
  return &xsens_msgs::msg::typesupport_fastrtps_cpp::_ConfigCam__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_msgs, msg, ConfigCam)() {
  return &xsens_msgs::msg::typesupport_fastrtps_cpp::_ConfigCam__handle;
}

#ifdef __cplusplus
}
#endif