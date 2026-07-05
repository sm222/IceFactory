
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
      DEBUG_P(TXT_RED, "✕ %s", _dependency[i]);
      perror("access");
      return false;
    }
    DEBUG_P(TXT_GRN, "✓ %s", _dependency[i]);
  }
  return true;
}

void IceFactory::_SetFpsControl(void) {
  SetKeyMapToKey(K_Forward,  KEY_W);
  SetKeyMapToKey(K_Backward, KEY_S);
  SetKeyMapToKey(K_Left,     KEY_A);
  SetKeyMapToKey(K_Right,    KEY_D);
  SetKeyMapToKey(K_Pause,    KEY_BACKSPACE);
}


int   IceFactory::Start(void) {
  const int status = GetEngineStatus();
  if (status != S_EngineBuild && status != S_EngineStop && status != S_EngineReboot) {
    DEBUG_P(TXT_RED, "engine status %d", status);
    return Start_fail;
  }
  if (!TestDependency())
    return Start_fail;
  __userSeting.targetFps = 60;
  __userSeting.targetWindowSize = {600, 600};
  __inputSelect = KeybordMouse;
  __numberGamepads = 0; // TODO defalut, add look up
  for (int i = 0; i < t_ControlKeys::K_End; i++) {
    __keyMapBind[(t_ControlKeys)i] = KEY_NULL;
  }
  SetEngineStatus(S_EngineInit);
  _SetFpsControl(); // defalut gamemode
  if (status == S_EngineReboot)
    __engineStatus = S_EngineRun;
  return no_error;
}

int  IceFactory::Reboot(int type) {
  (void)type; //! add later
  return this->Start() + this->InitEngine();
}

void  IceFactory::Stop(void) {
  this->SetEngineStatus(S_EngineForceStop);
  this->CloseEngine();
}

IceFactory::IceFactory(void):
__render(),
__screenSize({1000, 1000}),
__inputSelect(0),
__numberGamepads(0),
__root((char*)"root")
{
  __gameName = ("test");
  DEBUG_P(TXT_MAG, "");
  SetEngineStatus(S_EngineBuild);
  // error and debug
}

IceFactory::~IceFactory(void) {
  DEBUG_P(TXT_MAG, "");
}
// - - - - - - - - - - - - - - - -

void  IceFactory::SetEngineStatus(const t_EngineStatus status) {
  if (__engineStatus != S_EngineForceStop)
    __engineStatus = status;
}

// - - - - - - - - - - - - - - - -

const Vector2 IceFactory::GetMonitorSize(void) {
  if (IceFactory::GetEngineStatus()) {
    const int monitor  = GetCurrentMonitor();
    const float width  = GetMonitorWidth(monitor) ;
    const float height = GetMonitorHeight(monitor);
    DEBUG_P(TXT_ORG, "monitor:%d width%f height%f", monitor, width, height);
    return ((Vector2){width, height});
  }
  return (Vector2Zero());
}

const Vector2 IceFactory::GetWindowSize(void) {
  if (IceFactory::GetEngineStatus()) {
    const Vector2  WindowSize = (Vector2){(float)GetRenderWidth() ,(float)GetRenderHeight()};
    DEBUG_P(TXT_ORG, "Width:%f Height:%f", WindowSize.x, WindowSize.y);
    return (WindowSize);
  }
  return (Vector2Zero());
}



// - - - - - - - - - - - - - - - -

int  IceFactory::InitEngine(void) {
  InitRaylib();
  const int monitor = GetCurrentMonitor();
  const int fpsTarget = GetMonitorRefreshRate(monitor);
  DEBUG_P(TXT_ORG, "monitor:%d -> targetFps:%d", monitor, fpsTarget);
  __render.AddLayer("main", __screenSize);
  SetTargetFPS(fpsTarget);
  SetExitKey(KEY_NULL);
  return 1;
}

bool IceFactory::IceFactoryInitRayLib(void) {
  InitWindow(__screenSize.x, __screenSize.y, __gameName.c_str());
  if (!IsWindowReady()) {
    fprintf(stderr, "InitWindow: faild\n");
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
      DEBUG_P(TXT_RED, "error loading");
    }
    __what = Models.Get(ERR_MESH);
  }
  else {
    DEBUG_P(TXT_RED, "raylib run all ready");
  }
  return true;
}

bool IceFactory::CloseRaylib(void) {
  if (__raylib) {
    DEBUG_P(TXT_RED, "raylib was close");
    CloseWindow();
    __raylib = false;
  }
  return true;
}

// Rap around raylib
bool IceFactory::CloseEngine(void) {
  if (GetEngineStatus() != S_EngineReboot)
    __engineStatus = S_EngineStop;
  Models.Clear();
  Audios.Clear();
  Textures2D.Clear();
  __render.Close();
  //!last step
  if (GetEngineStatus() != S_EngineReboot)
    CloseRaylib();
  CloseRaylib();
  return true;
}


Vector2  IceFactory::FlaotToVec2(float angle) {
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
  __EngineEvent[Event_pause] = IsKeyPressed(__keyMapBind[K_Pause]);
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
  const int status = UpdateInpus() + UpdateEvent();
  Audios.Update();
  if (__EngineEvent[Event_window_resized]) {
    __screenSize = IceFactory::GetWindowSize();
  }
  if (IsKeyPressed(KEY_HOME)) {
    #ifdef HOT_RELOAD
      SetEngineStatus(S_EngineReboot);
    #else
      DEBUG_P(TXT_RED, "hot reload not support");
    #endif
  }
  if (IsKeyPressed(DEFAULT_CLOSE_KEY)|| WindowShouldClose()) { SetEngineStatus(S_EngineUnload); }
  if (ReadEnvent(Event_pause))  {
    static bool pause = false; //! put in class engine
    __setCursor(IsCursorHidden());
    if (!pause)
      SetEngineStatus(S_EnginePause);
    else
      SetEngineStatus(S_EngineRun);
    pause = !pause;
  }
  //! replace by render
  BeginDrawing();
  ClearBackground(BLACK);
  DrawFPS(0, 0);
  EndDrawing();
  return status;
}


float  IceFactory::GetAnalogInput(const t_Controls name) const {
  std::map<t_Controls, float>::const_iterator it = __analogMap.find(name);
  if (it != __analogMap.end())
    return ((*it).second);
  return 0;
}

float  IceFactory::TimeScale(float in) {
  return in * GetFrameTime() * __timeScale;
}

void   IceFactory::SetTimeScale(float scale) {
  __timeScale = scale;
}

Vector2 IceFactory::GiveWindowSize(void) {
  return __screenSize;
}


bool IceFactory::ResizeWindowSize(Vector2 size) {
  if (this->GetEngineStatus() == S_EngineRun) {
    SetWindowMinSize((int)size.x, (int)size.y);
    return true;
  }
  return false;
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
  DEBUG_P(TXT_ORG, "action[%d] key %d", action, key);
  __keyMapBind[action] = key;
}


// fps controls
void IceFactory::UpdateKeybord(void) {
  __analogMap[ForwardBackward] = (IsKeyDown(__keyMapBind[K_Forward]) - (IsKeyDown(__keyMapBind[K_Backward])));
  __analogMap[LeftRight]       = (IsKeyDown(__keyMapBind[K_Right])   - (IsKeyDown(__keyMapBind[K_Left])) );
}


//*                  *//*                  *//
//*                                        *//
//*                 GAMEPAD                *//
//*                                        *//
//*                                        *//
//*                  *//*                  *//
