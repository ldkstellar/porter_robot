// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from wave_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "wave_interfaces/msg/detail/distance__rosidl_typesupport_introspection_c.h"
#include "wave_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "wave_interfaces/msg/detail/distance__functions.h"
#include "wave_interfaces/msg/detail/distance__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  wave_interfaces__msg__Distance__init(message_memory);
}

void wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_fini_function(void * message_memory)
{
  wave_interfaces__msg__Distance__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array[1] = {
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wave_interfaces__msg__Distance, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_members = {
  "wave_interfaces__msg",  // message namespace
  "Distance",  // message name
  1,  // number of fields
  sizeof(wave_interfaces__msg__Distance),
  wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array,  // message members
  wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_init_function,  // function to initialize message memory (memory has to be allocated)
  wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle = {
  0,
  &wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wave_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wave_interfaces, msg, Distance)() {
  if (!wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle.typesupport_identifier) {
    wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &wave_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
