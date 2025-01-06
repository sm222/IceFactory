#include "BaseCamera.hpp"

BaseCamera::BaseCamera(void) : Object(), 
__camera((Camera3D){{0, 0, 0}, {0,0,0}, {0,1,0}, 90, 0}) , __status(false) {
  __type = BASE_CAMERA;
}

BaseCamera::BaseCamera(const char* name) : Object(name) {
  __type = BASE_CAMERA;
}

BaseCamera::BaseCamera(const std::string name) : Object(name) {
  __type = BASE_CAMERA;
}

BaseCamera::~BaseCamera(void) {

}

void BaseCamera::setTarget(Vector3 position) {
  __camera.target = position;
}


const Camera3D BaseCamera::getCamera(void) const {
  return __camera;
}

void BaseCamera::Draw(void) {
  return ;
}