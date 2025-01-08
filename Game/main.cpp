# include "../Engine/IceFactory.hpp"
# include "../Engine/Object/DevCube.hpp"
# include "../Engine/Camera/BaseCamera.hpp"
# include <iostream>



const Vector3 h = {0,0,0};


void DrawGrid(int sizeX, int sizeZ, int Y) {
  const float boxsize = 0.1;
  for (int i = (sizeX / 2) * -1; i < sizeX / 2; i++) {
    for (int j = (sizeZ / 2) * -1; j < sizeZ / 2; j++) {
      Vector3 p = {(float)i , (float)Y, (float)j};
      DrawCube(p, boxsize, boxsize, boxsize, GREEN);
    }
  }
  
}


void loop(IceFactory& engine) {
  BaseCamera PlayerCamera;
  SetTargetFPS(60);
  PlayerCamera.SetPosition((Vector3){1, 0, 1});
  PlayerCamera.SetCanvas(engine.GiveWindowSize());
  PlayerCamera.SetTarget(Vector3 {0,0,0});
  HideCursor();
  DisableCursor();
  while (!WindowShouldClose()) {
    engine.UpdateEngine();
    PlayerCamera.Update(
    (Vector3) { engine.timeScale(engine.getAnalogInput(ForwardBackward) * 5.0f),
                engine.timeScale(engine.getAnalogInput(LeftRight) * 5.0f),
                0.0f },
    (Vector3) { engine.getAnalogInput(MouseHorizontal) * 0.05f, // Rotation: yaw
                engine.getAnalogInput(MouseVertical)* 0.05f, // Rotation: pitch
                0.0f /* Rotation: roll*/ } ,
          GetMouseWheelMove());
    //
    if (engine.ReadEnvent(Event_pause)) {
      if (IsCursorHidden()) {
        ShowCursor();
        EnableCursor();
      }
      else {
        HideCursor();
        DisableCursor();
      }
    }
    //SetMousePosition(GetMonitorWidth(0) / 2, GetMonitorHeight(0) / 2);
    BeginDrawing();
    ClearBackground(BLACK);
    if (IsKeyPressed(KEY_ENTER)) {
      PlayerCamera.SetTarget((Vector3){0,0,0});
    }
    PlayerCamera.Start();
    engine._mainGroups.Run(Object::CallDraw);
    PlayerCamera.Stop();
    PlayerCamera.DrawFrame((Vector2){0 ,0}, 0.0f);
    DrawFPS(0,0);
    EndDrawing();
    PlayerCamera.Clear();
  }
}

//LoadRenderTexture

int main(void) {
  IceFactory engine;
  int run = 1;
  Object* ptr = new Object();
  DevCube* c = new DevCube();
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
        engine._mainGroups.Add(ptr);
        engine._mainGroups.AddChild(&newGroup);
        newGroup.Add(c);
        SetTraceLogLevel(LOG_DEBUG);
        loop(engine);
        engine.closeEngine();
        engine._mainGroups.Rm(ptr);
        newGroup.RmI(0);
        break;
      case S_EngineStop:
        run = 0;
        break;
      default:
        break;
    }
  }
  delete ptr;
  delete c;
  return 0;
}