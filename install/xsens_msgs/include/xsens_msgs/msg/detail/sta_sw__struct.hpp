// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/StaSW.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_SW__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__STA_SW__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__StaSW __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__StaSW __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StaSW_
{
  using Type = StaSW_<ContainerAllocator>;

  explicit StaSW_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filter_valid = "";
      this->gnss_fix = "";
      this->clock_sync = "";
      this->sync_in = "";
      this->sync_out = "";
      this->filter_mode = "";
      this->rtk_status = "";
    }
  }

  explicit StaSW_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : filter_valid(_alloc),
    gnss_fix(_alloc),
    clock_sync(_alloc),
    sync_in(_alloc),
    sync_out(_alloc),
    filter_mode(_alloc),
    rtk_status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filter_valid = "";
      this->gnss_fix = "";
      this->clock_sync = "";
      this->sync_in = "";
      this->sync_out = "";
      this->filter_mode = "";
      this->rtk_status = "";
    }
  }

  // field types and members
  using _filter_valid_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _filter_valid_type filter_valid;
  using _gnss_fix_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _gnss_fix_type gnss_fix;
  using _clock_sync_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _clock_sync_type clock_sync;
  using _sync_in_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _sync_in_type sync_in;
  using _sync_out_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _sync_out_type sync_out;
  using _filter_mode_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _filter_mode_type filter_mode;
  using _rtk_status_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _rtk_status_type rtk_status;

  // setters for named parameter idiom
  Type & set__filter_valid(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->filter_valid = _arg;
    return *this;
  }
  Type & set__gnss_fix(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->gnss_fix = _arg;
    return *this;
  }
  Type & set__clock_sync(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->clock_sync = _arg;
    return *this;
  }
  Type & set__sync_in(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->sync_in = _arg;
    return *this;
  }
  Type & set__sync_out(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->sync_out = _arg;
    return *this;
  }
  Type & set__filter_mode(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->filter_mode = _arg;
    return *this;
  }
  Type & set__rtk_status(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->rtk_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::StaSW_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::StaSW_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::StaSW_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::StaSW_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::StaSW_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::StaSW_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::StaSW_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::StaSW_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::StaSW_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::StaSW_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__StaSW
    std::shared_ptr<xsens_msgs::msg::StaSW_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__StaSW
    std::shared_ptr<xsens_msgs::msg::StaSW_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StaSW_ & other) const
  {
    if (this->filter_valid != other.filter_valid) {
      return false;
    }
    if (this->gnss_fix != other.gnss_fix) {
      return false;
    }
    if (this->clock_sync != other.clock_sync) {
      return false;
    }
    if (this->sync_in != other.sync_in) {
      return false;
    }
    if (this->sync_out != other.sync_out) {
      return false;
    }
    if (this->filter_mode != other.filter_mode) {
      return false;
    }
    if (this->rtk_status != other.rtk_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const StaSW_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StaSW_

// alias to use template instance with default allocator
using StaSW =
  xsens_msgs::msg::StaSW_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__STA_SW__STRUCT_HPP_
