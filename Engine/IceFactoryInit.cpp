#include "IceFactory.hpp"
#include "HideIceFactory.hpp"


bool IceFactory::IceFactoryInitRayLib(void) {
  std::cout << __screenSize.x << " " << __screenSize.y << "\n";
  InitWindow(__screenSize.x, __screenSize.y, __GameName.c_str());
  __engineStatus = S_EngineRun;
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetWindowMinSize(600, 600);
  return true;
}