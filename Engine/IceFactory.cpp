
#include "IceFactory.hpp"

#include <iostream>
#include <exception>
#include <stdio.h>

bool             IceFactory::__raylib       = false;
t_EngineStatus   IceFactory::__engineStatus = S_EngineInit;
float            IceFactory::__timeScale    = 1;


void IceFactory::_SetFpsControl(void) {
  SetKeyMapToKey(K_forward,  KEY_W);
  SetKeyMapToKey(K_backward, KEY_S);
  SetKeyMapToKey(K_left,     KEY_A);
  SetKeyMapToKey(K_right,    KEY_D);
  SetKeyMapToKey(K_pause,    KEY_BACKSPACE);
}

IceFactory::IceFactory(void):
__screenSize((Vector2) {1000, 1000}), __gameName("def") {
  //
  __userSeting.targetFps = 60;
  __userSeting.targetWindowSize = {600, 600};
  __inputSelect = KeybordMouse;
  __numberGamepads = 0;
  for (int i = 0; i < t_ControlKeys::K_End; i++) {
    __keyMapBind[(t_ControlKeys)i] = KEY_NULL;
  }
  _SetFpsControl();
  // error and debug
  C_DEBUG("start IceFactory");
}

IceFactory::~IceFactory(void) { C_DEBUG("IceFactory GoodBye"); }
// - - - - - - - - - - - - - - - -

void  IceFactory::SetEngineStatus(const t_EngineStatus status) {
  __engineStatus = status;
}

// - - - - - - - - - - - - - - - -

const Vector2 IceFactory::GetMonitorSize(void) {
  L_DEBUG("getMonitorSize");
  if (IceFactory::GetEngineStatus()) {
    const int monitor  = GetCurrentMonitor();
    const float width  = GetMonitorWidth(monitor) ;
    const float height = GetMonitorHeight(monitor);
    return ((Vector2){width, height});
  }
  return ((Vector2){0, 0});
}

const Vector2 IceFactory::GetWindowSize(void) {
  if (IceFactory::GetEngineStatus())
    return ((Vector2){(float)GetRenderWidth() ,(float)GetRenderHeight()});
  return ((Vector2){0, 0});
}



// - - - - - - - - - - - - - - - -

int  IceFactory::initEngine(void) {
  __engineStatus = S_EngineStart;
  return 1;
}

bool IceFactory::IceFactoryInitRayLib(void) {
  InitWindow(__screenSize.x, __screenSize.y, __gameName.c_str());
  if (!IsWindowReady()) {
    W_DEBUG("raylib FAIL!!!");
    return false;
  }
  L_DEBUG("Begin Raylib");
  __engineStatus = S_EngineRun;
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetWindowMinSize(600, 600);
  return true;
}

int IceFactory::GetEngineStatus(void) {
  return __engineStatus;
}


bool IceFactory::InitRaylib(void) {
  if (!__raylib) {
    __raylib = IceFactoryInitRayLib();
    if (!__raylib)
      return false;
    __screenSize = IceFactory::GetMonitorSize();
    SetWindowSize(__screenSize.x, __screenSize.y);
    Models.Add(ERR_MESH);
    __what = LoadModel(ERR_MESH);
    if (IsModelValid(Models.Get(ERR_MESH))) {
      L_DEBUG("ready to go!");
      // add pre chek if all defaut stuff are load in
    }
  }
  else {
    W_DEBUG("Raylib is all ready runing");
  }
  return true;
}

bool IceFactory::CloseRaylib(void) {
  if (__raylib) {
    CloseWindow();
    __raylib = false;
  }
  return true;
}

// Rap around raylib
bool IceFactory::closeEngine(void) {
  __engineStatus = S_EngineStop;
  Models.Clear();
  //!last step
  CloseRaylib();
  return true;
}


Vector2  IceFactory::flaotToVec2(float angle) {
  return {sin(angle * DEG2RAD), cos(angle * DEG2RAD)};
}


int      IceFactory::UpdateInpus(void) {
  //
  const Vector2 mouseDelta = GetMouseDelta();
  UpdateKeybord();
  __analogMap[MouseVertical]   = mouseDelta.y;
  __analogMap[MouseHorizontal] = mouseDelta.x;
  return 0;
}

int   IceFactory::UpdateEvent(void) {
  __EngineEvent[Event_pause] = IsKeyPressed(__keyMapBind[K_pause]);
  __EngineEvent[Event_window_resized] = IsWindowResized();
  return 0;
}

/// @brief this need to be call after UpdateEvent or the event my be true
/// @param envent key set to true
void  IceFactory::ForceEnvent(const t_EngineEvents event) {
  __EngineEvent[event] = true;
}

bool  IceFactory::ReadEnvent(const t_EngineEvents event) const {
  std::map<t_EngineEvents, bool>::const_iterator it = __EngineEvent.find(event);
  if (it != __EngineEvent.end())
    return ((*it).second);
  return false;
}


/// @brief call UpdateInpus and UpdateEvent
/// @param  
/// @return 
int   IceFactory::UpdateEngine(void) {
  ClearBackground(BLANK);
  const int status = UpdateInpus() + UpdateEvent();
  if (__EngineEvent[Event_window_resized]) {
    __screenSize = IceFactory::GetWindowSize();
  }
  return status;
}


float  IceFactory::GetAnalogInput(const t_Controls name) const {
  std::map<t_Controls, float>::const_iterator it = __analogMap.find(name);
  if (it != __analogMap.end())
    return ((*it).second);
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


//*                  *//*                  *//
//*                                        *//
//*                 KEYBORD                *//
//*                                        *//
//*                                        *//
//*                  *//*                  *//


void   IceFactory::SetKeyMapToKey(t_ControlKeys action, KeyboardKey key) {
  __keyMapBind[action] = key;
}

void IceFactory::UpdateKeybord(void) {
  __analogMap[ForwardBackward] = (IsKeyDown(__keyMapBind[K_forward]) - (IsKeyDown(__keyMapBind[K_backward])));
  __analogMap[LeftRight]       = (IsKeyDown(__keyMapBind[K_right])   - (IsKeyDown(__keyMapBind[K_left])) );
}


//*                  *//*                  *//
//*                                        *//
//*                 GAMEPAD                *//
//*                                        *//
//*                                        *//
//*                  *//*                  *//