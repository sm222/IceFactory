#include "Base2DCamera.hpp"


void Base2DCamera::Zero(void) {
  ZERO_NONE_PTR(__camera);
}

Base2DCamera::Base2DCamera(const char* name) : Object2D(name) {
  __type = BASE_CAMERA_2D;
  Default();
  DEBUG_P(magenta, "Base2DCamera::");
}

Base2DCamera::Base2DCamera(const std::string& name) : Object2D(name) {
  __type = BASE_CAMERA_2D;
  Default();
  DEBUG_P(magenta, "Base2DCamera::");
}


Base2DCamera::~Base2DCamera(void) {
  DEBUG_P(magenta, "Base2DCamera::~");
}


void  Base2DCamera::Default(void) {
  Zero();
  __camera.zoom = 1;
}


void Base2DCamera::Update(const Vector2& movement, \
const Vector2& target , const float& rotation, const float& zoom) {
  __camera.target += movement;
  __camera.target += target;
  __camera.rotation += rotation;
  __camera.zoom += zoom;
}


void  Base2DCamera::SetCamera(const Camera2D& camera) {
  __camera = camera;
}

const Camera2D&  Base2DCamera::GetCamera(void) const {
  return __camera;
}