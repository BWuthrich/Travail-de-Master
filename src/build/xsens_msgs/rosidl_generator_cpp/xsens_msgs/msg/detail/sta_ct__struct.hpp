// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/StaCT.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_CT__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__STA_CT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__StaCT __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__StaCT __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StaCT_
{
  using Type = StaCT_<ContainerAllocator>;

  explicit StaCT_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cam_status = "";
    }
  }

  explicit StaCT_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cam_status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cam_status = "";
    }
  }

  // field types and members
  using _cam_status_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _cam_status_type cam_status;

  // setters for named parameter idiom
  Type & set__cam_status(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->cam_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::StaCT_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::StaCT_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::StaCT_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::StaCT_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::StaCT_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::StaCT_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::StaCT_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::StaCT_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::StaCT_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::StaCT_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__StaCT
    std::shared_ptr<xsens_msgs::msg::StaCT_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__StaCT
    std::shared_ptr<xsens_msgs::msg::StaCT_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StaCT_ & other) const
  {
    if (this->cam_status != other.cam_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const StaCT_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StaCT_

// alias to use template instance with default allocator
using StaCT =
  xsens_msgs::msg::StaCT_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__STA_CT__STRUCT_HPP_
