// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rosbridge_msgs:msg/ConnectedClient.idl
// generated code does not contain a copyright notice

#ifndef ROSBRIDGE_MSGS__MSG__DETAIL__CONNECTED_CLIENT__FUNCTIONS_H_
#define ROSBRIDGE_MSGS__MSG__DETAIL__CONNECTED_CLIENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rosbridge_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rosbridge_msgs/msg/detail/connected_client__struct.h"

/// Initialize msg/ConnectedClient message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rosbridge_msgs__msg__ConnectedClient
 * )) before or use
 * rosbridge_msgs__msg__ConnectedClient__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_msgs
bool
rosbridge_msgs__msg__ConnectedClient__init(rosbridge_msgs__msg__ConnectedClient * msg);

/// Finalize msg/ConnectedClient message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_msgs
void
rosbridge_msgs__msg__ConnectedClient__fini(rosbridge_msgs__msg__ConnectedClient * msg);

/// Create msg/ConnectedClient message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rosbridge_msgs__msg__ConnectedClient__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_msgs
rosbridge_msgs__msg__ConnectedClient *
rosbridge_msgs__msg__ConnectedClient__create();

/// Destroy msg/ConnectedClient message.
/**
 * It calls
 * rosbridge_msgs__msg__ConnectedClient__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_msgs
void
rosbridge_msgs__msg__ConnectedClient__destroy(rosbridge_msgs__msg__ConnectedClient * msg);


/// Initialize array of msg/ConnectedClient messages.
/**
 * It allocates the memory for the number of elements and calls
 * rosbridge_msgs__msg__ConnectedClient__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_msgs
bool
rosbridge_msgs__msg__ConnectedClient__Sequence__init(rosbridge_msgs__msg__ConnectedClient__Sequence * array, size_t size);

/// Finalize array of msg/ConnectedClient messages.
/**
 * It calls
 * rosbridge_msgs__msg__ConnectedClient__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_msgs
void
rosbridge_msgs__msg__ConnectedClient__Sequence__fini(rosbridge_msgs__msg__ConnectedClient__Sequence * array);

/// Create array of msg/ConnectedClient messages.
/**
 * It allocates the memory for the array and calls
 * rosbridge_msgs__msg__ConnectedClient__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_msgs
rosbridge_msgs__msg__ConnectedClient__Sequence *
rosbridge_msgs__msg__ConnectedClient__Sequence__create(size_t size);

/// Destroy array of msg/ConnectedClient messages.
/**
 * It calls
 * rosbridge_msgs__msg__ConnectedClient__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosbridge_msgs
void
rosbridge_msgs__msg__ConnectedClient__Sequence__destroy(rosbridge_msgs__msg__ConnectedClient__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ROSBRIDGE_MSGS__MSG__DETAIL__CONNECTED_CLIENT__FUNCTIONS_H_
