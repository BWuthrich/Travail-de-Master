// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsens_msgs:msg/PosINS.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/pos_ins__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
xsens_msgs__msg__PosINS__init(xsens_msgs__msg__PosINS * msg)
{
  if (!msg) {
    return false;
  }
  // lon
  // lat
  // height
  return true;
}

void
xsens_msgs__msg__PosINS__fini(xsens_msgs__msg__PosINS * msg)
{
  if (!msg) {
    return;
  }
  // lon
  // lat
  // height
}

xsens_msgs__msg__PosINS *
xsens_msgs__msg__PosINS__create()
{
  xsens_msgs__msg__PosINS * msg = (xsens_msgs__msg__PosINS *)malloc(sizeof(xsens_msgs__msg__PosINS));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsens_msgs__msg__PosINS));
  bool success = xsens_msgs__msg__PosINS__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xsens_msgs__msg__PosINS__destroy(xsens_msgs__msg__PosINS * msg)
{
  if (msg) {
    xsens_msgs__msg__PosINS__fini(msg);
  }
  free(msg);
}


bool
xsens_msgs__msg__PosINS__Sequence__init(xsens_msgs__msg__PosINS__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xsens_msgs__msg__PosINS * data = NULL;
  if (size) {
    data = (xsens_msgs__msg__PosINS *)calloc(size, sizeof(xsens_msgs__msg__PosINS));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsens_msgs__msg__PosINS__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsens_msgs__msg__PosINS__fini(&data[i - 1]);
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
xsens_msgs__msg__PosINS__Sequence__fini(xsens_msgs__msg__PosINS__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xsens_msgs__msg__PosINS__fini(&array->data[i]);
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

xsens_msgs__msg__PosINS__Sequence *
xsens_msgs__msg__PosINS__Sequence__create(size_t size)
{
  xsens_msgs__msg__PosINS__Sequence * array = (xsens_msgs__msg__PosINS__Sequence *)malloc(sizeof(xsens_msgs__msg__PosINS__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xsens_msgs__msg__PosINS__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xsens_msgs__msg__PosINS__Sequence__destroy(xsens_msgs__msg__PosINS__Sequence * array)
{
  if (array) {
    xsens_msgs__msg__PosINS__Sequence__fini(array);
  }
  free(array);
}
