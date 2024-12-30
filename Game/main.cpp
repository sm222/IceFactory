# include "../Engine/IceFactory.hpp"
# include <iostream>

CameraGame cam;

const Vector3 h = {0,0,0};

int drawP(Object *p) {
  Vector3 end = p->GetPosition();
  const float d = 0.4;
  end.x += d;
  //DrawLine3D(p->GetPosition(), end , RED);
  end.x -= d;
  end.y -= d;
  DrawLine3D(p->GetPosition(), end , BLUE);
  end.y += d;
  end.z += d;
  //DrawLine3D(p->GetPosition(), end , GREEN);
  return 0;
}

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
  SetTargetFPS(144);
  Image flip;
  cam.setPotision((Vector3){-1, 0, -1});
  while (!WindowShouldClose()) {
    engine.updateInpus();
    cam.updatePotision(
    (Vector3) { (engine.getAnalogInput("FB") * 0.05f),
                (engine.getAnalogInput("LR") * 0.05f),
                0.0f },
    (Vector3) { GetMouseDelta().x * 0.05f, // Rotation: yaw
                GetMouseDelta().y * 0.05f, // Rotation: pitch
                0.0f /* Rotation: roll*/ } ,
          GetMouseWheelMove());
    if (IsKeyPressed(KEY_F11)) {
      SetWindowSize(1200 * 2, 1200);
      SetWindowPosition(0,0);
    }
    //
    SetMousePosition(GetMonitorWidth(0) / 2, GetMonitorHeight(0) / 2);
    BeginDrawing();
      BeginTextureMode(engine.GetViewPort());
    ClearBackground(BLACK);
    BeginMode3D(cam.getCamera());
    engine._mainGroups.Run(drawP);
    for (int i = 0; i < 2; i++) {
      DrawGrid(15 - i, 15 - i, -1 - i);
    }
    DrawLine3D((Vector3){0, 0, 0},(Vector3) {0, 1, 0}, BLUE);
    EndMode3D();
    EndTextureMode();
      Texture2D T = engine.GetViewPort().texture;
      flip = LoadImageFromTexture(T);
      ImageFlipVertical(&flip);
      Texture2D tmp = LoadTextureFromImage(flip);
      UnloadImage(flip);
      DrawTextureEx(tmp, {0, 0}, -0, 1, WHITE);
    DrawFPS(0,0);
    //DrawTexture(T, 0, 0, WHITE);
    EndDrawing();
    UnloadTexture(tmp);
  }
}

//LoadRenderTexture

int main(void) {
  IceFactory engine;
  Object a("test");
  int run = 1;
  engine._mainGroups.Add(&a);
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
        loop(engine);
        engine.closeEngine();
        break;
      case S_EngineStop:
        run = 0;
        break;
      default:
        break;
    }
  }
  
  //closeEngine();
  return 0;
}