// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/AngWR.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ANG_WR__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__ANG_WR__BUILDER_HPP_

#include "xsens_msgs/msg/detail/ang_wr__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_AngWR_gyrz
{
public:
  explicit Init_AngWR_gyrz(::xsens_msgs::msg::AngWR & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::AngWR gyrz(::xsens_msgs::msg::AngWR::_gyrz_type arg)
  {
    msg_.gyrz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::AngWR msg_;
};

class Init_AngWR_gyry
{
public:
  explicit Init_AngWR_gyry(::xsens_msgs::msg::AngWR & msg)
  : msg_(msg)
  {}
  Init_AngWR_gyrz gyry(::xsens_msgs::msg::AngWR::_gyry_type arg)
  {
    msg_.gyry = std::move(arg);
    return Init_AngWR_gyrz(msg_);
  }

private:
  ::xsens_msgs::msg::AngWR msg_;
};

class Init_AngWR_gyrx
{
public:
  explicit Init_AngWR_gyrx(::xsens_msgs::msg::AngWR & msg)
  : msg_(msg)
  {}
  Init_AngWR_gyry gyrx(::xsens_msgs::msg::AngWR::_gyrx_type arg)
  {
    msg_.gyrx = std::move(arg);
    return Init_AngWR_gyry(msg_);
  }

private:
  ::xsens_msgs::msg::AngWR msg_;
};

class Init_AngWR_stamp
{
public:
  Init_AngWR_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AngWR_gyrx stamp(::xsens_msgs::msg::AngWR::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_AngWR_gyrx(msg_);
  }

private:
  ::xsens_msgs::msg::AngWR msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::AngWR>()
{
  return xsens_msgs::msg::builder::Init_AngWR_stamp();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__ANG_WR__BUILDER_HPP_
