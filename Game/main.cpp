# include "../Engine/IceFactory.hpp"
# include "../Engine/Object/DevCube.hpp"
# include "../Engine/Camera/BaseCamera.hpp"
# include <iostream>

//# define  CLAY_IMPLEMENTATION
//# include "../Engine/include/clay.h"

typedef struct shot {
  Ray   ray;
  float time;
  Color c;
  void update(void) {
    time -= 0.01;
    SetRandomSeed((unsigned int)GetTime() / 2);
    switch (GetRandomValue(0, 2)) {
    case 0:
      if (c.r > 0) {
        c.r -= 1;
      }
      break;
    case 1:
      if (c.g > 0) {
        c.g -= 1;
      }
      break;
    case 2:
      if (c.b > 0) {
        c.b -= 1;
      }
      break;
    default:
      break;
    }
  }
} t_shot;

std::vector<t_shot*>    bullet;

void UpatePlayer(IceFactory& engine, BaseCamera& PlayerCamera) {
  if (engine.GetEngineStatus() != S_EnginePause) {
    PlayerCamera.Update(
    (Vector3) { engine.timeScale(engine.GetAnalogInput(ForwardBackward) * 5.0f),
                engine.timeScale(engine.GetAnalogInput(LeftRight) * 5.0f),
                0.0f },
    (Vector3) { engine.GetAnalogInput(MouseHorizontal) * 0.05f, // Rotation: yaw
                engine.GetAnalogInput(MouseVertical)   * 0.05f, // Rotation: pitch
                0.0f /* Rotation: roll*/ },
                0);
  }
}

int rm = 0;

void loop(IceFactory& engine) {
  BaseCamera PlayerCamera;
  SetTargetFPS(144);
  Vector2 small = engine.GiveWindowSize();
  PlayerCamera.SetPosition((Vector3){1, 0, 1});
  PlayerCamera.SetCanvas(small);
  PlayerCamera.SetTarget(Vector3 {0,0,0});
  //-------
  //
  HideCursor();
  DisableCursor();
  PlayerCamera.SetMode(t_camera_mode::camera_texture);
  Vector2 offset = {0,0};
  Vector2 offsetTxT = {0,0};
  TextBox* t = new TextBox;
  t->SetColor(GREEN);
  t->SetData({{0,0,0,0}, true, 0});
  for (size_t i = 0; i < 10; i++) {
    std::string ss = "ab";
    for (size_t j = 0; j < i; j++) {
      ss += "cdef";
    }
    t->pushText(ss, 0, RED);
  }
  t->SetFontSize(20);
  while (!WindowShouldClose()) {
    engine.UpdateEngine();
    if (engine.ReadEnvent(Event_window_resized)) { 
      PlayerCamera.SetCanvas(engine.GiveWindowSize());
    }
    UpatePlayer(engine, PlayerCamera);
    //
    if (IsKeyPressed(KEY_L)) {
      rm++;
      if (rm > 2)
        rm = 0;
    }
    if (engine.ReadEnvent(Event_pause)) {
      if (IsCursorHidden()) {
        ShowCursor();
        EnableCursor();
        engine.SetEngineStatus(S_EnginePause);
      }
      else {
        HideCursor();
        DisableCursor();
        engine.SetEngineStatus(S_EngineRun);
      }
    }
    //SetMousePosition(GetMonitorWidth(0) / 2, GetMonitorHeight(0) / 2);
    ClearBackground(BLANK);
    if (IsKeyPressed(KEY_ENTER)) {
      PlayerCamera.SetTarget((Vector3){0,0,0});
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      t_shot* ptr = new t_shot;
      ptr->time = 10;
      const Vector2 mid = small / 2;
      ptr->ray = GetScreenToWorldRay(mid, PlayerCamera.GetCamera());
      ptr->c.b = 255;
      ptr->c.r = 255;
      ptr->c.g = 255;
      ptr->c.a = 255;
      bullet.push_back(ptr);
    }
    //
    if (IsKeyDown(KEY_RIGHT)) {
      offset.x++;

    }
    if (IsKeyDown(KEY_UP)) {
      offsetTxT.y--;
      t->SetOffset(offsetTxT);
    }
    if (IsKeyDown(KEY_DOWN)) {
      offsetTxT.y++;
      t->SetOffset(offsetTxT);
    }
    //
    PlayerCamera.Start();
    std::vector<t_shot*>::iterator it;
    for (it = bullet.begin(); it != bullet.end(); it++) {
      (*it)->update();
      if ((*it)->time > 0)
        DrawRay((*it)->ray, (*it)->c);
      else {
        bullet.erase(it);
        it--;
      }
    }
    
    DrawPlane({0,-1, 0}, {40, 40}, GRAY);
    PlayerCamera.Stop();
    BeginDrawing();
    PlayerCamera.DrawFrame({0,0});
    DrawFPS(0,0);
    EndDrawing();
    PlayerCamera.Clear();
  }
  delete t;
}

//LoadRenderTexture

int main(void) {
  IceFactory engine;
  int run = 1;
  std::cout << "main group id " << engine._mainGroups.GetId() << "\n";
  Groups<Object*> newGroup;
  std::cout << "newgroup id " << newGroup.GetId() << "\n";
  while (run) {
    switch (getStatusEngine()) {
      case S_EngineInit:
        engine.initEngine();
        break;
      case S_EngineStart:
        engine.initRaylib();
        break;
      case S_EngineRun:
        engine._mainGroups.AddChild(&newGroup);
        SetTraceLogLevel(LOG_DEBUG);
        loop(engine);
        engine._mainGroups.Delete(-1);
        engine.closeEngine();
        break;
      case S_EngineStop:
        run = 0;
        break;
      default:
        break;
    }
  }
  return 0;
}