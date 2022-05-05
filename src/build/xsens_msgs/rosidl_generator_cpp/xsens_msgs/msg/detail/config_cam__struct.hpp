// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:msg/ConfigCam.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__MSG__DETAIL__CONFIG_CAM__STRUCT_HPP_
#define XSENS_MSGS__MSG__DETAIL__CONFIG_CAM__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__msg__ConfigCam __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__msg__ConfigCam __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ConfigCam_
{
  using Type = ConfigCam_<ContainerAllocator>;

  explicit ConfigCam_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0l;
      this->width = 0l;
      this->framerate = 0l;
      this->save_file = "";
    }
  }

  explicit ConfigCam_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : save_file(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0l;
      this->width = 0l;
      this->framerate = 0l;
      this->save_file = "";
    }
  }

  // field types and members
  using _height_type =
    int32_t;
  _height_type height;
  using _width_type =
    int32_t;
  _width_type width;
  using _framerate_type =
    int32_t;
  _framerate_type framerate;
  using _save_file_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _save_file_type save_file;

  // setters for named parameter idiom
  Type & set__height(
    const int32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__width(
    const int32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__framerate(
    const int32_t & _arg)
  {
    this->framerate = _arg;
    return *this;
  }
  Type & set__save_file(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->save_file = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::msg::ConfigCam_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::msg::ConfigCam_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::msg::ConfigCam_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::msg::ConfigCam_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::ConfigCam_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::ConfigCam_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::msg::ConfigCam_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::msg::ConfigCam_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::msg::ConfigCam_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::msg::ConfigCam_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__msg__ConfigCam
    std::shared_ptr<xsens_msgs::msg::ConfigCam_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__msg__ConfigCam
    std::shared_ptr<xsens_msgs::msg::ConfigCam_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigCam_ & other) const
  {
    if (this->height != other.height) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->framerate != other.framerate) {
      return false;
    }
    if (this->save_file != other.save_file) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigCam_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigCam_

// alias to use template instance with default allocator
using ConfigCam =
  xsens_msgs::msg::ConfigCam_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__MSG__DETAIL__CONFIG_CAM__STRUCT_HPP_
