#include "DevCube.hpp"

DevCube::DevCube(void): Object() {
  __type = DEV_CUBE_TYPE;
}

DevCube::DevCube(const char* name): Object(name) {
  __type = DEV_CUBE_TYPE;
}

DevCube::DevCube(const std::string& name): Object(name) {
  __type = DEV_CUBE_TYPE;
}


DevCube::~DevCube(void) {

}

void DevCube::Draw(int metod) {
  const float size = 0.1f;
  switch (metod) {
  case 0:
  default:
    DrawCube(__position, size, size, size, GREEN);
    break;
  }
}
