// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/CamImage.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CAM_IMAGE__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__CAM_IMAGE__BUILDER_HPP_

#include "xsens_msgs/msg/detail/cam_image__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_CamImage_data
{
public:
  explicit Init_CamImage_data(::xsens_msgs::msg::CamImage & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::CamImage data(::xsens_msgs::msg::CamImage::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::CamImage msg_;
};

class Init_CamImage_stamp
{
public:
  explicit Init_CamImage_stamp(::xsens_msgs::msg::CamImage & msg)
  : msg_(msg)
  {}
  Init_CamImage_data stamp(::xsens_msgs::msg::CamImage::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_CamImage_data(msg_);
  }

private:
  ::xsens_msgs::msg::CamImage msg_;
};

class Init_CamImage_cam_id
{
public:
  Init_CamImage_cam_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CamImage_stamp cam_id(::xsens_msgs::msg::CamImage::_cam_id_type arg)
  {
    msg_.cam_id = std::move(arg);
    return Init_CamImage_stamp(msg_);
  }

private:
  ::xsens_msgs::msg::CamImage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::CamImage>()
{
  return xsens_msgs::msg::builder::Init_CamImage_cam_id();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CAM_IMAGE__BUILDER_HPP_
