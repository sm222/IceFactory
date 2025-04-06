#include "Object.hpp"


void   Object::Info(Base& self, t_types i) {
  (void)i;
  Object& ref = (Object&)self;
  printf("name:%s type:%s\n", ref.GetName(), ref.GetType());
}

Object::Object(const char* name) : Base(name) {
  DEBUG_P(yello, "Object::char");
  __type = TYPE_OBJECT;
  Zero();
}

Object::Object(const std::string& name) : Base(name) {
  DEBUG_P(yello, "Object::string");
  __type = TYPE_OBJECT;
  Zero();
}

Object::~Object(void) {
  DEBUG_P(yello, "Object::~");
}

void Object::Zero(void) {

}