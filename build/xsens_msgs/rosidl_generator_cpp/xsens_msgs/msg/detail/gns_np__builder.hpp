// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/GnsNP.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__GNS_NP__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__GNS_NP__BUILDER_HPP_

#include "xsens_msgs/msg/detail/gns_np__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_GnsNP_s_acc
{
public:
  explicit Init_GnsNP_s_acc(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::GnsNP s_acc(::xsens_msgs::msg::GnsNP::_s_acc_type arg)
  {
    msg_.s_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_vel_d
{
public:
  explicit Init_GnsNP_vel_d(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_s_acc vel_d(::xsens_msgs::msg::GnsNP::_vel_d_type arg)
  {
    msg_.vel_d = std::move(arg);
    return Init_GnsNP_s_acc(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_vel_e
{
public:
  explicit Init_GnsNP_vel_e(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_vel_d vel_e(::xsens_msgs::msg::GnsNP::_vel_e_type arg)
  {
    msg_.vel_e = std::move(arg);
    return Init_GnsNP_vel_d(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_vel_n
{
public:
  explicit Init_GnsNP_vel_n(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_vel_e vel_n(::xsens_msgs::msg::GnsNP::_vel_n_type arg)
  {
    msg_.vel_n = std::move(arg);
    return Init_GnsNP_vel_e(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_v_acc
{
public:
  explicit Init_GnsNP_v_acc(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_vel_n v_acc(::xsens_msgs::msg::GnsNP::_v_acc_type arg)
  {
    msg_.v_acc = std::move(arg);
    return Init_GnsNP_vel_n(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_h_acc
{
public:
  explicit Init_GnsNP_h_acc(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_v_acc h_acc(::xsens_msgs::msg::GnsNP::_h_acc_type arg)
  {
    msg_.h_acc = std::move(arg);
    return Init_GnsNP_v_acc(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_h_msl
{
public:
  explicit Init_GnsNP_h_msl(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_h_acc h_msl(::xsens_msgs::msg::GnsNP::_h_msl_type arg)
  {
    msg_.h_msl = std::move(arg);
    return Init_GnsNP_h_acc(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_height
{
public:
  explicit Init_GnsNP_height(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_h_msl height(::xsens_msgs::msg::GnsNP::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_GnsNP_h_msl(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_lat
{
public:
  explicit Init_GnsNP_lat(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_height lat(::xsens_msgs::msg::GnsNP::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_GnsNP_height(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_lon
{
public:
  explicit Init_GnsNP_lon(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_lat lon(::xsens_msgs::msg::GnsNP::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_GnsNP_lat(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_fixtype
{
public:
  explicit Init_GnsNP_fixtype(::xsens_msgs::msg::GnsNP & msg)
  : msg_(msg)
  {}
  Init_GnsNP_lon fixtype(::xsens_msgs::msg::GnsNP::_fixtype_type arg)
  {
    msg_.fixtype = std::move(arg);
    return Init_GnsNP_lon(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

class Init_GnsNP_stamp
{
public:
  Init_GnsNP_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GnsNP_fixtype stamp(::xsens_msgs::msg::GnsNP::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_GnsNP_fixtype(msg_);
  }

private:
  ::xsens_msgs::msg::GnsNP msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::GnsNP>()
{
  return xsens_msgs::msg::builder::Init_GnsNP_stamp();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__GNS_NP__BUILDER_HPP_
