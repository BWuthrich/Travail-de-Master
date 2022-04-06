// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosapi_msgs:srv/TopicsAndRawTypes.idl
// generated code does not contain a copyright notice

#ifndef ROSAPI_MSGS__SRV__DETAIL__TOPICS_AND_RAW_TYPES__STRUCT_HPP_
#define ROSAPI_MSGS__SRV__DETAIL__TOPICS_AND_RAW_TYPES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rosapi_msgs__srv__TopicsAndRawTypes_Request __attribute__((deprecated))
#else
# define DEPRECATED__rosapi_msgs__srv__TopicsAndRawTypes_Request __declspec(deprecated)
#endif

namespace rosapi_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TopicsAndRawTypes_Request_
{
  using Type = TopicsAndRawTypes_Request_<ContainerAllocator>;

  explicit TopicsAndRawTypes_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit TopicsAndRawTypes_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosapi_msgs__srv__TopicsAndRawTypes_Request
    std::shared_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosapi_msgs__srv__TopicsAndRawTypes_Request
    std::shared_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TopicsAndRawTypes_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const TopicsAndRawTypes_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TopicsAndRawTypes_Request_

// alias to use template instance with default allocator
using TopicsAndRawTypes_Request =
  rosapi_msgs::srv::TopicsAndRawTypes_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosapi_msgs


#ifndef _WIN32
# define DEPRECATED__rosapi_msgs__srv__TopicsAndRawTypes_Response __attribute__((deprecated))
#else
# define DEPRECATED__rosapi_msgs__srv__TopicsAndRawTypes_Response __declspec(deprecated)
#endif

namespace rosapi_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TopicsAndRawTypes_Response_
{
  using Type = TopicsAndRawTypes_Response_<ContainerAllocator>;

  explicit TopicsAndRawTypes_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit TopicsAndRawTypes_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _topics_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _topics_type topics;
  using _types_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _types_type types;
  using _typedefs_full_text_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _typedefs_full_text_type typedefs_full_text;

  // setters for named parameter idiom
  Type & set__topics(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->topics = _arg;
    return *this;
  }
  Type & set__types(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->types = _arg;
    return *this;
  }
  Type & set__typedefs_full_text(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->typedefs_full_text = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosapi_msgs__srv__TopicsAndRawTypes_Response
    std::shared_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosapi_msgs__srv__TopicsAndRawTypes_Response
    std::shared_ptr<rosapi_msgs::srv::TopicsAndRawTypes_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TopicsAndRawTypes_Response_ & other) const
  {
    if (this->topics != other.topics) {
      return false;
    }
    if (this->types != other.types) {
      return false;
    }
    if (this->typedefs_full_text != other.typedefs_full_text) {
      return false;
    }
    return true;
  }
  bool operator!=(const TopicsAndRawTypes_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TopicsAndRawTypes_Response_

// alias to use template instance with default allocator
using TopicsAndRawTypes_Response =
  rosapi_msgs::srv::TopicsAndRawTypes_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosapi_msgs

namespace rosapi_msgs
{

namespace srv
{

struct TopicsAndRawTypes
{
  using Request = rosapi_msgs::srv::TopicsAndRawTypes_Request;
  using Response = rosapi_msgs::srv::TopicsAndRawTypes_Response;
};

}  // namespace srv

}  // namespace rosapi_msgs

#endif  // ROSAPI_MSGS__SRV__DETAIL__TOPICS_AND_RAW_TYPES__STRUCT_HPP_
