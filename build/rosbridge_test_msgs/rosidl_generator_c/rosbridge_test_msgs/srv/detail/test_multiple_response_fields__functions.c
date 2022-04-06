// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbridge_test_msgs:srv/TestMultipleResponseFields.idl
// generated code does not contain a copyright notice
#include "rosbridge_test_msgs/srv/detail/test_multiple_response_fields__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__init(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__fini(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

rosbridge_test_msgs__srv__TestMultipleResponseFields_Request *
rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__create()
{
  rosbridge_test_msgs__srv__TestMultipleResponseFields_Request * msg = (rosbridge_test_msgs__srv__TestMultipleResponseFields_Request *)malloc(sizeof(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request));
  bool success = rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__destroy(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request * msg)
{
  if (msg) {
    rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__fini(msg);
  }
  free(msg);
}


bool
rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence__init(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosbridge_test_msgs__srv__TestMultipleResponseFields_Request * data = NULL;
  if (size) {
    data = (rosbridge_test_msgs__srv__TestMultipleResponseFields_Request *)calloc(size, sizeof(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__fini(&data[i - 1]);
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
rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence__fini(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__fini(&array->data[i]);
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

rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence *
rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence__create(size_t size)
{
  rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence * array = (rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence *)malloc(sizeof(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence__destroy(rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence * array)
{
  if (array) {
    rosbridge_test_msgs__srv__TestMultipleResponseFields_Request__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `string`
#include "rosidl_runtime_c/string_functions.h"

bool
rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__init(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response * msg)
{
  if (!msg) {
    return false;
  }
  // int_value
  // float_value
  // string
  if (!rosidl_runtime_c__String__init(&msg->string)) {
    rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__fini(msg);
    return false;
  }
  // bool_value
  return true;
}

void
rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__fini(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response * msg)
{
  if (!msg) {
    return;
  }
  // int_value
  // float_value
  // string
  rosidl_runtime_c__String__fini(&msg->string);
  // bool_value
}

rosbridge_test_msgs__srv__TestMultipleResponseFields_Response *
rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__create()
{
  rosbridge_test_msgs__srv__TestMultipleResponseFields_Response * msg = (rosbridge_test_msgs__srv__TestMultipleResponseFields_Response *)malloc(sizeof(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response));
  bool success = rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__destroy(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response * msg)
{
  if (msg) {
    rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__fini(msg);
  }
  free(msg);
}


bool
rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence__init(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosbridge_test_msgs__srv__TestMultipleResponseFields_Response * data = NULL;
  if (size) {
    data = (rosbridge_test_msgs__srv__TestMultipleResponseFields_Response *)calloc(size, sizeof(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__fini(&data[i - 1]);
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
rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence__fini(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__fini(&array->data[i]);
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

rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence *
rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence__create(size_t size)
{
  rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence * array = (rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence *)malloc(sizeof(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence__destroy(rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence * array)
{
  if (array) {
    rosbridge_test_msgs__srv__TestMultipleResponseFields_Response__Sequence__fini(array);
  }
  free(array);
}
