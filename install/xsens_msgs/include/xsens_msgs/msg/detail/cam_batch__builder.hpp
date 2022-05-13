// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xsens_msgs:msg/CamBatch.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CAM_BATCH__BUILDER_HPP_
#define XSENS_MSGS__MSG__DETAIL__CAM_BATCH__BUILDER_HPP_

#include "xsens_msgs/msg/detail/cam_batch__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace xsens_msgs
{

namespace msg
{

namespace builder
{

class Init_CamBatch_data
{
public:
  explicit Init_CamBatch_data(::xsens_msgs::msg::CamBatch & msg)
  : msg_(msg)
  {}
  ::xsens_msgs::msg::CamBatch data(::xsens_msgs::msg::CamBatch::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xsens_msgs::msg::CamBatch msg_;
};

class Init_CamBatch_stamp
{
public:
  Init_CamBatch_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CamBatch_data stamp(::xsens_msgs::msg::CamBatch::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_CamBatch_data(msg_);
  }

private:
  ::xsens_msgs::msg::CamBatch msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xsens_msgs::msg::CamBatch>()
{
  return xsens_msgs::msg::builder::Init_CamBatch_stamp();
}

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CAM_BATCH__BUILDER_HPP_
