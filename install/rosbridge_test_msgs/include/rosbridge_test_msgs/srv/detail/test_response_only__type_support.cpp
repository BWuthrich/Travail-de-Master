// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rosbridge_test_msgs:srv/TestResponseOnly.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rosbridge_test_msgs/srv/detail/test_response_only__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rosbridge_test_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void TestResponseOnly_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rosbridge_test_msgs::srv::TestResponseOnly_Request(_init);
}

void TestResponseOnly_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rosbridge_test_msgs::srv::TestResponseOnly_Request *>(message_memory);
  typed_message->~TestResponseOnly_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TestResponseOnly_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbridge_test_msgs::srv::TestResponseOnly_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TestResponseOnly_Request_message_members = {
  "rosbridge_test_msgs::srv",  // message namespace
  "TestResponseOnly_Request",  // message name
  1,  // number of fields
  sizeof(rosbridge_test_msgs::srv::TestResponseOnly_Request),
  TestResponseOnly_Request_message_member_array,  // message members
  TestResponseOnly_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  TestResponseOnly_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TestResponseOnly_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TestResponseOnly_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rosbridge_test_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rosbridge_test_msgs::srv::TestResponseOnly_Request>()
{
  return &::rosbridge_test_msgs::srv::rosidl_typesupport_introspection_cpp::TestResponseOnly_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosbridge_test_msgs, srv, TestResponseOnly_Request)() {
  return &::rosbridge_test_msgs::srv::rosidl_typesupport_introspection_cpp::TestResponseOnly_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbridge_test_msgs/srv/detail/test_response_only__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rosbridge_test_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void TestResponseOnly_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rosbridge_test_msgs::srv::TestResponseOnly_Response(_init);
}

void TestResponseOnly_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rosbridge_test_msgs::srv::TestResponseOnly_Response *>(message_memory);
  typed_message->~TestResponseOnly_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TestResponseOnly_Response_message_member_array[1] = {
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbridge_test_msgs::srv::TestResponseOnly_Response, data),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TestResponseOnly_Response_message_members = {
  "rosbridge_test_msgs::srv",  // message namespace
  "TestResponseOnly_Response",  // message name
  1,  // number of fields
  sizeof(rosbridge_test_msgs::srv::TestResponseOnly_Response),
  TestResponseOnly_Response_message_member_array,  // message members
  TestResponseOnly_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  TestResponseOnly_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TestResponseOnly_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TestResponseOnly_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rosbridge_test_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rosbridge_test_msgs::srv::TestResponseOnly_Response>()
{
  return &::rosbridge_test_msgs::srv::rosidl_typesupport_introspection_cpp::TestResponseOnly_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosbridge_test_msgs, srv, TestResponseOnly_Response)() {
  return &::rosbridge_test_msgs::srv::rosidl_typesupport_introspection_cpp::TestResponseOnly_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "rosbridge_test_msgs/srv/detail/test_response_only__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace rosbridge_test_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers TestResponseOnly_service_members = {
  "rosbridge_test_msgs::srv",  // service namespace
  "TestResponseOnly",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<rosbridge_test_msgs::srv::TestResponseOnly>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t TestResponseOnly_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TestResponseOnly_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rosbridge_test_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<rosbridge_test_msgs::srv::TestResponseOnly>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::rosbridge_test_msgs::srv::rosidl_typesupport_introspection_cpp::TestResponseOnly_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::rosbridge_test_msgs::srv::TestResponseOnly_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::rosbridge_test_msgs::srv::TestResponseOnly_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rosbridge_test_msgs, srv, TestResponseOnly)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<rosbridge_test_msgs::srv::TestResponseOnly>();
}

#ifdef __cplusplus
}
#endif
