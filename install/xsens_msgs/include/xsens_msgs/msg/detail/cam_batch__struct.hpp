// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/CamBatch.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CAM_BATCH__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__CAM_BATCH__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'data'
#include "xsens_msgs/msg/detail/cam_image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__CamBatch __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__CamBatch __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CamBatch_
{
  using Type = CamBatch_<ContainerAllocator>;

  explicit CamBatch_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data.fill(xsens_msgs::msg::CamImage_<ContainerAllocator>{_init});
    }
  }

  explicit CamBatch_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data.fill(xsens_msgs::msg::CamImage_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _stamp_type =
    std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other>;
  _stamp_type stamp;
  using _data_type =
    std::array<xsens_msgs::msg::CamImage_<ContainerAllocator>, 4>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__stamp(
    const std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__data(
    const std::array<xsens_msgs::msg::CamImage_<ContainerAllocator>, 4> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::CamBatch_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::CamBatch_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::CamBatch_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::CamBatch_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::CamBatch_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::CamBatch_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::CamBatch_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::CamBatch_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::CamBatch_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::CamBatch_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__CamBatch
    std::shared_ptr<xsens_msgs::msg::CamBatch_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__CamBatch
    std::shared_ptr<xsens_msgs::msg::CamBatch_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CamBatch_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const CamBatch_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CamBatch_

// alias to use template instance with default allocator
using CamBatch =
  xsens_msgs::msg::CamBatch_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CAM_BATCH__STRUCT_HPP_
