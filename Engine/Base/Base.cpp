#include "Base.hpp"

Base::Base(const char* name) : __type(TYPE_BASE) {
  SetName(name);
}

Base::Base(const std::string& name) : __type(TYPE_BASE) {
  SetName(name);
}

Base::~Base(void) {
  
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
  size_t len = name.length();
  if (len > MAX_NAME_LEN) {
    memcpy(__name, name.c_str(), MAX_NAME_LEN - 1);
    __name[MAX_NAME_LEN] = 0;
  }
  else {
    memcpy(__name, name.c_str(), len);
    __name[len] = 0;
  }
}