#include "BaseCamera.hpp"

BaseCamera::BaseCamera() : Object(), 
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


const Camera3D getCamera(void) const {
  return __camera;
}

