// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xsens_msgs:msg/CamBatch.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/cam_batch__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xsens_msgs/msg/detail/cam_batch__struct.hpp"

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
bool cdr_serialize(
  const xsens_msgs::msg::CamImage &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  xsens_msgs::msg::CamImage &);
size_t get_serialized_size(
  const xsens_msgs::msg::CamImage &,
  size_t current_alignment);
size_t
max_serialized_size_CamImage(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace xsens_msgs


namespace xsens_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_serialize(
  const xsens_msgs::msg::CamBatch & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: stamp
  {
    cdr << ros_message.stamp;
  }
  // Member: data
  {
    for (size_t i = 0; i < 4; i++) {
      xsens_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.data[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsens_msgs::msg::CamBatch & ros_message)
{
  // Member: stamp
  {
    cdr >> ros_message.stamp;
  }

  // Member: data
  {
    for (size_t i = 0; i < 4; i++) {
      xsens_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr,
        ros_message.data[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
get_serialized_size(
  const xsens_msgs::msg::CamBatch & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: stamp
  {
    size_t array_size = ros_message.stamp.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.stamp[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: data
  {
    size_t array_size = 4;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        xsens_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.data[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
max_serialized_size_CamBatch(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: stamp
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: data
  {
    size_t array_size = 4;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        xsens_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_CamImage(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _CamBatch__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xsens_msgs::msg::CamBatch *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CamBatch__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xsens_msgs::msg::CamBatch *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CamBatch__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xsens_msgs::msg::CamBatch *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CamBatch__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_CamBatch(full_bounded, 0);
}

static message_type_support_callbacks_t _CamBatch__callbacks = {
  "xsens_msgs::msg",
  "CamBatch",
  _CamBatch__cdr_serialize,
  _CamBatch__cdr_deserialize,
  _CamBatch__get_serialized_size,
  _CamBatch__max_serialized_size
};

static rosidl_message_type_support_t _CamBatch__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CamBatch__callbacks,
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
get_message_type_support_handle<xsens_msgs::msg::CamBatch>()
{
  return &xsens_msgs::msg::typesupport_fastrtps_cpp::_CamBatch__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_msgs, msg, CamBatch)() {
  return &xsens_msgs::msg::typesupport_fastrtps_cpp::_CamBatch__handle;
}

#ifdef __cplusplus
}
#endif
