#include "obj3D.hpp"


Obj3D::Obj3D(const char* name) : Obj(name) {
  ZERO_NONE_PTR(__position);
  ZERO_NONE_PTR(__boundingBox);
  __type = TYPE_OBJ_3D;
}

Obj3D::~Obj3D(void) {
  //
}

void Obj3D::Draw(int mode) const {
  (void)mode;
  DrawPoint3D(__position, GREEN);
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

void Obj3D::Tranform(Vector3 dir) {
  __position += dir;
}

void Obj3D::Zero(void) {

}