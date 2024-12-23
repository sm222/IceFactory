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
bool Groups<T>::Rm(const size_t key) {
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

template <typename T>
bool Groups<T>::Run(int(*ft)(T)) {
  if (!ft)
    return false;
  for (size_t i = 0; i < __list.size(); i++) {
    ft(__list[i]);
  }
  return true;
}