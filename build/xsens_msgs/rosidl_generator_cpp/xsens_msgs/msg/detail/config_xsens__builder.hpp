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

class Init_ConfigXsens_dt_freq
{
public:
  explicit Init_ConfigXsens_dt_freq(::xsens_msgs::msg::ConfigXsens & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::ConfigXsens dt_freq(::xsens_msgs::msg::ConfigXsens::_dt_freq_type arg)
  {
    msg_.dt_freq = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigXsens msg_;
};

class Init_ConfigXsens_sync_config
{
public:
  explicit Init_ConfigXsens_sync_config(::xsens_msgs::msg::ConfigXsens & msg)
  : msg_(msg)
  {}
  Init_ConfigXsens_dt_freq sync_config(::xsens_msgs::msg::ConfigXsens::_sync_config_type arg)
  {
    msg_.sync_config = std::move(arg);
    return Init_ConfigXsens_dt_freq(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigXsens msg_;
};

class Init_ConfigXsens_rtcm_refresh_dist
{
public:
  explicit Init_ConfigXsens_rtcm_refresh_dist(::xsens_msgs::msg::ConfigXsens & msg)
  : msg_(msg)
  {}
  Init_ConfigXsens_sync_config rtcm_refresh_dist(::xsens_msgs::msg::ConfigXsens::_rtcm_refresh_dist_type arg)
  {
    msg_.rtcm_refresh_dist = std::move(arg);
    return Init_ConfigXsens_sync_config(msg_);
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

class Init_ConfigXsens_output_config
{
public:
  Init_ConfigXsens_output_config()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigXsens_baudrate output_config(::xsens_msgs::msg::ConfigXsens::_output_config_type arg)
  {
    msg_.output_config = std::move(arg);
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
  return xsens_msgs::msg::builder::Init_ConfigXsens_output_config();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_XSENS__BUILDER_HPP_
