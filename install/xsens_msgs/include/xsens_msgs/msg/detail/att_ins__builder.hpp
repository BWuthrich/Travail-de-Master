// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/AttINS.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ATT_INS__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__ATT_INS__BUILDER_HPP_

#include "xsens_msgs/msg/detail/att_ins__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_AttINS_yaw
{
public:
  explicit Init_AttINS_yaw(::xsens_msgs::msg::AttINS & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::AttINS yaw(::xsens_msgs::msg::AttINS::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::AttINS msg_;
};

class Init_AttINS_pitch
{
public:
  explicit Init_AttINS_pitch(::xsens_msgs::msg::AttINS & msg)
  : msg_(msg)
  {}
  Init_AttINS_yaw pitch(::xsens_msgs::msg::AttINS::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_AttINS_yaw(msg_);
  }

private:
  ::xsens_msgs::msg::AttINS msg_;
};

class Init_AttINS_roll
{
public:
  Init_AttINS_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AttINS_pitch roll(::xsens_msgs::msg::AttINS::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_AttINS_pitch(msg_);
  }

private:
  ::xsens_msgs::msg::AttINS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::AttINS>()
{
  return xsens_msgs::msg::builder::Init_AttINS_roll();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__ATT_INS__BUILDER_HPP_
