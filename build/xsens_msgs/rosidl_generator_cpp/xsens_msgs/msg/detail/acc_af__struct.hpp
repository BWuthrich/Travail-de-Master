// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/AccAF.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ACC_AF__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__ACC_AF__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__AccAF __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__AccAF __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AccAF_
{
  using Type = AccAF_<ContainerAllocator>;

  explicit AccAF_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accx = 0.0;
      this->accy = 0.0;
      this->accz = 0.0;
    }
  }

  explicit AccAF_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accx = 0.0;
      this->accy = 0.0;
      this->accz = 0.0;
    }
  }

  // field types and members
  using _stamp_type =
    std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other>;
  _stamp_type stamp;
  using _accx_type =
    double;
  _accx_type accx;
  using _accy_type =
    double;
  _accy_type accy;
  using _accz_type =
    double;
  _accz_type accz;

  // setters for named parameter idiom
  Type & set__stamp(
    const std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__accx(
    const double & _arg)
  {
    this->accx = _arg;
    return *this;
  }
  Type & set__accy(
    const double & _arg)
  {
    this->accy = _arg;
    return *this;
  }
  Type & set__accz(
    const double & _arg)
  {
    this->accz = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::AccAF_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::AccAF_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::AccAF_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::AccAF_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::AccAF_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::AccAF_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::AccAF_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::AccAF_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::AccAF_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::AccAF_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__AccAF
    std::shared_ptr<xsens_msgs::msg::AccAF_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__AccAF
    std::shared_ptr<xsens_msgs::msg::AccAF_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AccAF_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->accx != other.accx) {
      return false;
    }
    if (this->accy != other.accy) {
      return false;
    }
    if (this->accz != other.accz) {
      return false;
    }
    return true;
  }
  bool operator!=(const AccAF_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AccAF_

// alias to use template instance with default allocator
using AccAF =
  xsens_msgs::msg::AccAF_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__ACC_AF__STRUCT_HPP_
