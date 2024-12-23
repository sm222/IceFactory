# include "../Engine/IceFactory.hpp"
# include <iostream>

CameraGame cam;

const Vector3 h = {0,0,0};

int drawP(Object *p) {
  const float d = -1.5;
  Vector3 end = p->GetPosition();
  end.x += d;
  DrawLine3D(p->GetPosition(), end , RED);
  end.x -= d;
  end.y += d;
  DrawLine3D(p->GetPosition(), end , BLUE);
  end.y -= d;
  end.z += d;
  DrawLine3D(p->GetPosition(), end , GREEN);
  return 0;
}


void loop(IceFactory& engine) {
    cam.cam.position = (Vector3){-5, 0, -5};
  while (!WindowShouldClose()) {
    BeginDrawing();
    BeginTextureMode(engine.GetViewPort());
    BeginMode3D(cam.cam);
    cam.box.c = BLACK;
    ClearBackground(WHITE);
    cam.setBox();
    engine._mainGroups.Run(drawP);
    cam.box.Draw();
    EndMode3D();
    EndTextureMode();
    if (IsKeyDown(KEY_UP))
      cam.lookUp(0.0001);
    if (IsKeyDown(KEY_DOWN))
      cam.lookDown(0.0001);
    if (IsKeyDown(KEY_LEFT))
      cam.lookLeft(0.01);
    if (IsKeyDown(KEY_RIGHT))
      cam.lookRight(0.01);
    const Texture2D& T = engine.GetViewPort().texture;
    DrawTexture(T, 0,0, WHITE);
    EndDrawing();
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