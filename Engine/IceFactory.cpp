
#include "IceFactory.hpp"

#include <iostream>
#include <exception>
#include <stdio.h>

bool             IceFactory::__raylib       = false;
t_EngineStatus   IceFactory::__engineStatus = S_EngineInit;
float            IceFactory::__timeScale    = 1;

IceFactory::IceFactory(void): 
__screenSize((Vector2) {1000, 1000}),
__gameName("def") {
  //
  __userSeting.targetFps = 30;
  __userSeting.targetWindowSize = {600, 600};
  //
  __keyMapBind[K_forward]  = KEY_W;
  __keyMapBind[K_backward] = KEY_S;
  __keyMapBind[K_left]     = KEY_A;
  __keyMapBind[K_right]    = KEY_D;
  __keyMapBind[K_Pause]    = KEY_BACKSPACE;
  // error and debug
  __whatA = 0;
}

IceFactory::~IceFactory(void) {}
// - - - - - - - - - - - - - - - -

void  IceFactory::SetEngineStatus(const t_EngineStatus status) {
  __engineStatus = status;
}

// - - - - - - - - - - - - - - - -

static const Vector2 getMonitorSize(void) {
  const int m = GetCurrentMonitor();
  const float w = GetMonitorWidth(m) ;
  const float h = GetMonitorHeight(m);
  return ((Vector2){w, h});
}

static const Vector2 getWindowSize(void) {
  return ((Vector2){(float)GetRenderWidth() ,(float)GetRenderHeight()});
}



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
    __screenSize = getMonitorSize();
    SetWindowSize(__screenSize.x, __screenSize.y);
    __raylib = true;
    __what = LoadModel(ERR_MESH);
    if (IsModelValid(__what))
      printf("ready to go\n");
  }
  else {

  }
  return true;
}

bool IceFactory::closeRaylib(void) {
  if (__raylib) {
    __raylib = false;
  }
  else { 

  }
  return true;
}

bool IceFactory::closeEngine(void) {
  if ( IsModelValid(__what))
    UnloadModel(__what);
  __engineStatus = S_EngineStop;
  //!last step
  CloseWindow();
  return true;
}


Vector2  IceFactory::flaotToVec2(float angle) {
  return {sin(angle * DEG2RAD), cos(angle * DEG2RAD)};
}


int      IceFactory::UpdateInpus(void) {
  //
  const Vector2 Mdelata = GetMouseDelta();
  __analogMap[ForwardBackward] = (IsKeyDown(__keyMapBind[K_forward]) - (IsKeyDown(__keyMapBind[K_backward])));
  __analogMap[LeftRight] = (IsKeyDown(__keyMapBind[K_right])   - (IsKeyDown(__keyMapBind[K_left])) );
  __analogMap[MouseVertical]   = Mdelata.y;
  __analogMap[MouseHorizontal] = Mdelata.x;
  return 0;
}

int   IceFactory::UpdateEvent(void) {
  __EngineEvent[Event_pause] = IsKeyPressed(__keyMapBind[K_Pause]);
  __EngineEvent[Event_window_resized] = IsWindowResized();

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
  const int status = UpdateInpus() + UpdateEvent();
  if (__EngineEvent[Event_window_resized]) {
    __screenSize = getWindowSize();
  }
  __whatA++;
  return status;
}


float  IceFactory::GetAnalogInput(const t_Controls name) {
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


/*!
//!
//!
*/
Model*  IceFactory::GiveWhatModel(void) {
  return &__what;
}
