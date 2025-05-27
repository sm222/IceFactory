#include "DevCube.hpp"
#include "../Type/RenderType.hpp"

DevCube::DevCube(void): Object3D("Dev") {
  __type = DEV_CUBE_TYPE;
}

DevCube::DevCube(const char* name): Object3D(name) {
  __type = DEV_CUBE_TYPE;
}

DevCube::DevCube(const std::string& name): Object3D(name) {
  __type = DEV_CUBE_TYPE;
}


DevCube::~DevCube(void) {

}


void DevCube::Draw(int metod) const {
  if (metod & R_mesh) {
    if (__shape == 1)
      DrawCubeV(this->__position, this->__size, GREEN);
    else
      DrawSphere(this->__position, this->__size.x, GREEN);
  }
  if (metod & R_wire) {
    if (__shape == 1)
      DrawCubeWiresV(this->__position, this->__size, RED);
    else
      DrawSphereWires(this->__position, this->__size.x, 10, 20,  RED);
  }
}
