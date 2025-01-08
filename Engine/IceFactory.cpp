
#include "IceFactory.hpp"

#include <iostream>
#include <exception>
#include <stdio.h>

bool  IceFactory::__raylib       = false;
int   IceFactory::__engineStatus = S_EngineInit;
float IceFactory::__timeScale    = 1;

IceFactory::IceFactory(void): 
__instance(nullptr), __screenSize((Vector2) {1000, 1000}),
__gameName("def") {

  __keyMapBind[K_forward]  = KEY_W;
  __keyMapBind[K_backward] = KEY_S;
  __keyMapBind[K_left]     = KEY_A;
  __keyMapBind[K_right]    = KEY_D;
  __keyMapBind[K_Pause]    = KEY_BACKSPACE;
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

bool IceFactory::initRaylib(void) {
  if (!__raylib) {
    IceFactoryInitRayLib();
    const int m = GetCurrentMonitor();
    const float w = GetMonitorWidth(m) ;
    const float h = GetMonitorHeight(m);
    __screenSize = {w , h};
    SetWindowSize(w , h);
    __raylib = true;
  }
  else {

  }
  return true;
}

bool IceFactory::closeRaylib(void) {
  if (__raylib) {
    __raylib = false;
  }
  else {  __keyMapBind[K_right]    = KEY_D;


  }
  return true;
}

bool IceFactory::closeEngine(void) {
  CloseWindow();
  __engineStatus = S_EngineStop;
  return true;
}


Vector2  IceFactory::flaotToVec2(float angle) {
  return {sin(angle * DEG2RAD), cos(angle * DEG2RAD)};
}


int      IceFactory::UpdateInpus(void) {
  //
  __analogMap[ForwardBackward] = (IsKeyDown(__keyMapBind[K_forward]) - (IsKeyDown(__keyMapBind[K_backward])));
  __analogMap[LeftRight] = (IsKeyDown(__keyMapBind[K_right])   - (IsKeyDown(__keyMapBind[K_left])) );
  const Vector2 Mdelata = GetMouseDelta();
  __analogMap[MouseVertical] = Mdelata.y;
  __analogMap[MouseHorizontal] = Mdelata.x;
  return 0;
}

int   IceFactory::UpdateEvent(void) {
  __EngineEvent[Event_pause] = IsKeyPressed(__keyMapBind[K_Pause]);
  return 0;
}

/// @brief this need to be call after UpdateEvent or the event my be true
/// @param envent key set to true
void  IceFactory::ForceEnvent(const t_EngineEvents event) {
  __EngineEvent[event] = true;
}

bool  IceFactory::ReadEnvent(const t_EngineEvents event) {
  return __EngineEvent[event];
}

/// @brief call UpdateInpus and UpdateEvent
/// @param  
/// @return 
int   IceFactory::UpdateEngine(void) {
  return UpdateInpus() + UpdateEvent();
}

float  IceFactory::getAnalogInput(const t_Controls name) {
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