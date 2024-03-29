// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xsens_msgs:srv/RTCMdata.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/srv/detail/rtc_mdata__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xsens_msgs/srv/detail/rtc_mdata__struct.hpp"

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_serialize(
  const xsens_msgs::srv::RTCMdata_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: longitude
  cdr << ros_message.longitude;
  // Member: latitude
  cdr << ros_message.latitude;
  // Member: alti_ell
  cdr << ros_message.alti_ell;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsens_msgs::srv::RTCMdata_Request & ros_message)
{
  // Member: longitude
  cdr >> ros_message.longitude;

  // Member: latitude
  cdr >> ros_message.latitude;

  // Member: alti_ell
  cdr >> ros_message.alti_ell;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
get_serialized_size(
  const xsens_msgs::srv::RTCMdata_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: longitude
  {
    size_t item_size = sizeof(ros_message.longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: latitude
  {
    size_t item_size = sizeof(ros_message.latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: alti_ell
  {
    size_t item_size = sizeof(ros_message.alti_ell);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
max_serialized_size_RTCMdata_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: longitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: latitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: alti_ell
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _RTCMdata_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xsens_msgs::srv::RTCMdata_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RTCMdata_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xsens_msgs::srv::RTCMdata_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RTCMdata_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xsens_msgs::srv::RTCMdata_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RTCMdata_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RTCMdata_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _RTCMdata_Request__callbacks = {
  "xsens_msgs::srv",
  "RTCMdata_Request",
  _RTCMdata_Request__cdr_serialize,
  _RTCMdata_Request__cdr_deserialize,
  _RTCMdata_Request__get_serialized_size,
  _RTCMdata_Request__max_serialized_size
};

static rosidl_message_type_support_t _RTCMdata_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RTCMdata_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace xsens_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xsens_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<xsens_msgs::srv::RTCMdata_Request>()
{
  return &xsens_msgs::srv::typesupport_fastrtps_cpp::_RTCMdata_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_msgs, srv, RTCMdata_Request)() {
  return &xsens_msgs::srv::typesupport_fastrtps_cpp::_RTCMdata_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace xsens_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_serialize(
  const xsens_msgs::srv::RTCMdata_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsens_msgs::srv::RTCMdata_Response & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
get_serialized_size(
  const xsens_msgs::srv::RTCMdata_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_msgs
max_serialized_size_RTCMdata_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _RTCMdata_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xsens_msgs::srv::RTCMdata_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RTCMdata_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xsens_msgs::srv::RTCMdata_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RTCMdata_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xsens_msgs::srv::RTCMdata_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RTCMdata_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RTCMdata_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _RTCMdata_Response__callbacks = {
  "xsens_msgs::srv",
  "RTCMdata_Response",
  _RTCMdata_Response__cdr_serialize,
  _RTCMdata_Response__cdr_deserialize,
  _RTCMdata_Response__get_serialized_size,
  _RTCMdata_Response__max_serialized_size
};

static rosidl_message_type_support_t _RTCMdata_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RTCMdata_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace xsens_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xsens_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<xsens_msgs::srv::RTCMdata_Response>()
{
  return &xsens_msgs::srv::typesupport_fastrtps_cpp::_RTCMdata_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_msgs, srv, RTCMdata_Response)() {
  return &xsens_msgs::srv::typesupport_fastrtps_cpp::_RTCMdata_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace xsens_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _RTCMdata__callbacks = {
  "xsens_msgs::srv",
  "RTCMdata",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_msgs, srv, RTCMdata_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_msgs, srv, RTCMdata_Response)(),
};

static rosidl_service_type_support_t _RTCMdata__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RTCMdata__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace xsens_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xsens_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<xsens_msgs::srv::RTCMdata>()
{
  return &xsens_msgs::srv::typesupport_fastrtps_cpp::_RTCMdata__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_msgs, srv, RTCMdata)() {
  return &xsens_msgs::srv::typesupport_fastrtps_cpp::_RTCMdata__handle;
}

#ifdef __cplusplus
}
#endif
