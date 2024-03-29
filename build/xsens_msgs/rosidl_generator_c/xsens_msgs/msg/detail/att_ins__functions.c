// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsens_msgs:msg/AttINS.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/att_ins__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
xsens_msgs__msg__AttINS__init(xsens_msgs__msg__AttINS * msg)
{
  if (!msg) {
    return false;
  }
  // roll
  // pitch
  // yaw
  return true;
}

void
xsens_msgs__msg__AttINS__fini(xsens_msgs__msg__AttINS * msg)
{
  if (!msg) {
    return;
  }
  // roll
  // pitch
  // yaw
}

xsens_msgs__msg__AttINS *
xsens_msgs__msg__AttINS__create()
{
  xsens_msgs__msg__AttINS * msg = (xsens_msgs__msg__AttINS *)malloc(sizeof(xsens_msgs__msg__AttINS));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsens_msgs__msg__AttINS));
  bool success = xsens_msgs__msg__AttINS__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xsens_msgs__msg__AttINS__destroy(xsens_msgs__msg__AttINS * msg)
{
  if (msg) {
    xsens_msgs__msg__AttINS__fini(msg);
  }
  free(msg);
}


bool
xsens_msgs__msg__AttINS__Sequence__init(xsens_msgs__msg__AttINS__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xsens_msgs__msg__AttINS * data = NULL;
  if (size) {
    data = (xsens_msgs__msg__AttINS *)calloc(size, sizeof(xsens_msgs__msg__AttINS));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsens_msgs__msg__AttINS__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsens_msgs__msg__AttINS__fini(&data[i - 1]);
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
xsens_msgs__msg__AttINS__Sequence__fini(xsens_msgs__msg__AttINS__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xsens_msgs__msg__AttINS__fini(&array->data[i]);
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

xsens_msgs__msg__AttINS__Sequence *
xsens_msgs__msg__AttINS__Sequence__create(size_t size)
{
  xsens_msgs__msg__AttINS__Sequence * array = (xsens_msgs__msg__AttINS__Sequence *)malloc(sizeof(xsens_msgs__msg__AttINS__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xsens_msgs__msg__AttINS__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xsens_msgs__msg__AttINS__Sequence__destroy(xsens_msgs__msg__AttINS__Sequence * array)
{
  if (array) {
    xsens_msgs__msg__AttINS__Sequence__fini(array);
  }
  free(array);
}
