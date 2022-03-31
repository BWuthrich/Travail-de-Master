// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:srv/RTCMdata.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__SRV__DETAIL__RTC_MDATA__BUILDER_HPP_
#define XSENS_MSGS__SRV__DETAIL__RTC_MDATA__BUILDER_HPP_

#include "xsens_msgs/srv/detail/rtc_mdata__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace srv
{

namespace builder
{

class Init_RTCMdata_Request_alti_ell
{
public:
  explicit Init_RTCMdata_Request_alti_ell(::xsens_msgs::srv::RTCMdata_Request & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::srv::RTCMdata_Request alti_ell(::xsens_msgs::srv::RTCMdata_Request::_alti_ell_type arg)
  {
    msg_.alti_ell = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::srv::RTCMdata_Request msg_;
};

class Init_RTCMdata_Request_latitude
{
public:
  explicit Init_RTCMdata_Request_latitude(::xsens_msgs::srv::RTCMdata_Request & msg)
  : msg_(msg)
  {}
  Init_RTCMdata_Request_alti_ell latitude(::xsens_msgs::srv::RTCMdata_Request::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_RTCMdata_Request_alti_ell(msg_);
  }

private:
  ::xsens_msgs::srv::RTCMdata_Request msg_;
};

class Init_RTCMdata_Request_longitude
{
public:
  Init_RTCMdata_Request_longitude()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RTCMdata_Request_latitude longitude(::xsens_msgs::srv::RTCMdata_Request::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_RTCMdata_Request_latitude(msg_);
  }

private:
  ::xsens_msgs::srv::RTCMdata_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::srv::RTCMdata_Request>()
{
  return xsens_msgs::srv::builder::Init_RTCMdata_Request_longitude();
}

}  // namespace xsens_msgs


namespace xsens_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::srv::RTCMdata_Response>()
{
  return ::xsens_msgs::srv::RTCMdata_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__SRV__DETAIL__RTC_MDATA__BUILDER_HPP_
