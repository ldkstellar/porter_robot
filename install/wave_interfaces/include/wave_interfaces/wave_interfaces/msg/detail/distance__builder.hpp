// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wave_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice

#ifndef WAVE_INTERFACES__MSG__DETAIL__DISTANCE__BUILDER_HPP_
#define WAVE_INTERFACES__MSG__DETAIL__DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wave_interfaces/msg/detail/distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wave_interfaces
{

namespace msg
{

namespace builder
{

class Init_Distance_distance
{
public:
  Init_Distance_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::wave_interfaces::msg::Distance distance(::wave_interfaces::msg::Distance::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wave_interfaces::msg::Distance msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wave_interfaces::msg::Distance>()
{
  return wave_interfaces::msg::builder::Init_Distance_distance();
}

}  // namespace wave_interfaces

#endif  // WAVE_INTERFACES__MSG__DETAIL__DISTANCE__BUILDER_HPP_
