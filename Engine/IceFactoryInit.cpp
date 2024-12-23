#include "IceFactory.hpp"
#include "HideIceFactory.hpp"


bool IceFactory::IceFactoryInitRayLib(void) {
  InitWindow(__screenSize.x, __screenSize.y, __GameName.c_str());
  __engineStatus = S_EngineRun;
  SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN);
  SetWindowMinSize(600, 600);
  __viewport = LoadRenderTexture(__screenSize.x, __screenSize.y);
  return true;
}