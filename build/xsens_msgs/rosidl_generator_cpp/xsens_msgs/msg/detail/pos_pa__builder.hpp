// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/PosPA.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__POS_PA__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__POS_PA__BUILDER_HPP_

#include "xsens_msgs/msg/detail/pos_pa__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_PosPA_alt_ell
{
public:
  Init_PosPA_alt_ell()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::xsens_msgs::msg::PosPA alt_ell(::xsens_msgs::msg::PosPA::_alt_ell_type arg)
  {
    msg_.alt_ell = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::PosPA msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::PosPA>()
{
  return xsens_msgs::msg::builder::Init_PosPA_alt_ell();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__POS_PA__BUILDER_HPP_
