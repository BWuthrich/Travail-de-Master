// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/RTCMcorr.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__RTC_MCORR__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__RTC_MCORR__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__RTCMcorr __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__RTCMcorr __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RTCMcorr_
{
  using Type = RTCMcorr_<ContainerAllocator>;

  explicit RTCMcorr_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit RTCMcorr_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _rtcm_data_type =
    std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other>;
  _rtcm_data_type rtcm_data;
  using _layout_type =
    std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other>;
  _layout_type layout;

  // setters for named parameter idiom
  Type & set__rtcm_data(
    const std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other> & _arg)
  {
    this->rtcm_data = _arg;
    return *this;
  }
  Type & set__layout(
    const std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other> & _arg)
  {
    this->layout = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::RTCMcorr_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::RTCMcorr_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::RTCMcorr_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::RTCMcorr_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::RTCMcorr_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::RTCMcorr_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::RTCMcorr_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::RTCMcorr_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::RTCMcorr_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::RTCMcorr_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__RTCMcorr
    std::shared_ptr<xsens_msgs::msg::RTCMcorr_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__RTCMcorr
    std::shared_ptr<xsens_msgs::msg::RTCMcorr_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RTCMcorr_ & other) const
  {
    if (this->rtcm_data != other.rtcm_data) {
      return false;
    }
    if (this->layout != other.layout) {
      return false;
    }
    return true;
  }
  bool operator!=(const RTCMcorr_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RTCMcorr_

// alias to use template instance with default allocator
using RTCMcorr =
  xsens_msgs::msg::RTCMcorr_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__RTC_MCORR__STRUCT_HPP_
