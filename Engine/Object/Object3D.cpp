#include "Object3D.hpp"

void Object3D::Zero(void) {
  ZERO_NONE_PTR(__position);
  ZERO_NONE_PTR(__rotation);
}

Object3D::Object3D(const char* name) : Object(name) {
  __type = TYPE_OBJECT3D;
  DEBUG_P(magenta, "Object3D::char");
  Zero();
}

Object3D::Object3D(const std::string& name) : Object(name) {
  __type = TYPE_OBJECT3D;
  DEBUG_P(magenta, "Object3D::string");
  Zero();
}

Object3D::~Object3D(void) {
  DEBUG_P(magenta, "Object3D::~");
}

//*                  *//*                  *//
//*                                        *//
//*                                        *//
//*                                        *//
//*                                        *//
//*                  *//*                  *//

const Vector3&  Object3D::GetPosition(void) const {
  return __position;
}

const Vector3&  Object3D::GetRotation(void) const {
  return __rotation;
}

void  Object3D::SetPosition(const Vector3& position) {
  __position = position;
}

void  Object3D::SetRotation(const Vector3& rotation) {
  __rotation = rotation;
}

