// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from xsens_msgs:msg/ConfigXsens.idl
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
#include "xsens_msgs/msg/detail/config_xsens__struct.h"
#include "xsens_msgs/msg/detail/config_xsens__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool xsens_msgs__msg__config_xsens__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("xsens_msgs.msg._config_xsens.ConfigXsens", full_classname_dest, 40) == 0);
  }
  xsens_msgs__msg__ConfigXsens * ros_message = _ros_message;
  {  // configuration
    PyObject * field = PyObject_GetAttrString(_pymsg, "configuration");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->configuration, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // baudrate
    PyObject * field = PyObject_GetAttrString(_pymsg, "baudrate");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->baudrate = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // port_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "port_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->port_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // rtcm_refresh_dist
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtcm_refresh_dist");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rtcm_refresh_dist = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * xsens_msgs__msg__config_xsens__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ConfigXsens */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("xsens_msgs.msg._config_xsens");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ConfigXsens");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  xsens_msgs__msg__ConfigXsens * ros_message = (xsens_msgs__msg__ConfigXsens *)raw_ros_message;
  {  // configuration
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->configuration.data,
      strlen(ros_message->configuration.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "configuration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // baudrate
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->baudrate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "baudrate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // port_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->port_name.data,
      strlen(ros_message->port_name.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "port_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtcm_refresh_dist
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rtcm_refresh_dist);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtcm_refresh_dist", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
