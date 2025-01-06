# include <stdio.h>
# include <iostream>
template <typename T>
Groups<T>::Groups(void) {
  
}

template <typename T>
Groups<T>::~Groups(void) {
  
}

template <typename T>
ssize_t Groups<T>::Add(const T obj) {
  __list.push_back(obj);
  return __list.size();
}

template <typename T>
bool Groups<T>::RmI(const unsigned int key) {
  if (key > __list.size())
    return false;
  typename std::vector<T>::iterator it;
  it = __list.begin() + key;
  __list.erase(it);
  return true;
}

template <typename T>
bool Groups<T>::Rm(const T self) {
  typename std::vector<T>::iterator it = __list.begin();
  for (; it != __list.end(); it++) {
    if (*it == self) {
      __list.erase(it);
      return true;
    }
  }
  return false;
}

/// @brief use to run a cmd on the Vector T type. need to have a 'GetType'
/// @tparam T 
/// @param ft 
/// @param child 
/// @param type 
/// @return 
template <typename T>
bool Groups<T>::Run(void(*ft)(T), unsigned int child, const char* type) {
  if (!ft)
    return false;
  for (size_t i = 0; i < __list.size(); i++) {
    if (type == nullptr || strncmp(type, __list[i]->GetType(), strlen(type) + 1) == 0) {
      ft(__list[i]);
      //
    }
  }
  if (child) {
    for (size_t i = 0; i < __child.size(); i++) {
      __child[i]->Run(ft, --child, type);
    }
  }
  return true;
}


template <typename T>
bool Groups<T>::AddChild(Groups* g) {
  if (g) {
    __child.push_back(g);
    return true;
  }
  return false;
}