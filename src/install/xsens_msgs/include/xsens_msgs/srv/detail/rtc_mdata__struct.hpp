// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_msgs:srv/RTCMdata.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MSGS__SRV__DETAIL__RTC_MDATA__STRUCT_HPP_
#define XSENS_MSGS__SRV__DETAIL__RTC_MDATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__srv__RTCMdata_Request __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__srv__RTCMdata_Request __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RTCMdata_Request_
{
  using Type = RTCMdata_Request_<ContainerAllocator>;

  explicit RTCMdata_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->longitude = 0.0;
      this->latitude = 0.0;
      this->alti_ell = 0.0;
    }
  }

  explicit RTCMdata_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->longitude = 0.0;
      this->latitude = 0.0;
      this->alti_ell = 0.0;
    }
  }

  // field types and members
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _alti_ell_type =
    double;
  _alti_ell_type alti_ell;

  // setters for named parameter idiom
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__alti_ell(
    const double & _arg)
  {
    this->alti_ell = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__srv__RTCMdata_Request
    std::shared_ptr<xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__srv__RTCMdata_Request
    std::shared_ptr<xsens_msgs::srv::RTCMdata_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RTCMdata_Request_ & other) const
  {
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->alti_ell != other.alti_ell) {
      return false;
    }
    return true;
  }
  bool operator!=(const RTCMdata_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RTCMdata_Request_

// alias to use template instance with default allocator
using RTCMdata_Request =
  xsens_msgs::srv::RTCMdata_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace xsens_msgs


#ifndef _WIN32
# define DEPRECATED__xsens_msgs__srv__RTCMdata_Response __attribute__((deprecated))
#else
# define DEPRECATED__xsens_msgs__srv__RTCMdata_Response __declspec(deprecated)
#endif

namespace xsens_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RTCMdata_Response_
{
  using Type = RTCMdata_Response_<ContainerAllocator>;

  explicit RTCMdata_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit RTCMdata_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_msgs__srv__RTCMdata_Response
    std::shared_ptr<xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_msgs__srv__RTCMdata_Response
    std::shared_ptr<xsens_msgs::srv::RTCMdata_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RTCMdata_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const RTCMdata_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RTCMdata_Response_

// alias to use template instance with default allocator
using RTCMdata_Response =
  xsens_msgs::srv::RTCMdata_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace xsens_msgs

namespace xsens_msgs
{

namespace srv
{

struct RTCMdata
{
  using Request = xsens_msgs::srv::RTCMdata_Request;
  using Response = xsens_msgs::srv::RTCMdata_Response;
};

}  // namespace srv

}  // namespace xsens_msgs

#endif  // XSENS_MSGS__SRV__DETAIL__RTC_MDATA__STRUCT_HPP_
