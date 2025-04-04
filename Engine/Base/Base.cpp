#include "Base.hpp"

void  Base::SetFtList(void) {
  interface.Add(Base::Hello, prototype(t_none, t_none, t_none, t_none), "hello", "say hello");
}


void    Base::Hello(Base& self) {
  char buff[100];
  snprintf(buff, 99, "Hello from %s", self.GetName());
  DEBUG(PROJECT_ROOT, yello, buff);
}

Base::Base(const char* name) : __type(TYPE_BASE) {
  DEBUG(PROJECT_ROOT, blue, "Base::char");
  SetName(name);
  SetFtList();
}

Base::Base(const std::string& name) : __type(TYPE_BASE) {
  DEBUG(PROJECT_ROOT, blue, "Base::string");
  SetName(name);
  SetFtList();
}

Base::~Base(void) {
  DEBUG(PROJECT_ROOT, blue, "Base::~");
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
  DEBUG(PROJECT_ROOT, blue, "Base::Help");
}