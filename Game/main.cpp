# include "../Engine/IceFactory.hpp"
# include "../Engine/Object/DevCube.hpp"
# include "../Engine/Camera/BaseCamera.hpp"
# include <iostream>

FpsCamera cam;

BaseCamera PlayerCamera;

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
  SetTargetFPS(60);
  //Image flip;
  cam.setPotision((Vector3){-1, 0, -1});
  PlayerCamera.SetPosition(cam.getCamera().position);
  PlayerCamera.SetCanvas(engine.GiveWindowSize());
  PlayerCamera.SetTarget(Vector3 {0,0,0});
  while (!WindowShouldClose()) {
    engine.updateInpus();
    PlayerCamera.Update(
    (Vector3) { engine.timeScale(engine.getAnalogInput("FB") * 5.0f),
                engine.timeScale(engine.getAnalogInput("LR") * 5.0f),
                0.0f },
    (Vector3) { GetMouseDelta().x * 0.05f, // Rotation: yaw
                GetMouseDelta().y * 0.05f, // Rotation: pitch
                0.0f /* Rotation: roll*/ } ,
          GetMouseWheelMove());
    ///
    cam.updatePotision(
    (Vector3) { engine.timeScale(engine.getAnalogInput("FB") * 5.0f),
                engine.timeScale(engine.getAnalogInput("LR") * 5.0f),
                0.0f },
    (Vector3) { GetMouseDelta().x * 0.05f, // Rotation: yaw
                GetMouseDelta().y * 0.05f, // Rotation: pitch
                0.0f /* Rotation: roll*/ } ,
          GetMouseWheelMove());
    if (IsKeyPressed(KEY_F11)) {
      SetWindowSize(1200, 1200);
      SetWindowPosition(0,0);
    }
    //
    SetMousePosition(GetMonitorWidth(0) / 2, GetMonitorHeight(0) / 2);
    BeginDrawing();
    //  BeginTextureMode(engine.GetViewPort());
    //ClearBackground(BLACK);
    //BeginMode3D(cam.getCamera());
    //engine._mainGroups.Run(Object::CallDraw);
    //EndMode3D();
    //EndTextureMode();
    //
      //Texture2D T = engine.GetViewPort().texture;
      //flip = LoadImageFromTexture(T);
      //ImageFlipVertical(&flip);
      //Texture2D tmp = LoadTextureFromImage(flip);
      //UnloadImage(flip);
    //DrawTextureEx(tmp, {0, 0}, -0, 1, WHITE);
    PlayerCamera.Start();
    engine._mainGroups.Run(Object::CallDraw);
    PlayerCamera.Stop();
    PlayerCamera.DrawFrame((Vector2){0 ,0}, 0.0f);
    DrawFPS(0,0);
    EndDrawing();
    PlayerCamera.Clear();
    //UnloadTexture(tmp);
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
        std::cout << "!ici\n";
        break;
      case S_EngineRun:
        std::cout << "?ici\n";
        engine._mainGroups.Add(ptr);
        engine._mainGroups.AddChild(&newGroup);
        newGroup.Add(c);
        SetTraceLogLevel(LOG_NONE);
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
  std::cout << "retun main\n";
  //closeEngine();
  return 0;
}