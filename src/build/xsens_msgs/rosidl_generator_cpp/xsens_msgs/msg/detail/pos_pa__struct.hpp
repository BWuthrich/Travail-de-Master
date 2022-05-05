// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/PosPA.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__POS_PA__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__POS_PA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__PosPA __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__PosPA __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PosPA_
{
  using Type = PosPA_<ContainerAllocator>;

  explicit PosPA_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->alt_ell = 0.0;
    }
  }

  explicit PosPA_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->alt_ell = 0.0;
    }
  }

  // field types and members
  using _stamp_type =
    std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other>;
  _stamp_type stamp;
  using _alt_ell_type =
    double;
  _alt_ell_type alt_ell;

  // setters for named parameter idiom
  Type & set__stamp(
    const std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__alt_ell(
    const double & _arg)
  {
    this->alt_ell = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::PosPA_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::PosPA_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::PosPA_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::PosPA_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::PosPA_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::PosPA_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::PosPA_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::PosPA_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::PosPA_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::PosPA_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__PosPA
    std::shared_ptr<xsens_msgs::msg::PosPA_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__PosPA
    std::shared_ptr<xsens_msgs::msg::PosPA_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PosPA_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->alt_ell != other.alt_ell) {
      return false;
    }
    return true;
  }
  bool operator!=(const PosPA_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PosPA_

// alias to use template instance with default allocator
using PosPA =
  xsens_msgs::msg::PosPA_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__POS_PA__STRUCT_HPP_
