// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsens_msgs:srv/RTCMdata.idl
// generated code does not contain a copyright notice
#include "xsens_msgs/srv/detail/rtc_mdata__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
xsens_msgs__srv__RTCMdata_Request__init(xsens_msgs__srv__RTCMdata_Request * msg)
{
  if (!msg) {
    return false;
  }
  // longitude
  // latitude
  // alti_ell
  return true;
}

void
xsens_msgs__srv__RTCMdata_Request__fini(xsens_msgs__srv__RTCMdata_Request * msg)
{
  if (!msg) {
    return;
  }
  // longitude
  // latitude
  // alti_ell
}

xsens_msgs__srv__RTCMdata_Request *
xsens_msgs__srv__RTCMdata_Request__create()
{
  xsens_msgs__srv__RTCMdata_Request * msg = (xsens_msgs__srv__RTCMdata_Request *)malloc(sizeof(xsens_msgs__srv__RTCMdata_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsens_msgs__srv__RTCMdata_Request));
  bool success = xsens_msgs__srv__RTCMdata_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xsens_msgs__srv__RTCMdata_Request__destroy(xsens_msgs__srv__RTCMdata_Request * msg)
{
  if (msg) {
    xsens_msgs__srv__RTCMdata_Request__fini(msg);
  }
  free(msg);
}


bool
xsens_msgs__srv__RTCMdata_Request__Sequence__init(xsens_msgs__srv__RTCMdata_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xsens_msgs__srv__RTCMdata_Request * data = NULL;
  if (size) {
    data = (xsens_msgs__srv__RTCMdata_Request *)calloc(size, sizeof(xsens_msgs__srv__RTCMdata_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsens_msgs__srv__RTCMdata_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsens_msgs__srv__RTCMdata_Request__fini(&data[i - 1]);
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
xsens_msgs__srv__RTCMdata_Request__Sequence__fini(xsens_msgs__srv__RTCMdata_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xsens_msgs__srv__RTCMdata_Request__fini(&array->data[i]);
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

xsens_msgs__srv__RTCMdata_Request__Sequence *
xsens_msgs__srv__RTCMdata_Request__Sequence__create(size_t size)
{
  xsens_msgs__srv__RTCMdata_Request__Sequence * array = (xsens_msgs__srv__RTCMdata_Request__Sequence *)malloc(sizeof(xsens_msgs__srv__RTCMdata_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xsens_msgs__srv__RTCMdata_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xsens_msgs__srv__RTCMdata_Request__Sequence__destroy(xsens_msgs__srv__RTCMdata_Request__Sequence * array)
{
  if (array) {
    xsens_msgs__srv__RTCMdata_Request__Sequence__fini(array);
  }
  free(array);
}


bool
xsens_msgs__srv__RTCMdata_Response__init(xsens_msgs__srv__RTCMdata_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
xsens_msgs__srv__RTCMdata_Response__fini(xsens_msgs__srv__RTCMdata_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

xsens_msgs__srv__RTCMdata_Response *
xsens_msgs__srv__RTCMdata_Response__create()
{
  xsens_msgs__srv__RTCMdata_Response * msg = (xsens_msgs__srv__RTCMdata_Response *)malloc(sizeof(xsens_msgs__srv__RTCMdata_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsens_msgs__srv__RTCMdata_Response));
  bool success = xsens_msgs__srv__RTCMdata_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xsens_msgs__srv__RTCMdata_Response__destroy(xsens_msgs__srv__RTCMdata_Response * msg)
{
  if (msg) {
    xsens_msgs__srv__RTCMdata_Response__fini(msg);
  }
  free(msg);
}


bool
xsens_msgs__srv__RTCMdata_Response__Sequence__init(xsens_msgs__srv__RTCMdata_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xsens_msgs__srv__RTCMdata_Response * data = NULL;
  if (size) {
    data = (xsens_msgs__srv__RTCMdata_Response *)calloc(size, sizeof(xsens_msgs__srv__RTCMdata_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsens_msgs__srv__RTCMdata_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsens_msgs__srv__RTCMdata_Response__fini(&data[i - 1]);
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
xsens_msgs__srv__RTCMdata_Response__Sequence__fini(xsens_msgs__srv__RTCMdata_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xsens_msgs__srv__RTCMdata_Response__fini(&array->data[i]);
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

xsens_msgs__srv__RTCMdata_Response__Sequence *
xsens_msgs__srv__RTCMdata_Response__Sequence__create(size_t size)
{
  xsens_msgs__srv__RTCMdata_Response__Sequence * array = (xsens_msgs__srv__RTCMdata_Response__Sequence *)malloc(sizeof(xsens_msgs__srv__RTCMdata_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xsens_msgs__srv__RTCMdata_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xsens_msgs__srv__RTCMdata_Response__Sequence__destroy(xsens_msgs__srv__RTCMdata_Response__Sequence * array)
{
  if (array) {
    xsens_msgs__srv__RTCMdata_Response__Sequence__fini(array);
  }
  free(array);
}
