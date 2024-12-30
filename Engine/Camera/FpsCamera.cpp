#include "FpsCamera.hpp"
#include <iostream>

FpsCamera::FpsCamera(void): __cam((Camera3D){{0, 0, 0}, {0,0,0}, {0,1,0}, 90, 0}) 
, __status(false)
{

}

Vector2 floatToVec2(float angle) {
  return {sin(angle * DEG2RAD), cos(angle * DEG2RAD)};
}

FpsCamera::~FpsCamera(void) {}


const Camera3D FpsCamera::getCamera(void) const {
  return __cam;
}

void FpsCamera::updatePotision(Vector3 movement, Vector3 rotate, float zoom) {
  UpdateCameraPro(&__cam, movement, rotate, zoom);
}

void FpsCamera::setPotision(Vector3 p) {
  __cam.position = p;
}