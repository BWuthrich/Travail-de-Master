// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rosbridge_test_msgs:msg/TestHeaderArray.idl
// generated code does not contain a copyright notice

#ifndef ROSBRIDGE_TEST_MSGS__MSG__DETAIL__TEST_HEADER_ARRAY__FUNCTIONS_H_
#define ROSBRIDGE_TEST_MSGS__MSG__DETAIL__TEST_HEADER_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rosbridge_test_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rosbridge_test_msgs/msg/detail/test_header_array__struct.h"

/// Initialize msg/TestHeaderArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rosbridge_test_msgs__msg__TestHeaderArray
 * )) before or use
 * rosbridge_test_msgs__msg__TestHeaderArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
bool
rosbridge_test_msgs__msg__TestHeaderArray__init(rosbridge_test_msgs__msg__TestHeaderArray * msg);

/// Finalize msg/TestHeaderArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
void
rosbridge_test_msgs__msg__TestHeaderArray__fini(rosbridge_test_msgs__msg__TestHeaderArray * msg);

/// Create msg/TestHeaderArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rosbridge_test_msgs__msg__TestHeaderArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
rosbridge_test_msgs__msg__TestHeaderArray *
rosbridge_test_msgs__msg__TestHeaderArray__create();

/// Destroy msg/TestHeaderArray message.
/**
 * It calls
 * rosbridge_test_msgs__msg__TestHeaderArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
void
rosbridge_test_msgs__msg__TestHeaderArray__destroy(rosbridge_test_msgs__msg__TestHeaderArray * msg);


/// Initialize array of msg/TestHeaderArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * rosbridge_test_msgs__msg__TestHeaderArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
bool
rosbridge_test_msgs__msg__TestHeaderArray__Sequence__init(rosbridge_test_msgs__msg__TestHeaderArray__Sequence * array, size_t size);

/// Finalize array of msg/TestHeaderArray messages.
/**
 * It calls
 * rosbridge_test_msgs__msg__TestHeaderArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
void
rosbridge_test_msgs__msg__TestHeaderArray__Sequence__fini(rosbridge_test_msgs__msg__TestHeaderArray__Sequence * array);

/// Create array of msg/TestHeaderArray messages.
/**
 * It allocates the memory for the array and calls
 * rosbridge_test_msgs__msg__TestHeaderArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
rosbridge_test_msgs__msg__TestHeaderArray__Sequence *
rosbridge_test_msgs__msg__TestHeaderArray__Sequence__create(size_t size);

/// Destroy array of msg/TestHeaderArray messages.
/**
 * It calls
 * rosbridge_test_msgs__msg__TestHeaderArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
void
rosbridge_test_msgs__msg__TestHeaderArray__Sequence__destroy(rosbridge_test_msgs__msg__TestHeaderArray__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ROSBRIDGE_TEST_MSGS__MSG__DETAIL__TEST_HEADER_ARRAY__FUNCTIONS_H_
