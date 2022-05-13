// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from xsens_msgs:msg/CamBatch.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/cam_batch__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "xsens_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "xsens_msgs/msg/detail/cam_batch__struct.h"
#include "xsens_msgs/msg/detail/cam_batch__functions.h"
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
#include "xsens_msgs/msg/detail/cam_image__functions.h"  // data

// forward declare type support functions
size_t get_serialized_size_xsens_msgs__msg__CamImage(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_xsens_msgs__msg__CamImage(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, CamImage)();


using _CamBatch__ros_msg_type = xsens_msgs__msg__CamBatch;

static bool _CamBatch__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CamBatch__ros_msg_type * ros_message = static_cast<const _CamBatch__ros_msg_type *>(untyped_ros_message);
  // Field name: stamp
  {
    size_t size = ros_message->stamp.size;
    auto array_ptr = ros_message->stamp.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: data
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, xsens_msgs, msg, CamImage
      )()->data);
    size_t size = 4;
    auto array_ptr = ros_message->data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _CamBatch__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CamBatch__ros_msg_type * ros_message = static_cast<_CamBatch__ros_msg_type *>(untyped_ros_message);
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

  // Field name: data
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, xsens_msgs, msg, CamImage
      )()->data);
    size_t size = 4;
    auto array_ptr = ros_message->data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t get_serialized_size_xsens_msgs__msg__CamBatch(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CamBatch__ros_msg_type * ros_message = static_cast<const _CamBatch__ros_msg_type *>(untyped_ros_message);
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
  // field.name data
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->data;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_xsens_msgs__msg__CamImage(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CamBatch__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_xsens_msgs__msg__CamBatch(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_xsens_msgs
size_t max_serialized_size_xsens_msgs__msg__CamBatch(
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
  // member: data
  {
    size_t array_size = 4;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_xsens_msgs__msg__CamImage(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _CamBatch__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_xsens_msgs__msg__CamBatch(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_CamBatch = {
  "xsens_msgs::msg",
  "CamBatch",
  _CamBatch__cdr_serialize,
  _CamBatch__cdr_deserialize,
  _CamBatch__get_serialized_size,
  _CamBatch__max_serialized_size
};

static rosidl_message_type_support_t _CamBatch__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CamBatch,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, xsens_msgs, msg, CamBatch)() {
  return &_CamBatch__type_support;
}

#if defined(__cplusplus)
}
#endif
