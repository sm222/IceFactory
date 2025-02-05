# include "../Engine/IceFactory.hpp"
# include "../Engine/Object/DevCube.hpp"
# include "../Engine/Camera/BaseCamera.hpp"
# include <iostream>

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
  BaseCamera Wepon;
  SetTargetFPS(144);
  Vector2 small = engine.GiveWindowSize();
  PlayerCamera.SetPosition((Vector3){1, 0, 1});
  PlayerCamera.SetCanvas(small);
  PlayerCamera.SetTarget(Vector3 {0,0,0});
  //-------
  Wepon.SetPosition((Vector3){1, 0, 1});
  Wepon.SetCanvas(small);
  Wepon.SetTarget(Vector3 {0,0,0});
  //
  Groups<Object*>* weponModel = engine._mainGroups.GetGroupChildById(2);
  //
  HideCursor();
  DisableCursor();
  std::cout << PlayerCamera.SetMode(t_camera_mode::camera_texture) << "\n";
  std::cout << Wepon.SetMode(t_camera_mode::camera_texture) << "\n";
  while (!WindowShouldClose()) {
    engine.UpdateEngine();
    if (engine.ReadEnvent(Event_window_resized)) { 
      PlayerCamera.SetCanvas(engine.GiveWindowSize());
      Wepon.SetCanvas(engine.GiveWindowSize());
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
    //
    PlayerCamera.Start();
    engine._mainGroups.Run(Object::CallDraw, rm);
    DrawPlane({0,-1, 0}, {40, 40}, GRAY);
    PlayerCamera.Stop();
    Wepon.Start();
    const float cs = 0.1f;
    DrawCube({0,0,0},cs,cs,cs, RED);
    weponModel->Run(Object::CallDraw, rm);
    Wepon.Stop();
    BeginDrawing();
    PlayerCamera.DrawFrame({0,0});
    Wepon.DrawFrame({0,0});
    DrawFPS(0,0);
    EndDrawing();
    PlayerCamera.Clear();
    Wepon.Clear();
  }
}

//LoadRenderTexture

int main(void) {
  IceFactory engine;
  int run = 1;
  Object*     ptr = new Object();
  MeshObject* m   = new MeshObject();
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
        m->SetErrorModel(engine.GiveWhatModel());
        m->SetModel("Engine/Resource/Models/Glock18.glb");
        newGroup.Add(m);
        engine._mainGroups.Add(ptr);
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