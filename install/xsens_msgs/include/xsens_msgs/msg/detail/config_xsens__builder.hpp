// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/ConfigXsens.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__BUILDER_HPP_

#include "xsens_msgs/msg/detail/config_xsens__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_ConfigXsens_rtcm_refresh_dist
{
public:
  explicit Init_ConfigXsens_rtcm_refresh_dist(::xsens_msgs::msg::ConfigXsens & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::ConfigXsens rtcm_refresh_dist(::xsens_msgs::msg::ConfigXsens::_rtcm_refresh_dist_type arg)
  {
    msg_.rtcm_refresh_dist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigXsens msg_;
};

class Init_ConfigXsens_port_name
{
public:
  explicit Init_ConfigXsens_port_name(::xsens_msgs::msg::ConfigXsens & msg)
  : msg_(msg)
  {}
  Init_ConfigXsens_rtcm_refresh_dist port_name(::xsens_msgs::msg::ConfigXsens::_port_name_type arg)
  {
    msg_.port_name = std::move(arg);
    return Init_ConfigXsens_rtcm_refresh_dist(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigXsens msg_;
};

class Init_ConfigXsens_baudrate
{
public:
  explicit Init_ConfigXsens_baudrate(::xsens_msgs::msg::ConfigXsens & msg)
  : msg_(msg)
  {}
  Init_ConfigXsens_port_name baudrate(::xsens_msgs::msg::ConfigXsens::_baudrate_type arg)
  {
    msg_.baudrate = std::move(arg);
    return Init_ConfigXsens_port_name(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigXsens msg_;
};

class Init_ConfigXsens_configuration
{
public:
  Init_ConfigXsens_configuration()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigXsens_baudrate configuration(::xsens_msgs::msg::ConfigXsens::_configuration_type arg)
  {
    msg_.configuration = std::move(arg);
    return Init_ConfigXsens_baudrate(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigXsens msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::ConfigXsens>()
{
  return xsens_msgs::msg::builder::Init_ConfigXsens_configuration();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__BUILDER_HPP_
