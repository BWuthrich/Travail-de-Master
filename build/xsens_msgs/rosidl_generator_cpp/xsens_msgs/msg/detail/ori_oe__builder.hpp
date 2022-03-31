// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/OriOE.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ORI_OE__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__ORI_OE__BUILDER_HPP_

#include "xsens_msgs/msg/detail/ori_oe__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_OriOE_yaw
{
public:
  explicit Init_OriOE_yaw(::xsens_msgs::msg::OriOE & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::OriOE yaw(::xsens_msgs::msg::OriOE::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::OriOE msg_;
};

class Init_OriOE_pitch
{
public:
  explicit Init_OriOE_pitch(::xsens_msgs::msg::OriOE & msg)
  : msg_(msg)
  {}
  Init_OriOE_yaw pitch(::xsens_msgs::msg::OriOE::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_OriOE_yaw(msg_);
  }

private:
  ::xsens_msgs::msg::OriOE msg_;
};

class Init_OriOE_roll
{
public:
  Init_OriOE_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OriOE_pitch roll(::xsens_msgs::msg::OriOE::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_OriOE_pitch(msg_);
  }

private:
  ::xsens_msgs::msg::OriOE msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::OriOE>()
{
  return xsens_msgs::msg::builder::Init_OriOE_roll();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__ORI_OE__BUILDER_HPP_
