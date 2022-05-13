// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/GnsNP.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__GNS_NP__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__GNS_NP__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__GnsNP __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__GnsNP __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GnsNP_
{
  using Type = GnsNP_<ContainerAllocator>;

  explicit GnsNP_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fixtype = 0;
      this->lon = 0.0;
      this->lat = 0.0;
      this->height = 0ll;
      this->h_msl = 0ll;
      this->h_acc = 0ll;
      this->v_acc = 0ll;
      this->vel_n = 0ll;
      this->vel_e = 0ll;
      this->vel_d = 0ll;
      this->s_acc = 0ll;
    }
  }

  explicit GnsNP_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fixtype = 0;
      this->lon = 0.0;
      this->lat = 0.0;
      this->height = 0ll;
      this->h_msl = 0ll;
      this->h_acc = 0ll;
      this->v_acc = 0ll;
      this->vel_n = 0ll;
      this->vel_e = 0ll;
      this->vel_d = 0ll;
      this->s_acc = 0ll;
    }
  }

  // field types and members
  using _stamp_type =
    std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other>;
  _stamp_type stamp;
  using _fixtype_type =
    int8_t;
  _fixtype_type fixtype;
  using _lon_type =
    double;
  _lon_type lon;
  using _lat_type =
    double;
  _lat_type lat;
  using _height_type =
    int64_t;
  _height_type height;
  using _h_msl_type =
    int64_t;
  _h_msl_type h_msl;
  using _h_acc_type =
    int64_t;
  _h_acc_type h_acc;
  using _v_acc_type =
    int64_t;
  _v_acc_type v_acc;
  using _vel_n_type =
    int64_t;
  _vel_n_type vel_n;
  using _vel_e_type =
    int64_t;
  _vel_e_type vel_e;
  using _vel_d_type =
    int64_t;
  _vel_d_type vel_d;
  using _s_acc_type =
    int64_t;
  _s_acc_type s_acc;

  // setters for named parameter idiom
  Type & set__stamp(
    const std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__fixtype(
    const int8_t & _arg)
  {
    this->fixtype = _arg;
    return *this;
  }
  Type & set__lon(
    const double & _arg)
  {
    this->lon = _arg;
    return *this;
  }
  Type & set__lat(
    const double & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__height(
    const int64_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__h_msl(
    const int64_t & _arg)
  {
    this->h_msl = _arg;
    return *this;
  }
  Type & set__h_acc(
    const int64_t & _arg)
  {
    this->h_acc = _arg;
    return *this;
  }
  Type & set__v_acc(
    const int64_t & _arg)
  {
    this->v_acc = _arg;
    return *this;
  }
  Type & set__vel_n(
    const int64_t & _arg)
  {
    this->vel_n = _arg;
    return *this;
  }
  Type & set__vel_e(
    const int64_t & _arg)
  {
    this->vel_e = _arg;
    return *this;
  }
  Type & set__vel_d(
    const int64_t & _arg)
  {
    this->vel_d = _arg;
    return *this;
  }
  Type & set__s_acc(
    const int64_t & _arg)
  {
    this->s_acc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::GnsNP_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::GnsNP_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::GnsNP_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::GnsNP_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::GnsNP_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::GnsNP_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::GnsNP_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::GnsNP_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::GnsNP_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::GnsNP_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__GnsNP
    std::shared_ptr<xsens_msgs::msg::GnsNP_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__GnsNP
    std::shared_ptr<xsens_msgs::msg::GnsNP_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GnsNP_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->fixtype != other.fixtype) {
      return false;
    }
    if (this->lon != other.lon) {
      return false;
    }
    if (this->lat != other.lat) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->h_msl != other.h_msl) {
      return false;
    }
    if (this->h_acc != other.h_acc) {
      return false;
    }
    if (this->v_acc != other.v_acc) {
      return false;
    }
    if (this->vel_n != other.vel_n) {
      return false;
    }
    if (this->vel_e != other.vel_e) {
      return false;
    }
    if (this->vel_d != other.vel_d) {
      return false;
    }
    if (this->s_acc != other.s_acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const GnsNP_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GnsNP_

// alias to use template instance with default allocator
using GnsNP =
  xsens_msgs::msg::GnsNP_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__GNS_NP__STRUCT_HPP_
