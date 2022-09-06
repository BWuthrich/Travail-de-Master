// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xsens_msgs:msg/AttINS.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ATT_INS__FUNCTIONS_H_
#define XSENS_MSGS__MSG__DETAIL__ATT_INS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xsens_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "xsens_msgs/msg/detail/att_ins__struct.h"

/// Initialize msg/AttINS message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xsens_msgs__msg__AttINS
 * )) before or use
 * xsens_msgs__msg__AttINS__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
bool
xsens_msgs__msg__AttINS__init(xsens_msgs__msg__AttINS * msg);

/// Finalize msg/AttINS message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
void
xsens_msgs__msg__AttINS__fini(xsens_msgs__msg__AttINS * msg);

/// Create msg/AttINS message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xsens_msgs__msg__AttINS__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
xsens_msgs__msg__AttINS *
xsens_msgs__msg__AttINS__create();

/// Destroy msg/AttINS message.
/**
 * It calls
 * xsens_msgs__msg__AttINS__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
void
xsens_msgs__msg__AttINS__destroy(xsens_msgs__msg__AttINS * msg);


/// Initialize array of msg/AttINS messages.
/**
 * It allocates the memory for the number of elements and calls
 * xsens_msgs__msg__AttINS__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
bool
xsens_msgs__msg__AttINS__Sequence__init(xsens_msgs__msg__AttINS__Sequence * array, size_t size);

/// Finalize array of msg/AttINS messages.
/**
 * It calls
 * xsens_msgs__msg__AttINS__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
void
xsens_msgs__msg__AttINS__Sequence__fini(xsens_msgs__msg__AttINS__Sequence * array);

/// Create array of msg/AttINS messages.
/**
 * It allocates the memory for the array and calls
 * xsens_msgs__msg__AttINS__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
xsens_msgs__msg__AttINS__Sequence *
xsens_msgs__msg__AttINS__Sequence__create(size_t size);

/// Destroy array of msg/AttINS messages.
/**
 * It calls
 * xsens_msgs__msg__AttINS__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
void
xsens_msgs__msg__AttINS__Sequence__destroy(xsens_msgs__msg__AttINS__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__ATT_INS__FUNCTIONS_H_
