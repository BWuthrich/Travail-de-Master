// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbridge_msgs:msg/ConnectedClient.idl
// generated code does not contain a copyright notice
#include "rosbridge_msgs/msg/detail/connected_client__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `ip_address`
#include "rosidl_runtime_c/string_functions.h"
// Member `connection_time`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
rosbridge_msgs__msg__ConnectedClient__init(rosbridge_msgs__msg__ConnectedClient * msg)
{
  if (!msg) {
    return false;
  }
  // ip_address
  if (!rosidl_runtime_c__String__init(&msg->ip_address)) {
    rosbridge_msgs__msg__ConnectedClient__fini(msg);
    return false;
  }
  // connection_time
  if (!builtin_interfaces__msg__Time__init(&msg->connection_time)) {
    rosbridge_msgs__msg__ConnectedClient__fini(msg);
    return false;
  }
  return true;
}

void
rosbridge_msgs__msg__ConnectedClient__fini(rosbridge_msgs__msg__ConnectedClient * msg)
{
  if (!msg) {
    return;
  }
  // ip_address
  rosidl_runtime_c__String__fini(&msg->ip_address);
  // connection_time
  builtin_interfaces__msg__Time__fini(&msg->connection_time);
}

rosbridge_msgs__msg__ConnectedClient *
rosbridge_msgs__msg__ConnectedClient__create()
{
  rosbridge_msgs__msg__ConnectedClient * msg = (rosbridge_msgs__msg__ConnectedClient *)malloc(sizeof(rosbridge_msgs__msg__ConnectedClient));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbridge_msgs__msg__ConnectedClient));
  bool success = rosbridge_msgs__msg__ConnectedClient__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosbridge_msgs__msg__ConnectedClient__destroy(rosbridge_msgs__msg__ConnectedClient * msg)
{
  if (msg) {
    rosbridge_msgs__msg__ConnectedClient__fini(msg);
  }
  free(msg);
}


bool
rosbridge_msgs__msg__ConnectedClient__Sequence__init(rosbridge_msgs__msg__ConnectedClient__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosbridge_msgs__msg__ConnectedClient * data = NULL;
  if (size) {
    data = (rosbridge_msgs__msg__ConnectedClient *)calloc(size, sizeof(rosbridge_msgs__msg__ConnectedClient));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbridge_msgs__msg__ConnectedClient__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbridge_msgs__msg__ConnectedClient__fini(&data[i - 1]);
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
rosbridge_msgs__msg__ConnectedClient__Sequence__fini(rosbridge_msgs__msg__ConnectedClient__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosbridge_msgs__msg__ConnectedClient__fini(&array->data[i]);
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

rosbridge_msgs__msg__ConnectedClient__Sequence *
rosbridge_msgs__msg__ConnectedClient__Sequence__create(size_t size)
{
  rosbridge_msgs__msg__ConnectedClient__Sequence * array = (rosbridge_msgs__msg__ConnectedClient__Sequence *)malloc(sizeof(rosbridge_msgs__msg__ConnectedClient__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosbridge_msgs__msg__ConnectedClient__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosbridge_msgs__msg__ConnectedClient__Sequence__destroy(rosbridge_msgs__msg__ConnectedClient__Sequence * array)
{
  if (array) {
    rosbridge_msgs__msg__ConnectedClient__Sequence__fini(array);
  }
  free(array);
}
