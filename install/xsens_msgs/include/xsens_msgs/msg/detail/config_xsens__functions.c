// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsens_msgs:msg/ConfigXsens.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/config_xsens__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `output_config`
// Member `port_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `sync_config`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
xsens_msgs__msg__ConfigXsens__init(xsens_msgs__msg__ConfigXsens * msg)
{
  if (!msg) {
    return false;
  }
  // output_config
  if (!rosidl_runtime_c__String__init(&msg->output_config)) {
    xsens_msgs__msg__ConfigXsens__fini(msg);
    return false;
  }
  // baudrate
  // port_name
  if (!rosidl_runtime_c__String__init(&msg->port_name)) {
    xsens_msgs__msg__ConfigXsens__fini(msg);
    return false;
  }
  // rtcm_refresh_dist
  // sync_config
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->sync_config, 0)) {
    xsens_msgs__msg__ConfigXsens__fini(msg);
    return false;
  }
  // dt_freq
  return true;
}

void
xsens_msgs__msg__ConfigXsens__fini(xsens_msgs__msg__ConfigXsens * msg)
{
  if (!msg) {
    return;
  }
  // output_config
  rosidl_runtime_c__String__fini(&msg->output_config);
  // baudrate
  // port_name
  rosidl_runtime_c__String__fini(&msg->port_name);
  // rtcm_refresh_dist
  // sync_config
  rosidl_runtime_c__uint32__Sequence__fini(&msg->sync_config);
  // dt_freq
}

xsens_msgs__msg__ConfigXsens *
xsens_msgs__msg__ConfigXsens__create()
{
  xsens_msgs__msg__ConfigXsens * msg = (xsens_msgs__msg__ConfigXsens *)malloc(sizeof(xsens_msgs__msg__ConfigXsens));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsens_msgs__msg__ConfigXsens));
  bool success = xsens_msgs__msg__ConfigXsens__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xsens_msgs__msg__ConfigXsens__destroy(xsens_msgs__msg__ConfigXsens * msg)
{
  if (msg) {
    xsens_msgs__msg__ConfigXsens__fini(msg);
  }
  free(msg);
}


bool
xsens_msgs__msg__ConfigXsens__Sequence__init(xsens_msgs__msg__ConfigXsens__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xsens_msgs__msg__ConfigXsens * data = NULL;
  if (size) {
    data = (xsens_msgs__msg__ConfigXsens *)calloc(size, sizeof(xsens_msgs__msg__ConfigXsens));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsens_msgs__msg__ConfigXsens__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsens_msgs__msg__ConfigXsens__fini(&data[i - 1]);
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
xsens_msgs__msg__ConfigXsens__Sequence__fini(xsens_msgs__msg__ConfigXsens__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xsens_msgs__msg__ConfigXsens__fini(&array->data[i]);
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

xsens_msgs__msg__ConfigXsens__Sequence *
xsens_msgs__msg__ConfigXsens__Sequence__create(size_t size)
{
  xsens_msgs__msg__ConfigXsens__Sequence * array = (xsens_msgs__msg__ConfigXsens__Sequence *)malloc(sizeof(xsens_msgs__msg__ConfigXsens__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xsens_msgs__msg__ConfigXsens__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xsens_msgs__msg__ConfigXsens__Sequence__destroy(xsens_msgs__msg__ConfigXsens__Sequence * array)
{
  if (array) {
    xsens_msgs__msg__ConfigXsens__Sequence__fini(array);
  }
  free(array);
}
