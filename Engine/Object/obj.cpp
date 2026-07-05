# include "obj.hpp"

Obj::Obj(const char* name) : Base(name) {
  // -
  __type = TYPE_OBJ;
}

Obj::~Obj(void) {
  // -
}