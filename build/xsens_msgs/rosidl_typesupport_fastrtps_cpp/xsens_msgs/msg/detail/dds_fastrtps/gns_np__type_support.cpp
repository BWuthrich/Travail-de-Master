// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xsens_msgs:msg/GnsNP.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/gns_np__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xsens_msgs/msg/detail/gns_np__struct.hpp"

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
  const xsens_msgs::msg::GnsNP & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: stamp
  {
    cdr << ros_message.stamp;
  }
  // Member: fixtype
  cdr << ros_message.fixtype;
  // Member: lon
  cdr << ros_message.lon;
  // Member: lat
  cdr << ros_message.lat;
  // Member: height
  cdr << ros_message.height;
  // Member: h_msl
  cdr << ros_message.h_msl;
  // Member: h_acc
  cdr << ros_message.h_acc;
  // Member: v_acc
  cdr << ros_message.v_acc;
  // Member: vel_n
  cdr << ros_message.vel_n;
  // Member: vel_e
  cdr << ros_message.vel_e;
  // Member: vel_d
  cdr << ros_message.vel_d;
  // Member: s_acc
  cdr << ros_message.s_acc;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsens_msgs::msg::GnsNP & ros_message)
{
  // Member: stamp
  {
    cdr >> ros_message.stamp;
  }

  // Member: fixtype
  cdr >> ros_message.fixtype;

  // Member: lon
  cdr >> ros_message.lon;

  // Member: lat
  cdr >> ros_message.lat;

  // Member: height
  cdr >> ros_message.height;

  // Member: h_msl
  cdr >> ros_message.h_msl;

  // Member: h_acc
  cdr >> ros_message.h_acc;

  // Member: v_acc
  cdr >> ros_message.v_acc;

  // Member: vel_n
  cdr >> ros_message.vel_n;

  // Member: vel_e
  cdr >> ros_message.vel_e;

  // Member: vel_d
  cdr >> ros_message.vel_d;

  // Member: s_acc
  cdr >> ros_message.s_acc;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
get_serialized_size(
  const xsens_msgs::msg::GnsNP & ros_message,
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
  // Member: fixtype
  {
    size_t item_size = sizeof(ros_message.fixtype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lon
  {
    size_t item_size = sizeof(ros_message.lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lat
  {
    size_t item_size = sizeof(ros_message.lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: height
  {
    size_t item_size = sizeof(ros_message.height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: h_msl
  {
    size_t item_size = sizeof(ros_message.h_msl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: h_acc
  {
    size_t item_size = sizeof(ros_message.h_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_acc
  {
    size_t item_size = sizeof(ros_message.v_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_n
  {
    size_t item_size = sizeof(ros_message.vel_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_e
  {
    size_t item_size = sizeof(ros_message.vel_e);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_d
  {
    size_t item_size = sizeof(ros_message.vel_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: s_acc
  {
    size_t item_size = sizeof(ros_message.s_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
max_serialized_size_GnsNP(
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

  // Member: fixtype
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: lon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: lat
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: height
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: h_msl
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: h_acc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_acc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel_n
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel_e
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel_d
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: s_acc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _GnsNP__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xsens_msgs::msg::GnsNP *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GnsNP__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xsens_msgs::msg::GnsNP *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GnsNP__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xsens_msgs::msg::GnsNP *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GnsNP__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_GnsNP(full_bounded, 0);
}

static message_type_support_callbacks_t _GnsNP__callbacks = {
  "xsens_msgs::msg",
  "GnsNP",
  _GnsNP__cdr_serialize,
  _GnsNP__cdr_deserialize,
  _GnsNP__get_serialized_size,
  _GnsNP__max_serialized_size
};

static rosidl_message_type_support_t _GnsNP__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GnsNP__callbacks,
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
get_message_type_support_handle<xsens_msgs::msg::GnsNP>()
{
  return &xsens_msgs::msg::typesupport_fastrtps_cpp::_GnsNP__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_msgs, msg, GnsNP)() {
  return &xsens_msgs::msg::typesupport_fastrtps_cpp::_GnsNP__handle;
}

#ifdef __cplusplus
}
#endif
