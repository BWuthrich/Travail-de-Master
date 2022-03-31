// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xsens_msgs:srv/RTCMdata.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__SRV__DETAIL__RTC_MDATA__TRAITS_HPP_
#define XSENS_MSGS__SRV__DETAIL__RTC_MDATA__TRAITS_HPP_

#include "xsens_msgs/srv/detail/rtc_mdata__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<xsens_msgs::srv::RTCMdata_Request>()
{
  return "xsens_msgs::srv::RTCMdata_Request";
}

template<>
inline const char * name<xsens_msgs::srv::RTCMdata_Request>()
{
  return "xsens_msgs/srv/RTCMdata_Request";
}

template<>
struct has_fixed_size<xsens_msgs::srv::RTCMdata_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xsens_msgs::srv::RTCMdata_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xsens_msgs::srv::RTCMdata_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<xsens_msgs::srv::RTCMdata_Response>()
{
  return "xsens_msgs::srv::RTCMdata_Response";
}

template<>
inline const char * name<xsens_msgs::srv::RTCMdata_Response>()
{
  return "xsens_msgs/srv/RTCMdata_Response";
}

template<>
struct has_fixed_size<xsens_msgs::srv::RTCMdata_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xsens_msgs::srv::RTCMdata_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xsens_msgs::srv::RTCMdata_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<xsens_msgs::srv::RTCMdata>()
{
  return "xsens_msgs::srv::RTCMdata";
}

template<>
inline const char * name<xsens_msgs::srv::RTCMdata>()
{
  return "xsens_msgs/srv/RTCMdata";
}

template<>
struct has_fixed_size<xsens_msgs::srv::RTCMdata>
  : std::integral_constant<
    bool,
    has_fixed_size<xsens_msgs::srv::RTCMdata_Request>::value &&
    has_fixed_size<xsens_msgs::srv::RTCMdata_Response>::value
  >
{
};

template<>
struct has_bounded_size<xsens_msgs::srv::RTCMdata>
  : std::integral_constant<
    bool,
    has_bounded_size<xsens_msgs::srv::RTCMdata_Request>::value &&
    has_bounded_size<xsens_msgs::srv::RTCMdata_Response>::value
  >
{
};

template<>
struct is_service<xsens_msgs::srv::RTCMdata>
  : std::true_type
{
};

template<>
struct is_service_request<xsens_msgs::srv::RTCMdata_Request>
  : std::true_type
{
};

template<>
struct is_service_response<xsens_msgs::srv::RTCMdata_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // XSENS_MSGS__SRV__DETAIL__RTC_MDATA__TRAITS_HPP_
