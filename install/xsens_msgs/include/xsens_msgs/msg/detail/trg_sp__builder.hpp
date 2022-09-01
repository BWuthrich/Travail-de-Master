// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/TrgSP.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__TRG_SP__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__TRG_SP__BUILDER_HPP_

#include "xsens_msgs/msg/detail/trg_sp__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_TrgSP_stamp
{
public:
  Init_TrgSP_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::xsens_msgs::msg::TrgSP stamp(::xsens_msgs::msg::TrgSP::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::TrgSP msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::TrgSP>()
{
  return xsens_msgs::msg::builder::Init_TrgSP_stamp();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__TRG_SP__BUILDER_HPP_
