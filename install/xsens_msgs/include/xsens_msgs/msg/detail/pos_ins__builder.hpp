// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/PosINS.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__POS_INS__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__POS_INS__BUILDER_HPP_

#include "xsens_msgs/msg/detail/pos_ins__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_PosINS_height
{
public:
  explicit Init_PosINS_height(::xsens_msgs::msg::PosINS & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::PosINS height(::xsens_msgs::msg::PosINS::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::PosINS msg_;
};

class Init_PosINS_lat
{
public:
  explicit Init_PosINS_lat(::xsens_msgs::msg::PosINS & msg)
  : msg_(msg)
  {}
  Init_PosINS_height lat(::xsens_msgs::msg::PosINS::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_PosINS_height(msg_);
  }

private:
  ::xsens_msgs::msg::PosINS msg_;
};

class Init_PosINS_lon
{
public:
  Init_PosINS_lon()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PosINS_lat lon(::xsens_msgs::msg::PosINS::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_PosINS_lat(msg_);
  }

private:
  ::xsens_msgs::msg::PosINS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::PosINS>()
{
  return xsens_msgs::msg::builder::Init_PosINS_lon();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__POS_INS__BUILDER_HPP_
