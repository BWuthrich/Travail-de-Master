// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xsens_msgs:msg/StaCT.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_CT__FUNCTIONS_H_
#define XSENS_MSGS__MSG__DETAIL__STA_CT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xsens_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "xsens_msgs/msg/detail/sta_ct__struct.h"

/// Initialize msg/StaCT message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xsens_msgs__msg__StaCT
 * )) before or use
 * xsens_msgs__msg__StaCT__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
bool
xsens_msgs__msg__StaCT__init(xsens_msgs__msg__StaCT * msg);

/// Finalize msg/StaCT message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
void
xsens_msgs__msg__StaCT__fini(xsens_msgs__msg__StaCT * msg);

/// Create msg/StaCT message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xsens_msgs__msg__StaCT__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
xsens_msgs__msg__StaCT *
xsens_msgs__msg__StaCT__create();

/// Destroy msg/StaCT message.
/**
 * It calls
 * xsens_msgs__msg__StaCT__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
void
xsens_msgs__msg__StaCT__destroy(xsens_msgs__msg__StaCT * msg);


/// Initialize array of msg/StaCT messages.
/**
 * It allocates the memory for the number of elements and calls
 * xsens_msgs__msg__StaCT__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
bool
xsens_msgs__msg__StaCT__Sequence__init(xsens_msgs__msg__StaCT__Sequence * array, size_t size);

/// Finalize array of msg/StaCT messages.
/**
 * It calls
 * xsens_msgs__msg__StaCT__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
void
xsens_msgs__msg__StaCT__Sequence__fini(xsens_msgs__msg__StaCT__Sequence * array);

/// Create array of msg/StaCT messages.
/**
 * It allocates the memory for the array and calls
 * xsens_msgs__msg__StaCT__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
xsens_msgs__msg__StaCT__Sequence *
xsens_msgs__msg__StaCT__Sequence__create(size_t size);

/// Destroy array of msg/StaCT messages.
/**
 * It calls
 * xsens_msgs__msg__StaCT__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_msgs
void
xsens_msgs__msg__StaCT__Sequence__destroy(xsens_msgs__msg__StaCT__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MSGS__MSG__DETAIL__STA_CT__FUNCTIONS_H_
