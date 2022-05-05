// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xsens_msgs:msg/StaCT.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__STA_CT__TRAITS_HPP_
#define XSENS_MSGS__MSG__DETAIL__STA_CT__TRAITS_HPP_

#include "xsens_msgs/msg/detail/sta_ct__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<xsens_msgs::msg::StaCT>()
{
  return "xsens_msgs::msg::StaCT";
}

template<>
inline const char * name<xsens_msgs::msg::StaCT>()
{
  return "xsens_msgs/msg/StaCT";
}

template<>
struct has_fixed_size<xsens_msgs::msg::StaCT>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<xsens_msgs::msg::StaCT>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<xsens_msgs::msg::StaCT>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XSENS_MSGS__MSG__DETAIL__STA_CT__TRAITS_HPP_
