// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbridge_test_msgs:msg/TestHeaderArray.idl
// generated code does not contain a copyright notice
#include "rosbridge_test_msgs/msg/detail/test_header_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
rosbridge_test_msgs__msg__TestHeaderArray__init(rosbridge_test_msgs__msg__TestHeaderArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__Sequence__init(&msg->header, 0)) {
    rosbridge_test_msgs__msg__TestHeaderArray__fini(msg);
    return false;
  }
  return true;
}

void
rosbridge_test_msgs__msg__TestHeaderArray__fini(rosbridge_test_msgs__msg__TestHeaderArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__Sequence__fini(&msg->header);
}

rosbridge_test_msgs__msg__TestHeaderArray *
rosbridge_test_msgs__msg__TestHeaderArray__create()
{
  rosbridge_test_msgs__msg__TestHeaderArray * msg = (rosbridge_test_msgs__msg__TestHeaderArray *)malloc(sizeof(rosbridge_test_msgs__msg__TestHeaderArray));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbridge_test_msgs__msg__TestHeaderArray));
  bool success = rosbridge_test_msgs__msg__TestHeaderArray__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosbridge_test_msgs__msg__TestHeaderArray__destroy(rosbridge_test_msgs__msg__TestHeaderArray * msg)
{
  if (msg) {
    rosbridge_test_msgs__msg__TestHeaderArray__fini(msg);
  }
  free(msg);
}


bool
rosbridge_test_msgs__msg__TestHeaderArray__Sequence__init(rosbridge_test_msgs__msg__TestHeaderArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosbridge_test_msgs__msg__TestHeaderArray * data = NULL;
  if (size) {
    data = (rosbridge_test_msgs__msg__TestHeaderArray *)calloc(size, sizeof(rosbridge_test_msgs__msg__TestHeaderArray));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbridge_test_msgs__msg__TestHeaderArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbridge_test_msgs__msg__TestHeaderArray__fini(&data[i - 1]);
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
rosbridge_test_msgs__msg__TestHeaderArray__Sequence__fini(rosbridge_test_msgs__msg__TestHeaderArray__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosbridge_test_msgs__msg__TestHeaderArray__fini(&array->data[i]);
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

rosbridge_test_msgs__msg__TestHeaderArray__Sequence *
rosbridge_test_msgs__msg__TestHeaderArray__Sequence__create(size_t size)
{
  rosbridge_test_msgs__msg__TestHeaderArray__Sequence * array = (rosbridge_test_msgs__msg__TestHeaderArray__Sequence *)malloc(sizeof(rosbridge_test_msgs__msg__TestHeaderArray__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosbridge_test_msgs__msg__TestHeaderArray__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosbridge_test_msgs__msg__TestHeaderArray__Sequence__destroy(rosbridge_test_msgs__msg__TestHeaderArray__Sequence * array)
{
  if (array) {
    rosbridge_test_msgs__msg__TestHeaderArray__Sequence__fini(array);
  }
  free(array);
}
