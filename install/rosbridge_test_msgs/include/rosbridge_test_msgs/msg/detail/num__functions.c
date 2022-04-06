// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbridge_test_msgs:msg/Num.idl
// generated code does not contain a copyright notice
#include "rosbridge_test_msgs/msg/detail/num__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
rosbridge_test_msgs__msg__Num__init(rosbridge_test_msgs__msg__Num * msg)
{
  if (!msg) {
    return false;
  }
  // num
  return true;
}

void
rosbridge_test_msgs__msg__Num__fini(rosbridge_test_msgs__msg__Num * msg)
{
  if (!msg) {
    return;
  }
  // num
}

rosbridge_test_msgs__msg__Num *
rosbridge_test_msgs__msg__Num__create()
{
  rosbridge_test_msgs__msg__Num * msg = (rosbridge_test_msgs__msg__Num *)malloc(sizeof(rosbridge_test_msgs__msg__Num));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbridge_test_msgs__msg__Num));
  bool success = rosbridge_test_msgs__msg__Num__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosbridge_test_msgs__msg__Num__destroy(rosbridge_test_msgs__msg__Num * msg)
{
  if (msg) {
    rosbridge_test_msgs__msg__Num__fini(msg);
  }
  free(msg);
}


bool
rosbridge_test_msgs__msg__Num__Sequence__init(rosbridge_test_msgs__msg__Num__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosbridge_test_msgs__msg__Num * data = NULL;
  if (size) {
    data = (rosbridge_test_msgs__msg__Num *)calloc(size, sizeof(rosbridge_test_msgs__msg__Num));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbridge_test_msgs__msg__Num__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbridge_test_msgs__msg__Num__fini(&data[i - 1]);
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
rosbridge_test_msgs__msg__Num__Sequence__fini(rosbridge_test_msgs__msg__Num__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosbridge_test_msgs__msg__Num__fini(&array->data[i]);
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

rosbridge_test_msgs__msg__Num__Sequence *
rosbridge_test_msgs__msg__Num__Sequence__create(size_t size)
{
  rosbridge_test_msgs__msg__Num__Sequence * array = (rosbridge_test_msgs__msg__Num__Sequence *)malloc(sizeof(rosbridge_test_msgs__msg__Num__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosbridge_test_msgs__msg__Num__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosbridge_test_msgs__msg__Num__Sequence__destroy(rosbridge_test_msgs__msg__Num__Sequence * array)
{
  if (array) {
    rosbridge_test_msgs__msg__Num__Sequence__fini(array);
  }
  free(array);
}
