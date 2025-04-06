#include "BaseInterface.hpp"

template <size_t max>
BaseInterface<max>::BaseInterface(void) {
  for (size_t i = 0; i < max; i++) {
    __list[i]._ft.ptr = nullptr;
    __list[i]._types = prototype(t_none, t_none, t_none, t_none);
    __list[i]._name = nullptr;
    __list[i]._description = nullptr;
  }
  __i = 0;
}

template <size_t max>
BaseInterface<max>::~BaseInterface(void) { /*\*/ }

template <size_t max>
bool  BaseInterface<max>::__Add(t_prototype types, const char* name, const char* description) {
  __list[__i]._types = types;
  __list[__i]._name = name;
  __list[__i]._description = description;
  __i++;
  return true;
}

template <size_t max>
bool BaseInterface<max>::Add(void__void ft, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.void_void = ft;
  return __Add({t_none, t_none, t_none, t_none}, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(void__1 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.void_1 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(void__2 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.void_2 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(void__3 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.void_3 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(int__1 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.int_1 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(int__2 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.int_2 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(int__3 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.int_3 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(float__1 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.float_1 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(float__2 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.float_2 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(float__3 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.float_3 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(vec2__1 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.vec2_1 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(vec2__2 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.vec2_2 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(vec2__3 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.vec2_3 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(vec3__1 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.vec3_1 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(vec3__2 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.vec3_2 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Add(vec3__3 ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.vec3_3 = ft;
  return __Add(types, name, description);
}

template <size_t max>
bool BaseInterface<max>::Get(size_t i, t_BaseInterface& get) {
  if (i >= max)
    return false;
  get._ft = __list[i]._ft;
  get._name = __list[i]._name;
  get._description = __list[i]._description;
  return true;
}