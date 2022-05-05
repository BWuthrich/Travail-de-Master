// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsens_msgs:msg/AccAA.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/acc_aa__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `stamp`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
xsens_msgs__msg__AccAA__init(xsens_msgs__msg__AccAA * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->stamp, 0)) {
    xsens_msgs__msg__AccAA__fini(msg);
    return false;
  }
  // accx
  // accy
  // accz
  return true;
}

void
xsens_msgs__msg__AccAA__fini(xsens_msgs__msg__AccAA * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  rosidl_runtime_c__int32__Sequence__fini(&msg->stamp);
  // accx
  // accy
  // accz
}

xsens_msgs__msg__AccAA *
xsens_msgs__msg__AccAA__create()
{
  xsens_msgs__msg__AccAA * msg = (xsens_msgs__msg__AccAA *)malloc(sizeof(xsens_msgs__msg__AccAA));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsens_msgs__msg__AccAA));
  bool success = xsens_msgs__msg__AccAA__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xsens_msgs__msg__AccAA__destroy(xsens_msgs__msg__AccAA * msg)
{
  if (msg) {
    xsens_msgs__msg__AccAA__fini(msg);
  }
  free(msg);
}


bool
xsens_msgs__msg__AccAA__Sequence__init(xsens_msgs__msg__AccAA__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xsens_msgs__msg__AccAA * data = NULL;
  if (size) {
    data = (xsens_msgs__msg__AccAA *)calloc(size, sizeof(xsens_msgs__msg__AccAA));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsens_msgs__msg__AccAA__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsens_msgs__msg__AccAA__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xsens_msgs__msg__AccAA__Sequence__fini(xsens_msgs__msg__AccAA__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xsens_msgs__msg__AccAA__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xsens_msgs__msg__AccAA__Sequence *
xsens_msgs__msg__AccAA__Sequence__create(size_t size)
{
  xsens_msgs__msg__AccAA__Sequence * array = (xsens_msgs__msg__AccAA__Sequence *)malloc(sizeof(xsens_msgs__msg__AccAA__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xsens_msgs__msg__AccAA__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xsens_msgs__msg__AccAA__Sequence__destroy(xsens_msgs__msg__AccAA__Sequence * array)
{
  if (array) {
    xsens_msgs__msg__AccAA__Sequence__fini(array);
  }
  free(array);
}
