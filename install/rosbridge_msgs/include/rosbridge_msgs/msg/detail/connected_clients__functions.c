// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbridge_msgs:msg/ConnectedClients.idl
// generated code does not contain a copyright notice
#include "rosbridge_msgs/msg/detail/connected_clients__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `clients`
#include "rosbridge_msgs/msg/detail/connected_client__functions.h"

bool
rosbridge_msgs__msg__ConnectedClients__init(rosbridge_msgs__msg__ConnectedClients * msg)
{
  if (!msg) {
    return false;
  }
  // clients
  if (!rosbridge_msgs__msg__ConnectedClient__Sequence__init(&msg->clients, 0)) {
    rosbridge_msgs__msg__ConnectedClients__fini(msg);
    return false;
  }
  return true;
}

void
rosbridge_msgs__msg__ConnectedClients__fini(rosbridge_msgs__msg__ConnectedClients * msg)
{
  if (!msg) {
    return;
  }
  // clients
  rosbridge_msgs__msg__ConnectedClient__Sequence__fini(&msg->clients);
}

rosbridge_msgs__msg__ConnectedClients *
rosbridge_msgs__msg__ConnectedClients__create()
{
  rosbridge_msgs__msg__ConnectedClients * msg = (rosbridge_msgs__msg__ConnectedClients *)malloc(sizeof(rosbridge_msgs__msg__ConnectedClients));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbridge_msgs__msg__ConnectedClients));
  bool success = rosbridge_msgs__msg__ConnectedClients__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosbridge_msgs__msg__ConnectedClients__destroy(rosbridge_msgs__msg__ConnectedClients * msg)
{
  if (msg) {
    rosbridge_msgs__msg__ConnectedClients__fini(msg);
  }
  free(msg);
}


bool
rosbridge_msgs__msg__ConnectedClients__Sequence__init(rosbridge_msgs__msg__ConnectedClients__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosbridge_msgs__msg__ConnectedClients * data = NULL;
  if (size) {
    data = (rosbridge_msgs__msg__ConnectedClients *)calloc(size, sizeof(rosbridge_msgs__msg__ConnectedClients));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbridge_msgs__msg__ConnectedClients__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbridge_msgs__msg__ConnectedClients__fini(&data[i - 1]);
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
rosbridge_msgs__msg__ConnectedClients__Sequence__fini(rosbridge_msgs__msg__ConnectedClients__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosbridge_msgs__msg__ConnectedClients__fini(&array->data[i]);
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

rosbridge_msgs__msg__ConnectedClients__Sequence *
rosbridge_msgs__msg__ConnectedClients__Sequence__create(size_t size)
{
  rosbridge_msgs__msg__ConnectedClients__Sequence * array = (rosbridge_msgs__msg__ConnectedClients__Sequence *)malloc(sizeof(rosbridge_msgs__msg__ConnectedClients__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosbridge_msgs__msg__ConnectedClients__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosbridge_msgs__msg__ConnectedClients__Sequence__destroy(rosbridge_msgs__msg__ConnectedClients__Sequence * array)
{
  if (array) {
    rosbridge_msgs__msg__ConnectedClients__Sequence__fini(array);
  }
  free(array);
}
