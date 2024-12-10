# include "../Engine/IceFactory.hpp"
# include <iostream>


void loop(void) {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
  }
  CloseWindow();
}


int main(void) {
  int run = 1;
  while (run) {
    switch (getStatusEngine()) {
      case S_EngineInit:
        initEngine();
        break;
      case S_EngineStart:
        initRaylib();
        break;
      case S_EngineRun:
        std::cout << "?ici\n";
        loop();
        closeEngine();
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