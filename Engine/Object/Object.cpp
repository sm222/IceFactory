#include "Object.hpp"



Object::Object(const char* name): 
__type(NULL), __position((Vector3){0,0,0})
{
  if (!name) {
    sprintf(__name, "noName");
  }
  else {
    size_t len = strlen(name);
    if (len > 98) {
      memcpy(__name, name, 98);
      __name[99] = 0;
    }
    else {
      memcpy(__name, name, len);
      __name[len] = 0;
    }
  }
}

Object::Object(const std::string name): 
__type(NULL), __position((Vector3){0,0,0})
{
  size_t len = name.length();
  if (len > 98) {
    memcpy(__name, name.c_str(), 98);
    __name[99] = 0;
  }
  else {
    memcpy(__name, name.c_str(), len);
    __name[len] = 0;
  }
}

Object::~Object() {

}

const char* Object::GetName(void) const {
  return this->__name;
}

const char*  Object::GetType(void) const {
  return this->__type;
}

const Vector3 Object::GetPosition(void) const {
  return this->__position;
}

//

void Object::SetPosition(const Vector3 position) {
  this->__position = position;
}

void Object::SetPosition(float x, float y, float z) {
  this->__position.x = x;
  this->__position.y = y;
  this->__position.z = z;
}

void Object::SetPosition(const Vector3& position) {
  this->__position = position;
}

void Object::SetName(const char* name) {
  if (!name) {
    return;
  }
  else {
    size_t len = strlen(name);
    if (len > 98) {
      memcpy(__name, name, 98);
      __name[99] = 0;
    }
    else {
      memcpy(__name, name, len);
      __name[len] = 0;
    }
  }
}

void Object::SetName(const std::string name) {
  size_t len = name.length();
  if (len > 98) {
    memcpy(__name, name.c_str(), 98);
    __name[99] = 0;
  }
  else {
    memcpy(__name, name.c_str(), len);
    __name[len] = 0;
  }
}