#include "Base.hpp"

Base::Base(const char* name) : __type(TYPE_BASE) {
  C_DEBUG("Base::Base char");
  SetName(name);
}

Base::Base(const std::string& name) : __type(TYPE_BASE) {
  C_DEBUG("Base::Base std::string");
  SetName(name);
}

Base::~Base(void) {
  C_DEBUG("Base::~Base");
}


//*                  *//*                  *//
//*                                        *//
//*                                        *//
//*                                        *//
//*                                        *//
//*                  *//*                  *//


// GET

const char* Base::GetName(void) const {
  C_DEBUG("Base::GetName");
  return __name;
}

const char* Base::GetType(void) const {
  C_DEBUG("Base::GetType");
  return __type;
}

// SET

void Base::SetName(const char* name) {
  C_DEBUG("Base::SetName char");
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
  C_DEBUG("Base::SetName std::string");
  SetName(name.c_str());
}