#include "IceFactory.hpp"
#include "Type/Type.hpp"
#include <iostream>
#include <exception>
#include <stdio.h>

bool  IceFactory::__raylib       = false;
int   IceFactory::__engineStatus = S_EngineInit;
float IceFactory::__timeScale    = 1;

IceFactory::IceFactory(void): 
__instance(nullptr), __screenSize((Vector2) {1000, 1000}),
__GameName("def") {

  __keyMapBind[K_forward]  = KEY_W;
  __keyMapBind[K_backward] = KEY_S;
  __keyMapBind[K_left]     = KEY_A;
  __keyMapBind[K_right]    = KEY_D;
}

IceFactory::~IceFactory(void) {}

// - - - - - - - - - - - - - - - -

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
    const int m = GetCurrentMonitor();
    const float a = GetMonitorWidth(m) ;
    const float b = GetMonitorHeight(m);
    __screenSize = {a , b};
    std::cout << a << " / " << b << "\n";
    SetWindowSize(a , b );
    __viewport = LoadRenderTexture(a, b);
    __raylib = true;
  }
  else {

  }
  return true;
}

bool IceFactory::closeRaylib(void) {
  if (__raylib) {
    __raylib = false;
    UnloadRenderTexture(__viewport);
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


Vector2  IceFactory::flaotToVec2(float angle) {
  return {sin(angle * DEG2RAD), cos(angle * DEG2RAD)};
}


int      IceFactory::updateInpus(void) {
  //
  __analogMap["FB"] = (IsKeyDown(__keyMapBind[K_forward]) - (IsKeyDown(__keyMapBind[K_backward])));
  __analogMap["LR"] = (IsKeyDown(__keyMapBind[K_right])   - (IsKeyDown(__keyMapBind[K_left])) );
  return 0;
}

float  IceFactory::getAnalogInput(const std::string name) {
  if (__analogMap.find(name) != __analogMap.end())
    return __analogMap[name];
  return 0;
}

float  IceFactory::timeScale(float in) {
  return in * GetFrameTime() * __timeScale;
}

void   IceFactory::setTimeScale(float scale) {
  __timeScale = scale;
}

Vector2 IceFactory::GiveWindowSize(void) {
  return __screenSize;
}