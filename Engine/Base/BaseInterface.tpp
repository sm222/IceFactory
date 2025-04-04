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
void  BaseInterface<max>::__Add(t_prototype types, const char* name, const char* description) {
  __list[__i]._types = types;
  __list[__i]._name = name;
  __list[__i]._description = description;
  __i++;
}

template <size_t max>
bool BaseInterface<max>::Add(v__v ft, t_prototype types, const char* name, const char* description) {
  if (__i >= max)
    return false;
  __list[__i]._ft.v_v = ft;
  __Add(types, name, description);
  return true;
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