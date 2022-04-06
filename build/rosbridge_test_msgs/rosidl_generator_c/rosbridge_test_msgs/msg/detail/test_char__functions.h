// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rosbridge_test_msgs:msg/TestChar.idl
// generated code does not contain a copyright notice

#ifndef ROSBRIDGE_TEST_MSGS__MSG__DETAIL__TEST_CHAR__FUNCTIONS_H_
#define ROSBRIDGE_TEST_MSGS__MSG__DETAIL__TEST_CHAR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rosbridge_test_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rosbridge_test_msgs/msg/detail/test_char__struct.h"

/// Initialize msg/TestChar message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rosbridge_test_msgs__msg__TestChar
 * )) before or use
 * rosbridge_test_msgs__msg__TestChar__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
bool
rosbridge_test_msgs__msg__TestChar__init(rosbridge_test_msgs__msg__TestChar * msg);

/// Finalize msg/TestChar message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
void
rosbridge_test_msgs__msg__TestChar__fini(rosbridge_test_msgs__msg__TestChar * msg);

/// Create msg/TestChar message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rosbridge_test_msgs__msg__TestChar__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
rosbridge_test_msgs__msg__TestChar *
rosbridge_test_msgs__msg__TestChar__create();

/// Destroy msg/TestChar message.
/**
 * It calls
 * rosbridge_test_msgs__msg__TestChar__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
void
rosbridge_test_msgs__msg__TestChar__destroy(rosbridge_test_msgs__msg__TestChar * msg);


/// Initialize array of msg/TestChar messages.
/**
 * It allocates the memory for the number of elements and calls
 * rosbridge_test_msgs__msg__TestChar__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
bool
rosbridge_test_msgs__msg__TestChar__Sequence__init(rosbridge_test_msgs__msg__TestChar__Sequence * array, size_t size);

/// Finalize array of msg/TestChar messages.
/**
 * It calls
 * rosbridge_test_msgs__msg__TestChar__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
void
rosbridge_test_msgs__msg__TestChar__Sequence__fini(rosbridge_test_msgs__msg__TestChar__Sequence * array);

/// Create array of msg/TestChar messages.
/**
 * It allocates the memory for the array and calls
 * rosbridge_test_msgs__msg__TestChar__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
rosbridge_test_msgs__msg__TestChar__Sequence *
rosbridge_test_msgs__msg__TestChar__Sequence__create(size_t size);

/// Destroy array of msg/TestChar messages.
/**
 * It calls
 * rosbridge_test_msgs__msg__TestChar__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_test_msgs
void
rosbridge_test_msgs__msg__TestChar__Sequence__destroy(rosbridge_test_msgs__msg__TestChar__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ROSBRIDGE_TEST_MSGS__MSG__DETAIL__TEST_CHAR__FUNCTIONS_H_
