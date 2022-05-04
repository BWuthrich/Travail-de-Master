// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/AccAA.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ACC_AA__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__ACC_AA__BUILDER_HPP_

#include "xsens_msgs/msg/detail/acc_aa__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_AccAA_accz
{
public:
  explicit Init_AccAA_accz(::xsens_msgs::msg::AccAA & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::AccAA accz(::xsens_msgs::msg::AccAA::_accz_type arg)
  {
    msg_.accz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::AccAA msg_;
};

class Init_AccAA_accy
{
public:
  explicit Init_AccAA_accy(::xsens_msgs::msg::AccAA & msg)
  : msg_(msg)
  {}
  Init_AccAA_accz accy(::xsens_msgs::msg::AccAA::_accy_type arg)
  {
    msg_.accy = std::move(arg);
    return Init_AccAA_accz(msg_);
  }

private:
  ::xsens_msgs::msg::AccAA msg_;
};

class Init_AccAA_accx
{
public:
  explicit Init_AccAA_accx(::xsens_msgs::msg::AccAA & msg)
  : msg_(msg)
  {}
  Init_AccAA_accy accx(::xsens_msgs::msg::AccAA::_accx_type arg)
  {
    msg_.accx = std::move(arg);
    return Init_AccAA_accy(msg_);
  }

private:
  ::xsens_msgs::msg::AccAA msg_;
};

class Init_AccAA_stamp
{
public:
  Init_AccAA_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AccAA_accx stamp(::xsens_msgs::msg::AccAA::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_AccAA_accx(msg_);
  }

private:
  ::xsens_msgs::msg::AccAA msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::AccAA>()
{
  return xsens_msgs::msg::builder::Init_AccAA_stamp();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__ACC_AA__BUILDER_HPP_
