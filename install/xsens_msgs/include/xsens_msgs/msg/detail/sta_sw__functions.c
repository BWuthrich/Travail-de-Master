// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsens_msgs:msg/StaSW.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/msg/detail/sta_sw__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `filter_valid`
// Member `gnss_fix`
// Member `clock_sync`
// Member `sync_in`
// Member `sync_out`
// Member `filter_mode`
// Member `rtk_status`
#include "rosidl_runtime_c/string_functions.h"

bool
xsens_msgs__msg__StaSW__init(xsens_msgs__msg__StaSW * msg)
{
  if (!msg) {
    return false;
  }
  // filter_valid
  if (!rosidl_runtime_c__String__init(&msg->filter_valid)) {
    xsens_msgs__msg__StaSW__fini(msg);
    return false;
  }
  // gnss_fix
  if (!rosidl_runtime_c__String__init(&msg->gnss_fix)) {
    xsens_msgs__msg__StaSW__fini(msg);
    return false;
  }
  // clock_sync
  if (!rosidl_runtime_c__String__init(&msg->clock_sync)) {
    xsens_msgs__msg__StaSW__fini(msg);
    return false;
  }
  // sync_in
  if (!rosidl_runtime_c__String__init(&msg->sync_in)) {
    xsens_msgs__msg__StaSW__fini(msg);
    return false;
  }
  // sync_out
  if (!rosidl_runtime_c__String__init(&msg->sync_out)) {
    xsens_msgs__msg__StaSW__fini(msg);
    return false;
  }
  // filter_mode
  if (!rosidl_runtime_c__String__init(&msg->filter_mode)) {
    xsens_msgs__msg__StaSW__fini(msg);
    return false;
  }
  // rtk_status
  if (!rosidl_runtime_c__String__init(&msg->rtk_status)) {
    xsens_msgs__msg__StaSW__fini(msg);
    return false;
  }
  return true;
}

void
xsens_msgs__msg__StaSW__fini(xsens_msgs__msg__StaSW * msg)
{
  if (!msg) {
    return;
  }
  // filter_valid
  rosidl_runtime_c__String__fini(&msg->filter_valid);
  // gnss_fix
  rosidl_runtime_c__String__fini(&msg->gnss_fix);
  // clock_sync
  rosidl_runtime_c__String__fini(&msg->clock_sync);
  // sync_in
  rosidl_runtime_c__String__fini(&msg->sync_in);
  // sync_out
  rosidl_runtime_c__String__fini(&msg->sync_out);
  // filter_mode
  rosidl_runtime_c__String__fini(&msg->filter_mode);
  // rtk_status
  rosidl_runtime_c__String__fini(&msg->rtk_status);
}

xsens_msgs__msg__StaSW *
xsens_msgs__msg__StaSW__create()
{
  xsens_msgs__msg__StaSW * msg = (xsens_msgs__msg__StaSW *)malloc(sizeof(xsens_msgs__msg__StaSW));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsens_msgs__msg__StaSW));
  bool success = xsens_msgs__msg__StaSW__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xsens_msgs__msg__StaSW__destroy(xsens_msgs__msg__StaSW * msg)
{
  if (msg) {
    xsens_msgs__msg__StaSW__fini(msg);
  }
  free(msg);
}


bool
xsens_msgs__msg__StaSW__Sequence__init(xsens_msgs__msg__StaSW__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xsens_msgs__msg__StaSW * data = NULL;
  if (size) {
    data = (xsens_msgs__msg__StaSW *)calloc(size, sizeof(xsens_msgs__msg__StaSW));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsens_msgs__msg__StaSW__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsens_msgs__msg__StaSW__fini(&data[i - 1]);
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
xsens_msgs__msg__StaSW__Sequence__fini(xsens_msgs__msg__StaSW__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xsens_msgs__msg__StaSW__fini(&array->data[i]);
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

xsens_msgs__msg__StaSW__Sequence *
xsens_msgs__msg__StaSW__Sequence__create(size_t size)
{
  xsens_msgs__msg__StaSW__Sequence * array = (xsens_msgs__msg__StaSW__Sequence *)malloc(sizeof(xsens_msgs__msg__StaSW__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xsens_msgs__msg__StaSW__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xsens_msgs__msg__StaSW__Sequence__destroy(xsens_msgs__msg__StaSW__Sequence * array)
{
  if (array) {
    xsens_msgs__msg__StaSW__Sequence__fini(array);
  }
  free(array);
}
