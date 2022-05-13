// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xsens_msgs:msg/TrgSP.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/trg_sp__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xsens_msgs/msg/detail/trg_sp__struct.hpp"

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
  const xsens_msgs::msg::TrgSP & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: stamp
  {
    cdr << ros_message.stamp;
  }
  // Member: trig_counter
  cdr << ros_message.trig_counter;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsens_msgs::msg::TrgSP & ros_message)
{
  // Member: stamp
  {
    cdr >> ros_message.stamp;
  }

  // Member: trig_counter
  cdr >> ros_message.trig_counter;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
get_serialized_size(
  const xsens_msgs::msg::TrgSP & ros_message,
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
  // Member: trig_counter
  {
    size_t item_size = sizeof(ros_message.trig_counter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
max_serialized_size_TrgSP(
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

  // Member: trig_counter
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _TrgSP__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xsens_msgs::msg::TrgSP *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TrgSP__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xsens_msgs::msg::TrgSP *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TrgSP__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xsens_msgs::msg::TrgSP *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TrgSP__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_TrgSP(full_bounded, 0);
}

static message_type_support_callbacks_t _TrgSP__callbacks = {
  "xsens_msgs::msg",
  "TrgSP",
  _TrgSP__cdr_serialize,
  _TrgSP__cdr_deserialize,
  _TrgSP__get_serialized_size,
  _TrgSP__max_serialized_size
};

static rosidl_message_type_support_t _TrgSP__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TrgSP__callbacks,
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
get_message_type_support_handle<xsens_msgs::msg::TrgSP>()
{
  return &xsens_msgs::msg::typesupport_fastrtps_cpp::_TrgSP__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_msgs, msg, TrgSP)() {
  return &xsens_msgs::msg::typesupport_fastrtps_cpp::_TrgSP__handle;
}

#ifdef __cplusplus
}
#endif
