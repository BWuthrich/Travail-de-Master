// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbridge_test_msgs:msg/TestUInt8.idl
// generated code does not contain a copyright notice
#include "rosbridge_test_msgs/msg/detail/test_u_int8__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rosbridge_test_msgs__msg__TestUInt8__init(rosbridge_test_msgs__msg__TestUInt8 * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    rosbridge_test_msgs__msg__TestUInt8__fini(msg);
    return false;
  }
  return true;
}

void
rosbridge_test_msgs__msg__TestUInt8__fini(rosbridge_test_msgs__msg__TestUInt8 * msg)
{
  if (!msg) {
    return;
  }
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

rosbridge_test_msgs__msg__TestUInt8 *
rosbridge_test_msgs__msg__TestUInt8__create()
{
  rosbridge_test_msgs__msg__TestUInt8 * msg = (rosbridge_test_msgs__msg__TestUInt8 *)malloc(sizeof(rosbridge_test_msgs__msg__TestUInt8));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbridge_test_msgs__msg__TestUInt8));
  bool success = rosbridge_test_msgs__msg__TestUInt8__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosbridge_test_msgs__msg__TestUInt8__destroy(rosbridge_test_msgs__msg__TestUInt8 * msg)
{
  if (msg) {
    rosbridge_test_msgs__msg__TestUInt8__fini(msg);
  }
  free(msg);
}


bool
rosbridge_test_msgs__msg__TestUInt8__Sequence__init(rosbridge_test_msgs__msg__TestUInt8__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosbridge_test_msgs__msg__TestUInt8 * data = NULL;
  if (size) {
    data = (rosbridge_test_msgs__msg__TestUInt8 *)calloc(size, sizeof(rosbridge_test_msgs__msg__TestUInt8));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbridge_test_msgs__msg__TestUInt8__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbridge_test_msgs__msg__TestUInt8__fini(&data[i - 1]);
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
rosbridge_test_msgs__msg__TestUInt8__Sequence__fini(rosbridge_test_msgs__msg__TestUInt8__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosbridge_test_msgs__msg__TestUInt8__fini(&array->data[i]);
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

rosbridge_test_msgs__msg__TestUInt8__Sequence *
rosbridge_test_msgs__msg__TestUInt8__Sequence__create(size_t size)
{
  rosbridge_test_msgs__msg__TestUInt8__Sequence * array = (rosbridge_test_msgs__msg__TestUInt8__Sequence *)malloc(sizeof(rosbridge_test_msgs__msg__TestUInt8__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosbridge_test_msgs__msg__TestUInt8__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosbridge_test_msgs__msg__TestUInt8__Sequence__destroy(rosbridge_test_msgs__msg__TestUInt8__Sequence * array)
{
  if (array) {
    rosbridge_test_msgs__msg__TestUInt8__Sequence__fini(array);
  }
  free(array);
}
