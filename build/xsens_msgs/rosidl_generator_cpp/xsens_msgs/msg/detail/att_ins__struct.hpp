// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/AttINS.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ATT_INS__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__ATT_INS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__AttINS __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__AttINS __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AttINS_
{
  using Type = AttINS_<ContainerAllocator>;

  explicit AttINS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  explicit AttINS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::AttINS_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::AttINS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::AttINS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::AttINS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::AttINS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::AttINS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::AttINS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::AttINS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::AttINS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::AttINS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__AttINS
    std::shared_ptr<xsens_msgs::msg::AttINS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__AttINS
    std::shared_ptr<xsens_msgs::msg::AttINS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AttINS_ & other) const
  {
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const AttINS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AttINS_

// alias to use template instance with default allocator
using AttINS =
  xsens_msgs::msg::AttINS_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__ATT_INS__STRUCT_HPP_
