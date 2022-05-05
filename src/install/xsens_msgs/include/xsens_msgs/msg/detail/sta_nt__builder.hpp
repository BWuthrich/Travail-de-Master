// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/StaNT.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_NT__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__STA_NT__BUILDER_HPP_

#include "xsens_msgs/msg/detail/sta_nt__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_StaNT_rtcm_status
{
public:
  explicit Init_StaNT_rtcm_status(::xsens_msgs::msg::StaNT & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::StaNT rtcm_status(::xsens_msgs::msg::StaNT::_rtcm_status_type arg)
  {
    msg_.rtcm_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::StaNT msg_;
};

class Init_StaNT_ntrip_status
{
public:
  Init_StaNT_ntrip_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StaNT_rtcm_status ntrip_status(::xsens_msgs::msg::StaNT::_ntrip_status_type arg)
  {
    msg_.ntrip_status = std::move(arg);
    return Init_StaNT_rtcm_status(msg_);
  }

private:
  ::xsens_msgs::msg::StaNT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::StaNT>()
{
  return xsens_msgs::msg::builder::Init_StaNT_ntrip_status();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__STA_NT__BUILDER_HPP_
