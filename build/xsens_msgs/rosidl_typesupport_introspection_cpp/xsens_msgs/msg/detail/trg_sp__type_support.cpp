// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from xsens_msgs:msg/TrgSP.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "xsens_msgs/msg/detail/trg_sp__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace xsens_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TrgSP_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) xsens_msgs::msg::TrgSP(_init);
}

void TrgSP_fini_function(void * message_memory)
{
  auto typed_message = static_cast<xsens_msgs::msg::TrgSP *>(message_memory);
  typed_message->~TrgSP();
}

size_t size_function__TrgSP__stamp(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TrgSP__stamp(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__TrgSP__stamp(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void resize_function__TrgSP__stamp(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TrgSP_message_member_array[2] = {
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs::msg::TrgSP, stamp),  // bytes offset in struct
    nullptr,  // default value
    size_function__TrgSP__stamp,  // size() function pointer
    get_const_function__TrgSP__stamp,  // get_const(index) function pointer
    get_function__TrgSP__stamp,  // get(index) function pointer
    resize_function__TrgSP__stamp  // resize(index) function pointer
  },
  {
    "trig_counter",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_msgs::msg::TrgSP, trig_counter),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TrgSP_message_members = {
  "xsens_msgs::msg",  // message namespace
  "TrgSP",  // message name
  2,  // number of fields
  sizeof(xsens_msgs::msg::TrgSP),
  TrgSP_message_member_array,  // message members
  TrgSP_init_function,  // function to initialize message memory (memory has to be allocated)
  TrgSP_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TrgSP_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TrgSP_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace xsens_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<xsens_msgs::msg::TrgSP>()
{
  return &::xsens_msgs::msg::rosidl_typesupport_introspection_cpp::TrgSP_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, xsens_msgs, msg, TrgSP)() {
  return &::xsens_msgs::msg::rosidl_typesupport_introspection_cpp::TrgSP_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
