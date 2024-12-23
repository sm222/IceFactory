#include "IceFactory.hpp"
#include "Type/Type.hpp"
#include <iostream>
#include <exception>

bool  IceFactory::__raylib       = false;
int   IceFactory::__engineStatus = S_EngineInit;

IceFactory::IceFactory(void): 
__instance(nullptr), __screenSize((Vector2){800, 800}),
__GameName("def") {

}

IceFactory::~IceFactory(void) {}

int  IceFactory::initEngine(void) {
  __engineStatus = S_EngineStart;
  return 1;
}

int IceFactory::GetEngineStatus(void) {
  return __engineStatus;
}

int getStatusEngine(void) {
  return IceFactory::GetEngineStatus();
}


RenderTexture2D IceFactory::GetViewPort(void) {
  return __viewport;
}

bool IceFactory::initRaylib(void) {
  if (!__raylib) {
    IceFactoryInitRayLib();
    __viewport = LoadRenderTexture(__screenSize.x, __screenSize.y);
    __raylib = true;
  }
  else {

  }
  return true;
}

bool IceFactory::closeRaylib(void) {
  if (__raylib) {
    UnloadRenderTexture(__viewport);
    __raylib = false;
  }
  else {

  }
  return true;
}

bool IceFactory::closeEngine(void) {
  CloseWindow();
  __engineStatus = S_EngineStop;
  std::cout << "end" << std::endl;
  return true;
}
