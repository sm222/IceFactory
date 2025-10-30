#include "Object.hpp"


void   Object::Info(Base& self) {
  Object& ref = (Object&)self;
  printf("name:%s type:%s\n", ref.GetName(), ref.GetType());
}

Object::Object(const char* name) : Base(name) {
  DEBUG_P(TXT_MAG, "char");
  __type = TYPE_OBJECT;
  __AddInheritance();
  __DrawInheritance();
  Zero();
}

Object::Object(const char* name, unsigned short drawType) : Base(name, drawType) {
}

Object::Object(const std::string& name) : Base(name) {
  DEBUG_P(TXT_MAG, "string");
  __type = TYPE_OBJECT;
  __AddInheritance();
  __DrawInheritance();
  Zero();
}

Object::Object(const std::string& name, unsigned short drawType) : Base(name, drawType) {
}


Object::~Object(void) {
  DEBUG_P(TXT_MAG, "");
}

void Object::Zero(void) {
  interface.Add(Object::Info, "info", "print info of Object");
}