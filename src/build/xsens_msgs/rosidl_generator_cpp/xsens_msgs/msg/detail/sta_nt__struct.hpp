// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/StaNT.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_NT__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__STA_NT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__StaNT __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__StaNT __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StaNT_
{
  using Type = StaNT_<ContainerAllocator>;

  explicit StaNT_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ntrip_status = "";
      this->rtcm_status = "";
    }
  }

  explicit StaNT_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : ntrip_status(_alloc),
    rtcm_status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ntrip_status = "";
      this->rtcm_status = "";
    }
  }

  // field types and members
  using _ntrip_status_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _ntrip_status_type ntrip_status;
  using _rtcm_status_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _rtcm_status_type rtcm_status;

  // setters for named parameter idiom
  Type & set__ntrip_status(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->ntrip_status = _arg;
    return *this;
  }
  Type & set__rtcm_status(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->rtcm_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::StaNT_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::StaNT_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::StaNT_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::StaNT_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::StaNT_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::StaNT_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::StaNT_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::StaNT_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::StaNT_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::StaNT_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__StaNT
    std::shared_ptr<xsens_msgs::msg::StaNT_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__StaNT
    std::shared_ptr<xsens_msgs::msg::StaNT_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StaNT_ & other) const
  {
    if (this->ntrip_status != other.ntrip_status) {
      return false;
    }
    if (this->rtcm_status != other.rtcm_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const StaNT_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StaNT_

// alias to use template instance with default allocator
using StaNT =
  xsens_msgs::msg::StaNT_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__STA_NT__STRUCT_HPP_
