// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/CamImage.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CAM_IMAGE__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__CAM_IMAGE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'data'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__CamImage __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__CamImage __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CamImage_
{
  using Type = CamImage_<ContainerAllocator>;

  explicit CamImage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cam_id = 0;
    }
  }

  explicit CamImage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cam_id = 0;
    }
  }

  // field types and members
  using _cam_id_type =
    int8_t;
  _cam_id_type cam_id;
  using _data_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__cam_id(
    const int8_t & _arg)
  {
    this->cam_id = _arg;
    return *this;
  }
  Type & set__data(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::CamImage_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::CamImage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::CamImage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::CamImage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::CamImage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::CamImage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::CamImage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::CamImage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::CamImage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::CamImage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__CamImage
    std::shared_ptr<xsens_msgs::msg::CamImage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__CamImage
    std::shared_ptr<xsens_msgs::msg::CamImage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CamImage_ & other) const
  {
    if (this->cam_id != other.cam_id) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const CamImage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CamImage_

// alias to use template instance with default allocator
using CamImage =
  xsens_msgs::msg::CamImage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CAM_IMAGE__STRUCT_HPP_
