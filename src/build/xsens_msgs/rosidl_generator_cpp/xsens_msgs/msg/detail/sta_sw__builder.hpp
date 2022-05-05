// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/StaSW.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_SW__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__STA_SW__BUILDER_HPP_

#include "xsens_msgs/msg/detail/sta_sw__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_StaSW_rtk_status
{
public:
  explicit Init_StaSW_rtk_status(::xsens_msgs::msg::StaSW & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::StaSW rtk_status(::xsens_msgs::msg::StaSW::_rtk_status_type arg)
  {
    msg_.rtk_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::StaSW msg_;
};

class Init_StaSW_filter_mode
{
public:
  explicit Init_StaSW_filter_mode(::xsens_msgs::msg::StaSW & msg)
  : msg_(msg)
  {}
  Init_StaSW_rtk_status filter_mode(::xsens_msgs::msg::StaSW::_filter_mode_type arg)
  {
    msg_.filter_mode = std::move(arg);
    return Init_StaSW_rtk_status(msg_);
  }

private:
  ::xsens_msgs::msg::StaSW msg_;
};

class Init_StaSW_sync_out
{
public:
  explicit Init_StaSW_sync_out(::xsens_msgs::msg::StaSW & msg)
  : msg_(msg)
  {}
  Init_StaSW_filter_mode sync_out(::xsens_msgs::msg::StaSW::_sync_out_type arg)
  {
    msg_.sync_out = std::move(arg);
    return Init_StaSW_filter_mode(msg_);
  }

private:
  ::xsens_msgs::msg::StaSW msg_;
};

class Init_StaSW_sync_in
{
public:
  explicit Init_StaSW_sync_in(::xsens_msgs::msg::StaSW & msg)
  : msg_(msg)
  {}
  Init_StaSW_sync_out sync_in(::xsens_msgs::msg::StaSW::_sync_in_type arg)
  {
    msg_.sync_in = std::move(arg);
    return Init_StaSW_sync_out(msg_);
  }

private:
  ::xsens_msgs::msg::StaSW msg_;
};

class Init_StaSW_clock_sync
{
public:
  explicit Init_StaSW_clock_sync(::xsens_msgs::msg::StaSW & msg)
  : msg_(msg)
  {}
  Init_StaSW_sync_in clock_sync(::xsens_msgs::msg::StaSW::_clock_sync_type arg)
  {
    msg_.clock_sync = std::move(arg);
    return Init_StaSW_sync_in(msg_);
  }

private:
  ::xsens_msgs::msg::StaSW msg_;
};

class Init_StaSW_gnss_fix
{
public:
  explicit Init_StaSW_gnss_fix(::xsens_msgs::msg::StaSW & msg)
  : msg_(msg)
  {}
  Init_StaSW_clock_sync gnss_fix(::xsens_msgs::msg::StaSW::_gnss_fix_type arg)
  {
    msg_.gnss_fix = std::move(arg);
    return Init_StaSW_clock_sync(msg_);
  }

private:
  ::xsens_msgs::msg::StaSW msg_;
};

class Init_StaSW_filter_valid
{
public:
  explicit Init_StaSW_filter_valid(::xsens_msgs::msg::StaSW & msg)
  : msg_(msg)
  {}
  Init_StaSW_gnss_fix filter_valid(::xsens_msgs::msg::StaSW::_filter_valid_type arg)
  {
    msg_.filter_valid = std::move(arg);
    return Init_StaSW_gnss_fix(msg_);
  }

private:
  ::xsens_msgs::msg::StaSW msg_;
};

class Init_StaSW_xsens_status
{
public:
  Init_StaSW_xsens_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StaSW_filter_valid xsens_status(::xsens_msgs::msg::StaSW::_xsens_status_type arg)
  {
    msg_.xsens_status = std::move(arg);
    return Init_StaSW_filter_valid(msg_);
  }

private:
  ::xsens_msgs::msg::StaSW msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::StaSW>()
{
  return xsens_msgs::msg::builder::Init_StaSW_xsens_status();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__STA_SW__BUILDER_HPP_
