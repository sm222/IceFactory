#include "DevFlore.hpp"

DevFlore::DevFlore(const char* name) : Obj3D(name) {
  __boundingBox.min = {-1.f, -1.f, -1.f};
  __boundingBox.max = {1.f, 1.f, 1.f};
  __type = TYPE_DEV_FLORE_3D;
}

DevFlore::~DevFlore(void) {
}

void DevFlore::Draw(int mode) const {
  (void)mode;
  DrawGrid(30, 3);
  const float l = 1.5f;
  const Vector3 mid = {0, 0.2f, 0};
  Vector3 r = {mid};
  r = {0, l + 0.2f, 0};
  DrawLine3D(mid, r, BLUE);
  r = {l, 0.2f, 0};
  DrawLine3D(mid, r, RED);
  r = {0, 0.2f, l};
  DrawLine3D(mid, r, GREEN);
}