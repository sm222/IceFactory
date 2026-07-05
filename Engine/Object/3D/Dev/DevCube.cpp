#include "DevCube.hpp"

DevCube3D::DevCube3D(const char* name) : Obj3D(name) {
  __boundingBox.min = {-1.f, -1.f, -1.f};
  __boundingBox.max = {1.f, 1.f, 1.f};
  __type = TYPE_DEV_CUBE_3D;
}

DevCube3D::~DevCube3D(void) {
}

void DevCube3D::Draw(int mode) const {
  (void)mode;
  DrawBoundingBox(__boundingBox, RED);
}

void DevCube3D::SetPosition(Vector3 position) {
  __position = position;
  const Vector3 offset = {1, 1 ,1};
  __boundingBox.min = position - offset;
  __boundingBox.max = position + offset;
}