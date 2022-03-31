// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/ConfigNtrip.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CONFIG_NTRIP__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__CONFIG_NTRIP__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__ConfigNtrip __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__ConfigNtrip __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ConfigNtrip_
{
  using Type = ConfigNtrip_<ContainerAllocator>;

  explicit ConfigNtrip_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->host = "";
      this->port = 0;
      this->mountpoint = "";
      this->username = "";
      this->password = "";
      this->rtcm_timer = 0.0f;
    }
  }

  explicit ConfigNtrip_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : host(_alloc),
    mountpoint(_alloc),
    username(_alloc),
    password(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->host = "";
      this->port = 0;
      this->mountpoint = "";
      this->username = "";
      this->password = "";
      this->rtcm_timer = 0.0f;
    }
  }

  // field types and members
  using _host_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _host_type host;
  using _port_type =
    int16_t;
  _port_type port;
  using _mountpoint_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _mountpoint_type mountpoint;
  using _username_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _username_type username;
  using _password_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _password_type password;
  using _rtcm_timer_type =
    float;
  _rtcm_timer_type rtcm_timer;

  // setters for named parameter idiom
  Type & set__host(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->host = _arg;
    return *this;
  }
  Type & set__port(
    const int16_t & _arg)
  {
    this->port = _arg;
    return *this;
  }
  Type & set__mountpoint(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->mountpoint = _arg;
    return *this;
  }
  Type & set__username(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->username = _arg;
    return *this;
  }
  Type & set__password(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->password = _arg;
    return *this;
  }
  Type & set__rtcm_timer(
    const float & _arg)
  {
    this->rtcm_timer = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::ConfigNtrip_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::ConfigNtrip_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::ConfigNtrip_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::ConfigNtrip_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::ConfigNtrip_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::ConfigNtrip_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::ConfigNtrip_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::ConfigNtrip_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::ConfigNtrip_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::ConfigNtrip_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__ConfigNtrip
    std::shared_ptr<xsens_msgs::msg::ConfigNtrip_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__ConfigNtrip
    std::shared_ptr<xsens_msgs::msg::ConfigNtrip_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigNtrip_ & other) const
  {
    if (this->host != other.host) {
      return false;
    }
    if (this->port != other.port) {
      return false;
    }
    if (this->mountpoint != other.mountpoint) {
      return false;
    }
    if (this->username != other.username) {
      return false;
    }
    if (this->password != other.password) {
      return false;
    }
    if (this->rtcm_timer != other.rtcm_timer) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigNtrip_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigNtrip_

// alias to use template instance with default allocator
using ConfigNtrip =
  xsens_msgs::msg::ConfigNtrip_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_NTRIP__STRUCT_HPP_
