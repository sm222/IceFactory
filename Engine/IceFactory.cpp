
#include "IceFactory.hpp"

#include <stdio.h>

bool             IceFactory::__raylib       = false;
t_EngineStatus   IceFactory::__engineStatus = S_EngineBuild;
float            IceFactory::__timeScale    = 1;

const char* const _dependency[] = {
  ERR_MESH,
  nullptr
};

bool IceFactory::TestDependency(void) {
  for (size_t i = 0; _dependency[i]; i++) {
    if (access(_dependency[i], R_OK) != 0) {
      DEBUG_P(red, "IceFactory::TestDependency ✕%s", _dependency[i]);
      perror("access");
      return false;
    }
    DEBUG_P(green, "IceFactory::TestDependency ✓%s", _dependency[i]);
  }
  return true;
}

void IceFactory::_SetFpsControl(void) {
  SetKeyMapToKey(K_forward,  KEY_W);
  SetKeyMapToKey(K_backward, KEY_S);
  SetKeyMapToKey(K_left,     KEY_A);
  SetKeyMapToKey(K_right,    KEY_D);
  SetKeyMapToKey(K_pause,    KEY_BACKSPACE);
}


int   IceFactory::Start(void) {
  const int status = GetEngineStatus();
  if (status != S_EngineBuild && status != S_EngineStop && status != S_EngineReboot) {
    DEBUG_P(red, "IceFactory::Start engine status %d", status);
    return 0;
  }
  for (size_t i = 0; i < MAX_ROOM + 1; i++) {
    __roomsEngine[i] = nullptr;
  }
  if (!TestDependency())
    return 0;
  __userSeting.targetFps = 60;
  __userSeting.targetWindowSize = {600, 600};
  __inputSelect = KeybordMouse;
  __numberGamepads = 0; // TODO defalut, add look up
  for (int i = 0; i < t_ControlKeys::K_End; i++) {
    __keyMapBind[(t_ControlKeys)i] = KEY_NULL;
  }
  __roomsEngine[0] = new Room("backup");
  if (!__roomsEngine[0])
    throw std::runtime_error("new room fail");
  __renderEngine.SetRoom(__roomsEngine[0]);
  __roomsEngine[0]->SetRoomType(room_noType);
  SetEngineStatus(S_EngineInit);
  _SetFpsControl(); // defalut gamemode
  if (status == S_EngineReboot)
    __engineStatus = S_EngineRun;
  return 1;
}

IceFactory::IceFactory(void):
_root("root"), __currentRoom(nullptr), __screenSize({1000, 1000}), __inputSelect(0), \
__numberGamepads(0)
{
  __gameName = ("test");
  DEBUG_P(magenta, "IceFactory::");
  SetEngineStatus(S_EngineBuild);
  // error and debug
}

IceFactory::~IceFactory(void) {
  DEBUG_P(magenta, "IceFactory::~");
}
// - - - - - - - - - - - - - - - -

void  IceFactory::SetEngineStatus(const t_EngineStatus status) {
  __engineStatus = status;
}

// - - - - - - - - - - - - - - - -

const Vector2 IceFactory::GetMonitorSize(void) {
  if (IceFactory::GetEngineStatus()) {
    const int monitor  = GetCurrentMonitor();
    const float width  = GetMonitorWidth(monitor) ;
    const float height = GetMonitorHeight(monitor);
    DEBUG_P(green, "IceFactory::GetMonitorSize monitor:%d width%f height%f", monitor, width, height);
    return ((Vector2){width, height});
  }
  return ((Vector2){0, 0});
}

const Vector2 IceFactory::GetWindowSize(void) {
  if (IceFactory::GetEngineStatus()) {
    const Vector2  WindowSize = (Vector2){(float)GetRenderWidth() ,(float)GetRenderHeight()};
    DEBUG_P(green, "IceFactory::GetWindowSize Width:%f Height:%f", WindowSize.x, WindowSize.y);
    return (WindowSize);
  }
  return ((Vector2){0, 0});
}



// - - - - - - - - - - - - - - - -

int  IceFactory::initEngine(void) {
  __currentRoom = __roomsEngine[0];
  InitRaylib();
  const int monitor = GetCurrentMonitor();
  const int fpsTarget = GetMonitorRefreshRate(monitor);
  DEBUG_P(orange, "IceFactory::initEngine monitor:%d -> targetFps:%d", monitor, fpsTarget);
  SetTargetFPS(fpsTarget);
  return 1;
}

bool IceFactory::IceFactoryInitRayLib(void) {
  InitWindow(__screenSize.x, __screenSize.y, __gameName.c_str());
  if (!IsWindowReady()) {
    return false;
  }
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
    if (!IsModelValid(Models.Get(ERR_MESH))) {
      DEBUG_P(red, "error loading");
    }
    __what = Models.Get(ERR_MESH);
  }
  else {
    DEBUG_P(red, "raylib run all ready");
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
  if (GetEngineStatus() != S_EngineReboot)
    __engineStatus = S_EngineStop;
  Models.Clear();
  for(size_t i = 0; i < MAX_ROOM + 1; i++) {
    if (__roomsEngine[i])
      delete __roomsEngine[i];
    __roomsEngine[i] = nullptr;
  }
  __currentRoom = nullptr;
  //!last step
  if (GetEngineStatus() != S_EngineReboot)
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

void  __setCursor(bool mode) {
  if (mode) {
    ShowCursor();
    EnableCursor();
  }
  else {
    HideCursor();
    DisableCursor();
  }
}


/// @brief call UpdateInpus and UpdateEvent
/// @param  
/// @return 
int   IceFactory::UpdateEngine(void) {
  //ClearBackground(BLANK); //! render job? yes :>
  __renderEngine.Draw();
  const int status = UpdateInpus() + UpdateEvent();
  if (__EngineEvent[Event_window_resized]) {
    __screenSize = IceFactory::GetWindowSize();
  }
  if (IsKeyPressed(KEY_HOME)) {
    #ifdef HOT_RELOAD
    SetEngineStatus(S_EngineReboot);
    #else
    DEBUG_P(red, "hot reload not support");
    #endif
  }
  if (IsKeyPressed(KEY_ESCAPE)) { SetEngineStatus(S_EngineUnload); }
  if (ReadEnvent(Event_pause))  {
    static bool pause = false;
    __setCursor(IsCursorHidden());
    if (!pause)
      SetEngineStatus(S_EnginePause);
    else
      SetEngineStatus(S_EngineRun);
    pause = !pause;
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

bool  IceFactory::AddCameraToUpdateList(BaseCamera* camera) {
  if (!camera) {
    DEBUG_P(red, "IceFactory::AddCameraToUpdateList no camera");
    return false;
  }
  if (!__currentRoom) {
    DEBUG_P(red, "IceFactory::AddCameraToUpdateList no room!?");
    return false;
  }
  __currentRoom->AddCamera(camera);
  return true;
}


Room* IceFactory::GetRoom(size_t index) {
  return __roomsEngine[index];
}




//*                  *//*                  *//
//*                                        *//
//*                 KEYBORD                *//
//*                                        *//
//*                                        *//
//*                  *//*                  *//


void   IceFactory::SetKeyMapToKey(t_ControlKeys action, KeyboardKey key) {
  DEBUG_P(orange, "action[%d] key%d", action, key);
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