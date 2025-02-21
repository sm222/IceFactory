#include "Object.hpp"

Object::Object(const char* name) : Base(name) {
  __type = TYPE_OBJECT;
  Zero();
}

Object::Object(const std::string& name) : Base(name) {
  __type = TYPE_OBJECT;
  Zero();
}

Object::~Object(void) {

}

void Object::Zero(void) {

}