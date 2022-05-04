// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/AccAF.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ACC_AF__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__ACC_AF__BUILDER_HPP_

#include "xsens_msgs/msg/detail/acc_af__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_AccAF_accz
{
public:
  explicit Init_AccAF_accz(::xsens_msgs::msg::AccAF & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::AccAF accz(::xsens_msgs::msg::AccAF::_accz_type arg)
  {
    msg_.accz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::AccAF msg_;
};

class Init_AccAF_accy
{
public:
  explicit Init_AccAF_accy(::xsens_msgs::msg::AccAF & msg)
  : msg_(msg)
  {}
  Init_AccAF_accz accy(::xsens_msgs::msg::AccAF::_accy_type arg)
  {
    msg_.accy = std::move(arg);
    return Init_AccAF_accz(msg_);
  }

private:
  ::xsens_msgs::msg::AccAF msg_;
};

class Init_AccAF_accx
{
public:
  explicit Init_AccAF_accx(::xsens_msgs::msg::AccAF & msg)
  : msg_(msg)
  {}
  Init_AccAF_accy accx(::xsens_msgs::msg::AccAF::_accx_type arg)
  {
    msg_.accx = std::move(arg);
    return Init_AccAF_accy(msg_);
  }

private:
  ::xsens_msgs::msg::AccAF msg_;
};

class Init_AccAF_stamp
{
public:
  Init_AccAF_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AccAF_accx stamp(::xsens_msgs::msg::AccAF::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_AccAF_accx(msg_);
  }

private:
  ::xsens_msgs::msg::AccAF msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::AccAF>()
{
  return xsens_msgs::msg::builder::Init_AccAF_stamp();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__ACC_AF__BUILDER_HPP_
