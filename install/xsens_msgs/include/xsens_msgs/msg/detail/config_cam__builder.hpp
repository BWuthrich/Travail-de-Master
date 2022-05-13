// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/ConfigCam.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CONFIG_CAM__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__CONFIG_CAM__BUILDER_HPP_

#include "xsens_msgs/msg/detail/config_cam__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_ConfigCam_stream
{
public:
  explicit Init_ConfigCam_stream(::xsens_msgs::msg::ConfigCam & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::ConfigCam stream(::xsens_msgs::msg::ConfigCam::_stream_type arg)
  {
    msg_.stream = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigCam msg_;
};

class Init_ConfigCam_save_file
{
public:
  explicit Init_ConfigCam_save_file(::xsens_msgs::msg::ConfigCam & msg)
  : msg_(msg)
  {}
  Init_ConfigCam_stream save_file(::xsens_msgs::msg::ConfigCam::_save_file_type arg)
  {
    msg_.save_file = std::move(arg);
    return Init_ConfigCam_stream(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigCam msg_;
};

class Init_ConfigCam_framerate
{
public:
  explicit Init_ConfigCam_framerate(::xsens_msgs::msg::ConfigCam & msg)
  : msg_(msg)
  {}
  Init_ConfigCam_save_file framerate(::xsens_msgs::msg::ConfigCam::_framerate_type arg)
  {
    msg_.framerate = std::move(arg);
    return Init_ConfigCam_save_file(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigCam msg_;
};

class Init_ConfigCam_width
{
public:
  explicit Init_ConfigCam_width(::xsens_msgs::msg::ConfigCam & msg)
  : msg_(msg)
  {}
  Init_ConfigCam_framerate width(::xsens_msgs::msg::ConfigCam::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ConfigCam_framerate(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigCam msg_;
};

class Init_ConfigCam_height
{
public:
  Init_ConfigCam_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigCam_width height(::xsens_msgs::msg::ConfigCam::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ConfigCam_width(msg_);
  }

private:
  ::xsens_msgs::msg::ConfigCam msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::ConfigCam>()
{
  return xsens_msgs::msg::builder::Init_ConfigCam_height();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_CAM__BUILDER_HPP_
