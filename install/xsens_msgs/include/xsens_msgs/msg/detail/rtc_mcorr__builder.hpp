// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/RTCMcorr.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__RTC_MCORR__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__RTC_MCORR__BUILDER_HPP_

#include "xsens_msgs/msg/detail/rtc_mcorr__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_RTCMcorr_layout
{
public:
  explicit Init_RTCMcorr_layout(::xsens_msgs::msg::RTCMcorr & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::RTCMcorr layout(::xsens_msgs::msg::RTCMcorr::_layout_type arg)
  {
    msg_.layout = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::RTCMcorr msg_;
};

class Init_RTCMcorr_rtcm_data
{
public:
  Init_RTCMcorr_rtcm_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RTCMcorr_layout rtcm_data(::xsens_msgs::msg::RTCMcorr::_rtcm_data_type arg)
  {
    msg_.rtcm_data = std::move(arg);
    return Init_RTCMcorr_layout(msg_);
  }

private:
  ::xsens_msgs::msg::RTCMcorr msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::RTCMcorr>()
{
  return xsens_msgs::msg::builder::Init_RTCMcorr_rtcm_data();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__RTC_MCORR__BUILDER_HPP_
