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
  MeshObject* ptr = new MeshObject();
  ptr->SetModel("Engine/Resource/Models/cube.glb");
  engine._mainGroups.Add(ptr);
  SetTargetFPS(60);
  PlayerCamera.SetPosition((Vector3){1, 0, 1});
  PlayerCamera.SetCanvas(engine.GiveWindowSize());
  PlayerCamera.SetTarget(Vector3 {0,0,0});
  HideCursor();
  DisableCursor();
  std::cout << PlayerCamera.SetMode(t_camera_mode::none) << "\n";
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
    ClearBackground(BLACK);
    if (IsKeyPressed(KEY_ENTER)) {
      PlayerCamera.SetTarget((Vector3){0,0,0});
    }
    //
    engine._mainGroups.MoveToward({0,1,0}, 0.001);
    BeginDrawing();
    PlayerCamera.Start();
    engine._mainGroups.Run(Object::CallDraw, rm);
    DrawPlane({0,-1, 0}, {40, 40}, GRAY);
    PlayerCamera.Stop();
    PlayerCamera.DrawFrame((Vector2){0, 0}, 0.0f);
    DrawFPS(0,0);
    EndDrawing();
    PlayerCamera.Clear();
  }
}

//LoadRenderTexture

int main(void) {
  IceFactory engine;
  int run = 1;
  Object*     ptr = new Object();
  MeshObject* m   = new MeshObject();
  DevCube*    c   = new DevCube();
  Groups<Object*> newGroup;
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
        engine._mainGroups.Add(m);
        engine._mainGroups.Add(ptr);
        engine._mainGroups.AddChild(&newGroup);
        newGroup.Add(c);
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