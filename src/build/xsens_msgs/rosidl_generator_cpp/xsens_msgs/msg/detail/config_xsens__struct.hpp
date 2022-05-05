// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/ConfigXsens.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__ConfigXsens __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__ConfigXsens __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ConfigXsens_
{
  using Type = ConfigXsens_<ContainerAllocator>;

  explicit ConfigXsens_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output_config = "";
      this->baudrate = 0ul;
      this->port_name = "";
      this->rtcm_refresh_dist = 0;
      this->dt_freq = 0.0;
    }
  }

  explicit ConfigXsens_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : output_config(_alloc),
    port_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output_config = "";
      this->baudrate = 0ul;
      this->port_name = "";
      this->rtcm_refresh_dist = 0;
      this->dt_freq = 0.0;
    }
  }

  // field types and members
  using _output_config_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _output_config_type output_config;
  using _baudrate_type =
    uint32_t;
  _baudrate_type baudrate;
  using _port_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _port_name_type port_name;
  using _rtcm_refresh_dist_type =
    uint16_t;
  _rtcm_refresh_dist_type rtcm_refresh_dist;
  using _sync_config_type =
    std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other>;
  _sync_config_type sync_config;
  using _dt_freq_type =
    double;
  _dt_freq_type dt_freq;

  // setters for named parameter idiom
  Type & set__output_config(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->output_config = _arg;
    return *this;
  }
  Type & set__baudrate(
    const uint32_t & _arg)
  {
    this->baudrate = _arg;
    return *this;
  }
  Type & set__port_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->port_name = _arg;
    return *this;
  }
  Type & set__rtcm_refresh_dist(
    const uint16_t & _arg)
  {
    this->rtcm_refresh_dist = _arg;
    return *this;
  }
  Type & set__sync_config(
    const std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other> & _arg)
  {
    this->sync_config = _arg;
    return *this;
  }
  Type & set__dt_freq(
    const double & _arg)
  {
    this->dt_freq = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::ConfigXsens_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::ConfigXsens_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::ConfigXsens_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::ConfigXsens_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::ConfigXsens_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::ConfigXsens_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::ConfigXsens_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::ConfigXsens_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::ConfigXsens_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::ConfigXsens_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__ConfigXsens
    std::shared_ptr<xsens_msgs::msg::ConfigXsens_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__ConfigXsens
    std::shared_ptr<xsens_msgs::msg::ConfigXsens_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigXsens_ & other) const
  {
    if (this->output_config != other.output_config) {
      return false;
    }
    if (this->baudrate != other.baudrate) {
      return false;
    }
    if (this->port_name != other.port_name) {
      return false;
    }
    if (this->rtcm_refresh_dist != other.rtcm_refresh_dist) {
      return false;
    }
    if (this->sync_config != other.sync_config) {
      return false;
    }
    if (this->dt_freq != other.dt_freq) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigXsens_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigXsens_

// alias to use template instance with default allocator
using ConfigXsens =
  xsens_msgs::msg::ConfigXsens_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__STRUCT_HPP_
