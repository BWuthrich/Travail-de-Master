// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_msgs:msg/AngWR.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/ang_wr__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_msgs/msg/detail/ang_wr__struct.h"
#include "xsens_msgs/msg/detail/ang_wr__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // stamp
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // stamp

// forward declare type support functions


using _AngWR__ros_msg_type = xsens_msgs__msg__AngWR;

static bool _AngWR__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AngWR__ros_msg_type * ros_message = static_cast<const _AngWR__ros_msg_type *>(untyped_ros_message);
  // Field name: stamp
  {
    size_t size = ros_message->stamp.size;
    auto array_ptr = ros_message->stamp.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: gyrx
  {
    cdr << ros_message->gyrx;
  }

  // Field name: gyry
  {
    cdr << ros_message->gyry;
  }

  // Field name: gyrz
  {
    cdr << ros_message->gyrz;
  }

  return true;
}

static bool _AngWR__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AngWR__ros_msg_type * ros_message = static_cast<_AngWR__ros_msg_type *>(untyped_ros_message);
  // Field name: stamp
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->stamp.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->stamp);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->stamp, size)) {
      return "failed to create array for field 'stamp'";
    }
    auto array_ptr = ros_message->stamp.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: gyrx
  {
    cdr >> ros_message->gyrx;
  }

  // Field name: gyry
  {
    cdr >> ros_message->gyry;
  }

  // Field name: gyrz
  {
    cdr >> ros_message->gyrz;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t get_serialized_size_xsens_msgs__msg__AngWR(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AngWR__ros_msg_type * ros_message = static_cast<const _AngWR__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name stamp
  {
    size_t array_size = ros_message->stamp.size;
    auto array_ptr = ros_message->stamp.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyrx
  {
    size_t item_size = sizeof(ros_message->gyrx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyry
  {
    size_t item_size = sizeof(ros_message->gyry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyrz
  {
    size_t item_size = sizeof(ros_message->gyrz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AngWR__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_msgs__msg__AngWR(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t max_serialized_size_xsens_msgs__msg__AngWR(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: stamp
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gyrx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gyry
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gyrz
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _AngWR__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_xsens_msgs__msg__AngWR(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_AngWR = {
  "xsens_msgs::msg",
  "AngWR",
  _AngWR__cdr_serialize,
  _AngWR__cdr_deserialize,
  _AngWR__get_serialized_size,
  _AngWR__max_serialized_size
};

static rosidl_message_type_support_t _AngWR__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AngWR,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, AngWR)() {
  return &_AngWR__type_support;
}

#if defined(__cplusplus)
}
#endif
