// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_msgs:msg/GnsNP.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/gns_np__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_msgs/msg/detail/gns_np__struct.h"
#include "xsens_msgs/msg/detail/gns_np__functions.h"
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


using _GnsNP__ros_msg_type = xsens_msgs__msg__GnsNP;

static bool _GnsNP__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GnsNP__ros_msg_type * ros_message = static_cast<const _GnsNP__ros_msg_type *>(untyped_ros_message);
  // Field name: stamp
  {
    size_t size = ros_message->stamp.size;
    auto array_ptr = ros_message->stamp.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: fixtype
  {
    cdr << ros_message->fixtype;
  }

  // Field name: lon
  {
    cdr << ros_message->lon;
  }

  // Field name: lat
  {
    cdr << ros_message->lat;
  }

  // Field name: height
  {
    cdr << ros_message->height;
  }

  // Field name: h_msl
  {
    cdr << ros_message->h_msl;
  }

  // Field name: h_acc
  {
    cdr << ros_message->h_acc;
  }

  // Field name: v_acc
  {
    cdr << ros_message->v_acc;
  }

  // Field name: vel_n
  {
    cdr << ros_message->vel_n;
  }

  // Field name: vel_e
  {
    cdr << ros_message->vel_e;
  }

  // Field name: vel_d
  {
    cdr << ros_message->vel_d;
  }

  // Field name: s_acc
  {
    cdr << ros_message->s_acc;
  }

  return true;
}

static bool _GnsNP__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GnsNP__ros_msg_type * ros_message = static_cast<_GnsNP__ros_msg_type *>(untyped_ros_message);
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

  // Field name: fixtype
  {
    cdr >> ros_message->fixtype;
  }

  // Field name: lon
  {
    cdr >> ros_message->lon;
  }

  // Field name: lat
  {
    cdr >> ros_message->lat;
  }

  // Field name: height
  {
    cdr >> ros_message->height;
  }

  // Field name: h_msl
  {
    cdr >> ros_message->h_msl;
  }

  // Field name: h_acc
  {
    cdr >> ros_message->h_acc;
  }

  // Field name: v_acc
  {
    cdr >> ros_message->v_acc;
  }

  // Field name: vel_n
  {
    cdr >> ros_message->vel_n;
  }

  // Field name: vel_e
  {
    cdr >> ros_message->vel_e;
  }

  // Field name: vel_d
  {
    cdr >> ros_message->vel_d;
  }

  // Field name: s_acc
  {
    cdr >> ros_message->s_acc;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t get_serialized_size_xsens_msgs__msg__GnsNP(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GnsNP__ros_msg_type * ros_message = static_cast<const _GnsNP__ros_msg_type *>(untyped_ros_message);
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
  // field.name fixtype
  {
    size_t item_size = sizeof(ros_message->fixtype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lon
  {
    size_t item_size = sizeof(ros_message->lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lat
  {
    size_t item_size = sizeof(ros_message->lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name height
  {
    size_t item_size = sizeof(ros_message->height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name h_msl
  {
    size_t item_size = sizeof(ros_message->h_msl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name h_acc
  {
    size_t item_size = sizeof(ros_message->h_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_acc
  {
    size_t item_size = sizeof(ros_message->v_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_n
  {
    size_t item_size = sizeof(ros_message->vel_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_e
  {
    size_t item_size = sizeof(ros_message->vel_e);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_d
  {
    size_t item_size = sizeof(ros_message->vel_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name s_acc
  {
    size_t item_size = sizeof(ros_message->s_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GnsNP__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_msgs__msg__GnsNP(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t max_serialized_size_xsens_msgs__msg__GnsNP(
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
  // member: fixtype
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: lon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: lat
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: height
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: h_msl
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: h_acc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_acc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_n
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_e
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_d
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: s_acc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _GnsNP__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_xsens_msgs__msg__GnsNP(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_GnsNP = {
  "xsens_msgs::msg",
  "GnsNP",
  _GnsNP__cdr_serialize,
  _GnsNP__cdr_deserialize,
  _GnsNP__get_serialized_size,
  _GnsNP__max_serialized_size
};

static rosidl_message_type_support_t _GnsNP__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GnsNP,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, GnsNP)() {
  return &_GnsNP__type_support;
}

#if defined(__cplusplus)
}
#endif
