// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosapi_msgs:msg/TypeDef.idl
// generated code does not contain a copyright notice
#include "rosapi_msgs/msg/detail/type_def__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `type`
// Member `fieldnames`
// Member `fieldtypes`
// Member `examples`
// Member `constnames`
// Member `constvalues`
#include "rosidl_runtime_c/string_functions.h"
// Member `fieldarraylen`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rosapi_msgs__msg__TypeDef__init(rosapi_msgs__msg__TypeDef * msg)
{
  if (!msg) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    rosapi_msgs__msg__TypeDef__fini(msg);
    return false;
  }
  // fieldnames
  if (!rosidl_runtime_c__String__Sequence__init(&msg->fieldnames, 0)) {
    rosapi_msgs__msg__TypeDef__fini(msg);
    return false;
  }
  // fieldtypes
  if (!rosidl_runtime_c__String__Sequence__init(&msg->fieldtypes, 0)) {
    rosapi_msgs__msg__TypeDef__fini(msg);
    return false;
  }
  // fieldarraylen
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->fieldarraylen, 0)) {
    rosapi_msgs__msg__TypeDef__fini(msg);
    return false;
  }
  // examples
  if (!rosidl_runtime_c__String__Sequence__init(&msg->examples, 0)) {
    rosapi_msgs__msg__TypeDef__fini(msg);
    return false;
  }
  // constnames
  if (!rosidl_runtime_c__String__Sequence__init(&msg->constnames, 0)) {
    rosapi_msgs__msg__TypeDef__fini(msg);
    return false;
  }
  // constvalues
  if (!rosidl_runtime_c__String__Sequence__init(&msg->constvalues, 0)) {
    rosapi_msgs__msg__TypeDef__fini(msg);
    return false;
  }
  return true;
}

void
rosapi_msgs__msg__TypeDef__fini(rosapi_msgs__msg__TypeDef * msg)
{
  if (!msg) {
    return;
  }
  // type
  rosidl_runtime_c__String__fini(&msg->type);
  // fieldnames
  rosidl_runtime_c__String__Sequence__fini(&msg->fieldnames);
  // fieldtypes
  rosidl_runtime_c__String__Sequence__fini(&msg->fieldtypes);
  // fieldarraylen
  rosidl_runtime_c__int32__Sequence__fini(&msg->fieldarraylen);
  // examples
  rosidl_runtime_c__String__Sequence__fini(&msg->examples);
  // constnames
  rosidl_runtime_c__String__Sequence__fini(&msg->constnames);
  // constvalues
  rosidl_runtime_c__String__Sequence__fini(&msg->constvalues);
}

rosapi_msgs__msg__TypeDef *
rosapi_msgs__msg__TypeDef__create()
{
  rosapi_msgs__msg__TypeDef * msg = (rosapi_msgs__msg__TypeDef *)malloc(sizeof(rosapi_msgs__msg__TypeDef));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosapi_msgs__msg__TypeDef));
  bool success = rosapi_msgs__msg__TypeDef__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosapi_msgs__msg__TypeDef__destroy(rosapi_msgs__msg__TypeDef * msg)
{
  if (msg) {
    rosapi_msgs__msg__TypeDef__fini(msg);
  }
  free(msg);
}


bool
rosapi_msgs__msg__TypeDef__Sequence__init(rosapi_msgs__msg__TypeDef__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosapi_msgs__msg__TypeDef * data = NULL;
  if (size) {
    data = (rosapi_msgs__msg__TypeDef *)calloc(size, sizeof(rosapi_msgs__msg__TypeDef));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosapi_msgs__msg__TypeDef__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosapi_msgs__msg__TypeDef__fini(&data[i - 1]);
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
rosapi_msgs__msg__TypeDef__Sequence__fini(rosapi_msgs__msg__TypeDef__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosapi_msgs__msg__TypeDef__fini(&array->data[i]);
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

rosapi_msgs__msg__TypeDef__Sequence *
rosapi_msgs__msg__TypeDef__Sequence__create(size_t size)
{
  rosapi_msgs__msg__TypeDef__Sequence * array = (rosapi_msgs__msg__TypeDef__Sequence *)malloc(sizeof(rosapi_msgs__msg__TypeDef__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosapi_msgs__msg__TypeDef__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosapi_msgs__msg__TypeDef__Sequence__destroy(rosapi_msgs__msg__TypeDef__Sequence * array)
{
  if (array) {
    rosapi_msgs__msg__TypeDef__Sequence__fini(array);
  }
  free(array);
}
