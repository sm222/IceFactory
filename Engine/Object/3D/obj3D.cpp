#include "obj3D.hpp"


Obj3D::Obj3D(const char* name) : Obj(name) {
  ZERO_NONE_PTR(__position);
  ZERO_NONE_PTR(__boundingBox);
}

Obj3D::~Obj3D(void) {
  //
}

