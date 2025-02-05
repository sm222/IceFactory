# include <stdio.h>
# include <iostream>
# include <vector>

template <typename T>
unsigned int Groups<T>::__MakeId(void) {
  static unsigned int id = 0;
  return ++id;
}

template <typename T>
Groups<T>::Groups(void) {
  __id = __MakeId();
}

template <typename T>
Groups<T>* Groups<T>::GetGroupChildById(unsigned int id) {
  typename std::vector<Groups*>::iterator it;
  for (it = __child.begin();  it != __child.end(); it++) {
    if ((*it)->GetId() == id) {
      return *it;
    }
  }
  return nullptr;
}

template <typename T>
unsigned int Groups<T>::GetId(void) const {
  return __id;
}

template <typename T>
Groups<T>::~Groups(void) {
  
}

template <typename T>
ssize_t Groups<T>::Add(const T& obj) {
  __list.push_back(obj);
  return __list.size();
}

template <typename T>
ssize_t Groups<T>::Add(std::vector<T>& objs) {
  typename std::vector<T>::interator it = objs.begin();
  for (it; it != objs.end(); it++) {
    __list.push_back(*it);
  }
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
/// @param depth depth of recursive
/// @param type use to select only one type at the time
/// @return 
template <typename T>
bool Groups<T>::Run(void(*ft)(T, int), int setting, unsigned int depth, const char* type) {
  if (!ft)
    return false;
  for (size_t i = 0; i < __list.size(); i++) {
    if (type == nullptr || strncmp(type, __list[i]->GetType(), strlen(type) + 1) == 0) {
      ft(__list[i], setting);
    }
  }
  if (depth) {
    for (size_t i = 0; i < __child.size(); i++) {
      __child[i]->Run(ft, setting, --depth, type);
    }
  }
  return true;
}


template <typename T>
bool Groups<T>::AddChild(Groups* group) {
  if (group) {
    __child.push_back(group);
    return true;
  }
  return false;
}

template <typename T>
bool Groups<T>::RmChildI(const size_t key) {
  typename std::vector<Groups*>::iterator it;
  if (key > __child.size())
    return false;
  it = __child.begin() + key;
  __child.erase(it);
  return true;
}

template <typename T>
bool Groups<T>::RmChild(const Groups *self) {
  typename std::vector<Groups*>::iterator it;
  for (it = __child.begin();  it != __child.end(); it++) {
    if (*it == self) {
      __child.erase(it);
      return true;
    }
  }
  return false;
}


/// @brief find the first instance with the same name
/// @brief the T value must have a 'GetName'
/// @tparam T 
/// @param name 
/// @param depth
/// @return 
template <typename T>
T*  Groups<T>::Find(const char* name, unsigned int depth) {
  if (name == nullptr)
    return nullptr;
  for (size_t i = 0; i < __list.size(); i++) {
    if (strncmp(__list[i].GetName(), name, strlen(name) + 1) == 0) {
      return __list[i];
    }
  }
  if (depth) {
    for (size_t i = 0; i < __child.size(); i++) {
      const T* data = __child[i]->Find(name, --depth);
      if (data)
        return data;
    }
  }
  return nullptr;
}


/// @brief T need to be a ptr and have a MoveToward define 
/// @tparam T 
/// @param direction 
/// @param ammout 
template <typename T>
void  Groups<T>::MoveToward(const Vector3& direction, const float ammout) {
  typename std::vector<T>::iterator it = __list.begin();
  while (it != __list.end()) {
    (*it)->MoveTowards(direction, ammout);
    it++;
  }
}


#if 0
/// @brief T need to be a ptr and have a MoveToward define 
/// @tparam T 
/// @param direction 
/// @param ammout 
template <typename T, typename D>
void  Groups<T>::MoveToward(void (*ft)(T, D), const D data) {
  typename std::vector<T>::iterator it = __list.begin();
  while (it != __list.end()) {
    try { ft(*it, data); }
    catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    
    it++;
  }
}
#endif



/// @brief call Delete on evry element in the group
/// @tparam T 
template <typename T>
void  Groups<T>::Delete(unsigned int depth, const char* type) {
  typename std::vector<T>::iterator it = __list.begin();
  if (depth) {
    size_t i = __child.size();
    while (i--) {
      __child[i]->Delete(--depth, type);
    }
  }
  while (it != __list.end()) {
    T tmp = *it;
    __list.erase(it);
    delete tmp;
  }
}