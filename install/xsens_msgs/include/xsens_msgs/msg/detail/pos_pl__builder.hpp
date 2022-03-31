// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/PosPL.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__POS_PL__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__POS_PL__BUILDER_HPP_

#include "xsens_msgs/msg/detail/pos_pl__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_PosPL_latitude
{
public:
  explicit Init_PosPL_latitude(::xsens_msgs::msg::PosPL & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::PosPL latitude(::xsens_msgs::msg::PosPL::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::PosPL msg_;
};

class Init_PosPL_longitude
{
public:
  Init_PosPL_longitude()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PosPL_latitude longitude(::xsens_msgs::msg::PosPL::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_PosPL_latitude(msg_);
  }

private:
  ::xsens_msgs::msg::PosPL msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::PosPL>()
{
  return xsens_msgs::msg::builder::Init_PosPL_longitude();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__POS_PL__BUILDER_HPP_
