// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xsens_msgs:msg/AttINS.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__ATT_INS__TRAITS_HPP_
#define XSENS_MSGS__MSG__DETAIL__ATT_INS__TRAITS_HPP_

#include "xsens_msgs/msg/detail/att_ins__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<xsens_msgs::msg::AttINS>()
{
  return "xsens_msgs::msg::AttINS";
}

template<>
inline const char * name<xsens_msgs::msg::AttINS>()
{
  return "xsens_msgs/msg/AttINS";
}

template<>
struct has_fixed_size<xsens_msgs::msg::AttINS>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xsens_msgs::msg::AttINS>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xsens_msgs::msg::AttINS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XSENS_MSGS__MSG__DETAIL__ATT_INS__TRAITS_HPP_
