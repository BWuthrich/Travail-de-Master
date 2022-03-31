// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from xsens_msgs:msg/ConfigNtrip.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "xsens_msgs/msg/detail/config_ntrip__struct.h"
#include "xsens_msgs/msg/detail/config_ntrip__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool xsens_msgs__msg__config_ntrip__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("xsens_msgs.msg._config_ntrip.ConfigNtrip", full_classname_dest, 40) == 0);
  }
  xsens_msgs__msg__ConfigNtrip * ros_message = _ros_message;
  {  // host
    PyObject * field = PyObject_GetAttrString(_pymsg, "host");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->host, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // port
    PyObject * field = PyObject_GetAttrString(_pymsg, "port");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->port = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // mountpoint
    PyObject * field = PyObject_GetAttrString(_pymsg, "mountpoint");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->mountpoint, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // username
    PyObject * field = PyObject_GetAttrString(_pymsg, "username");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->username, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // password
    PyObject * field = PyObject_GetAttrString(_pymsg, "password");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->password, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // rtcm_timer
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtcm_timer");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rtcm_timer = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * xsens_msgs__msg__config_ntrip__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ConfigNtrip */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("xsens_msgs.msg._config_ntrip");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ConfigNtrip");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  xsens_msgs__msg__ConfigNtrip * ros_message = (xsens_msgs__msg__ConfigNtrip *)raw_ros_message;
  {  // host
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->host.data,
      strlen(ros_message->host.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "host", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // port
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->port);
    {
      int rc = PyObject_SetAttrString(_pymessage, "port", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mountpoint
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->mountpoint.data,
      strlen(ros_message->mountpoint.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "mountpoint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // username
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->username.data,
      strlen(ros_message->username.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "username", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // password
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->password.data,
      strlen(ros_message->password.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "password", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtcm_timer
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rtcm_timer);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtcm_timer", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
