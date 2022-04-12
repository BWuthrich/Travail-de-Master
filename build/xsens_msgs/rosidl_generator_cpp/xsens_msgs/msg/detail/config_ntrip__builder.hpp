// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/ConfigNtrip.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CONFIG_NTRIP__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__CONFIG_NTRIP__BUILDER_HPP_

#include "xsens_msgs/msg/detail/config_ntrip__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_ConfigNtrip_rtcm_timer
{
public:
  explicit Init_ConfigNtrip_rtcm_timer(::xsens_msgs::msg::ConfigNtrip & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::ConfigNtrip rtcm_timer(::xsens_msgs::msg::ConfigNtrip::_rtcm_timer_type arg)
  {
    msg_.rtcm_timer = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigNtrip msg_;
};

class Init_ConfigNtrip_rtcm_baudrate
{
public:
  explicit Init_ConfigNtrip_rtcm_baudrate(::xsens_msgs::msg::ConfigNtrip & msg)
  : msg_(msg)
  {}
  Init_ConfigNtrip_rtcm_timer rtcm_baudrate(::xsens_msgs::msg::ConfigNtrip::_rtcm_baudrate_type arg)
  {
    msg_.rtcm_baudrate = std::move(arg);
    return Init_ConfigNtrip_rtcm_timer(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigNtrip msg_;
};

class Init_ConfigNtrip_rtcm_port
{
public:
  explicit Init_ConfigNtrip_rtcm_port(::xsens_msgs::msg::ConfigNtrip & msg)
  : msg_(msg)
  {}
  Init_ConfigNtrip_rtcm_baudrate rtcm_port(::xsens_msgs::msg::ConfigNtrip::_rtcm_port_type arg)
  {
    msg_.rtcm_port = std::move(arg);
    return Init_ConfigNtrip_rtcm_baudrate(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigNtrip msg_;
};

class Init_ConfigNtrip_password
{
public:
  explicit Init_ConfigNtrip_password(::xsens_msgs::msg::ConfigNtrip & msg)
  : msg_(msg)
  {}
  Init_ConfigNtrip_rtcm_port password(::xsens_msgs::msg::ConfigNtrip::_password_type arg)
  {
    msg_.password = std::move(arg);
    return Init_ConfigNtrip_rtcm_port(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigNtrip msg_;
};

class Init_ConfigNtrip_username
{
public:
  explicit Init_ConfigNtrip_username(::xsens_msgs::msg::ConfigNtrip & msg)
  : msg_(msg)
  {}
  Init_ConfigNtrip_password username(::xsens_msgs::msg::ConfigNtrip::_username_type arg)
  {
    msg_.username = std::move(arg);
    return Init_ConfigNtrip_password(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigNtrip msg_;
};

class Init_ConfigNtrip_mountpoint
{
public:
  explicit Init_ConfigNtrip_mountpoint(::xsens_msgs::msg::ConfigNtrip & msg)
  : msg_(msg)
  {}
  Init_ConfigNtrip_username mountpoint(::xsens_msgs::msg::ConfigNtrip::_mountpoint_type arg)
  {
    msg_.mountpoint = std::move(arg);
    return Init_ConfigNtrip_username(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigNtrip msg_;
};

class Init_ConfigNtrip_port
{
public:
  explicit Init_ConfigNtrip_port(::xsens_msgs::msg::ConfigNtrip & msg)
  : msg_(msg)
  {}
  Init_ConfigNtrip_mountpoint port(::xsens_msgs::msg::ConfigNtrip::_port_type arg)
  {
    msg_.port = std::move(arg);
    return Init_ConfigNtrip_mountpoint(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigNtrip msg_;
};

class Init_ConfigNtrip_host
{
public:
  Init_ConfigNtrip_host()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigNtrip_port host(::xsens_msgs::msg::ConfigNtrip::_host_type arg)
  {
    msg_.host = std::move(arg);
    return Init_ConfigNtrip_port(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigNtrip msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::ConfigNtrip>()
{
  return xsens_msgs::msg::builder::Init_ConfigNtrip_host();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_NTRIP__BUILDER_HPP_
