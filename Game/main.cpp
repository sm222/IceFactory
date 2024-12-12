# include "../Engine/IceFactory.hpp"
# include <iostream>


void loop(IceFactory& engine) {
  while (!WindowShouldClose()) {
    BeginDrawing();
    BeginTextureMode(engine.GetViewPort());
    ClearBackground(WHITE);
    EndTextureMode();
    const Texture2D& T = engine.GetViewPort().texture;
    DrawTexture(T, 0,0, WHITE);
    EndDrawing();
  }
}

//LoadRenderTexture

int main(void) {
  IceFactory engine;
  int run = 1;
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