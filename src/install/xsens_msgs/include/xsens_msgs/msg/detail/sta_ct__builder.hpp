// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/StaCT.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_CT__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__STA_CT__BUILDER_HPP_

#include "xsens_msgs/msg/detail/sta_ct__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_StaCT_cam_status
{
public:
  Init_StaCT_cam_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::xsens_msgs::msg::StaCT cam_status(::xsens_msgs::msg::StaCT::_cam_status_type arg)
  {
    msg_.cam_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::StaCT msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::StaCT>()
{
  return xsens_msgs::msg::builder::Init_StaCT_cam_status();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__STA_CT__BUILDER_HPP_
