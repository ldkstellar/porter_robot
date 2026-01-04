// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wave_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice

#ifndef WAVE_INTERFACES__MSG__DETAIL__DISTANCE__STRUCT_H_
#define WAVE_INTERFACES__MSG__DETAIL__DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Distance in the package wave_interfaces.
typedef struct wave_interfaces__msg__Distance
{
  double distance;
} wave_interfaces__msg__Distance;

// Struct for a sequence of wave_interfaces__msg__Distance.
typedef struct wave_interfaces__msg__Distance__Sequence
{
  wave_interfaces__msg__Distance * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wave_interfaces__msg__Distance__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAVE_INTERFACES__MSG__DETAIL__DISTANCE__STRUCT_H_
