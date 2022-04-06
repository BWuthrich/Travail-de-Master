// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosapi_msgs:srv/Subscribers.idl
// generated code does not contain a copyright notice
#include "rosapi_msgs/srv/detail/subscribers__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `topic`
#include "rosidl_runtime_c/string_functions.h"

bool
rosapi_msgs__srv__Subscribers_Request__init(rosapi_msgs__srv__Subscribers_Request * msg)
{
  if (!msg) {
    return false;
  }
  // topic
  if (!rosidl_runtime_c__String__init(&msg->topic)) {
    rosapi_msgs__srv__Subscribers_Request__fini(msg);
    return false;
  }
  return true;
}

void
rosapi_msgs__srv__Subscribers_Request__fini(rosapi_msgs__srv__Subscribers_Request * msg)
{
  if (!msg) {
    return;
  }
  // topic
  rosidl_runtime_c__String__fini(&msg->topic);
}

rosapi_msgs__srv__Subscribers_Request *
rosapi_msgs__srv__Subscribers_Request__create()
{
  rosapi_msgs__srv__Subscribers_Request * msg = (rosapi_msgs__srv__Subscribers_Request *)malloc(sizeof(rosapi_msgs__srv__Subscribers_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosapi_msgs__srv__Subscribers_Request));
  bool success = rosapi_msgs__srv__Subscribers_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosapi_msgs__srv__Subscribers_Request__destroy(rosapi_msgs__srv__Subscribers_Request * msg)
{
  if (msg) {
    rosapi_msgs__srv__Subscribers_Request__fini(msg);
  }
  free(msg);
}


bool
rosapi_msgs__srv__Subscribers_Request__Sequence__init(rosapi_msgs__srv__Subscribers_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosapi_msgs__srv__Subscribers_Request * data = NULL;
  if (size) {
    data = (rosapi_msgs__srv__Subscribers_Request *)calloc(size, sizeof(rosapi_msgs__srv__Subscribers_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosapi_msgs__srv__Subscribers_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosapi_msgs__srv__Subscribers_Request__fini(&data[i - 1]);
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
rosapi_msgs__srv__Subscribers_Request__Sequence__fini(rosapi_msgs__srv__Subscribers_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosapi_msgs__srv__Subscribers_Request__fini(&array->data[i]);
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

rosapi_msgs__srv__Subscribers_Request__Sequence *
rosapi_msgs__srv__Subscribers_Request__Sequence__create(size_t size)
{
  rosapi_msgs__srv__Subscribers_Request__Sequence * array = (rosapi_msgs__srv__Subscribers_Request__Sequence *)malloc(sizeof(rosapi_msgs__srv__Subscribers_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosapi_msgs__srv__Subscribers_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosapi_msgs__srv__Subscribers_Request__Sequence__destroy(rosapi_msgs__srv__Subscribers_Request__Sequence * array)
{
  if (array) {
    rosapi_msgs__srv__Subscribers_Request__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `subscribers`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
rosapi_msgs__srv__Subscribers_Response__init(rosapi_msgs__srv__Subscribers_Response * msg)
{
  if (!msg) {
    return false;
  }
  // subscribers
  if (!rosidl_runtime_c__String__Sequence__init(&msg->subscribers, 0)) {
    rosapi_msgs__srv__Subscribers_Response__fini(msg);
    return false;
  }
  return true;
}

void
rosapi_msgs__srv__Subscribers_Response__fini(rosapi_msgs__srv__Subscribers_Response * msg)
{
  if (!msg) {
    return;
  }
  // subscribers
  rosidl_runtime_c__String__Sequence__fini(&msg->subscribers);
}

rosapi_msgs__srv__Subscribers_Response *
rosapi_msgs__srv__Subscribers_Response__create()
{
  rosapi_msgs__srv__Subscribers_Response * msg = (rosapi_msgs__srv__Subscribers_Response *)malloc(sizeof(rosapi_msgs__srv__Subscribers_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosapi_msgs__srv__Subscribers_Response));
  bool success = rosapi_msgs__srv__Subscribers_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosapi_msgs__srv__Subscribers_Response__destroy(rosapi_msgs__srv__Subscribers_Response * msg)
{
  if (msg) {
    rosapi_msgs__srv__Subscribers_Response__fini(msg);
  }
  free(msg);
}


bool
rosapi_msgs__srv__Subscribers_Response__Sequence__init(rosapi_msgs__srv__Subscribers_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosapi_msgs__srv__Subscribers_Response * data = NULL;
  if (size) {
    data = (rosapi_msgs__srv__Subscribers_Response *)calloc(size, sizeof(rosapi_msgs__srv__Subscribers_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosapi_msgs__srv__Subscribers_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosapi_msgs__srv__Subscribers_Response__fini(&data[i - 1]);
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
rosapi_msgs__srv__Subscribers_Response__Sequence__fini(rosapi_msgs__srv__Subscribers_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosapi_msgs__srv__Subscribers_Response__fini(&array->data[i]);
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

rosapi_msgs__srv__Subscribers_Response__Sequence *
rosapi_msgs__srv__Subscribers_Response__Sequence__create(size_t size)
{
  rosapi_msgs__srv__Subscribers_Response__Sequence * array = (rosapi_msgs__srv__Subscribers_Response__Sequence *)malloc(sizeof(rosapi_msgs__srv__Subscribers_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosapi_msgs__srv__Subscribers_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosapi_msgs__srv__Subscribers_Response__Sequence__destroy(rosapi_msgs__srv__Subscribers_Response__Sequence * array)
{
  if (array) {
    rosapi_msgs__srv__Subscribers_Response__Sequence__fini(array);
  }
  free(array);
}
