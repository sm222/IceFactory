#include "obj3D.hpp"


Obj3D::Obj3D(const char* name) : Obj(name) {
  ZERO_NONE_PTR(__position);
  ZERO_NONE_PTR(__boundingBox);
}

Obj3D::~Obj3D(void) {
  //
}

void Obj3D::Draw(int mode) const {
  (void)mode;
}

void Obj3D::SetPosition(Vector3 position) {
  __position = position;
}

Vector3 Obj3D::GetPosition(void) const {
  return __position;
}

void Obj3D::SetBoundingBox(BoundingBox box) {
  __boundingBox = box;
}

BoundingBox Obj3D::GetBoundingBox(void) const {
  return __boundingBox;
}