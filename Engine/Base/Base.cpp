#include "Base.hpp"

void  Base::SetFtList(void) {
  interface.Add(Base::Hello, prototype(t_none, t_none, t_none, t_none), "hello", "say hello");
}


void    Base::Hello(Base& self) {
  char buff[100];
  snprintf(buff, 99, "Hello from %s", self.GetName());
  DEBUG_P(yello, buff);
}

Base::Base(const char* name) : __type(TYPE_BASE) {
  DEBUG_P(blue, "Base::char");
  SetName(name);
  SetFtList();
}

Base::Base(const std::string& name) : __type(TYPE_BASE) {
  DEBUG_P(blue, "Base::string");
  SetName(name);
  SetFtList();
}

Base::~Base(void) {
  DEBUG_P(blue, "Base::~");
}


//*                  *//*                  *//
//*                                        *//
//*                                        *//
//*                                        *//
//*                                        *//
//*                  *//*                  *//


// GET

const char* Base::GetName(void) const {
  return __name;
}

const char* Base::GetType(void) const {
  return __type;
}

// SET

void Base::SetName(const char* name) {
  if (!name) {
    sprintf(__name, "noName");
  }
  else {
    size_t len = strlen(name);
    if (len > MAX_NAME_LEN) {
      memcpy(__name, name, MAX_NAME_LEN - 1);
      __name[MAX_NAME_LEN] = 0;
    }
    else {
      memcpy(__name, name, len);
      __name[len] = 0;
    }
  }
}

void Base::SetName(const std::string& name) {
  SetName(name.c_str());
}

void  Base::Help(void) {
  DEBUG_P(blue, "Base::Help");
}


/// @brief set the parant to addr of parant
/// @return return false if parent was all ready set
bool Base::__SetParent(const Base& parant) {
  if (__parent)
    return false;
  DEBUG_P(pink, "set parant to %p", &parant);
  __parent = &parant;
  return true;
}

/// @brief set parant ptr to nullptr
/// @return return false if ptr all ready at nullptr
bool Base::__SetParantNone(void) {
  bool rm = false;
  if (__parent) {
    __parent = nullptr;
    rm = true;
    DEBUG_P(pink, "remove parant %p", __parent);
  }
  return rm;
}