
// raylib
#include "../../Engine/include/raylib/src/raylib.h"
#include "../../Engine/include/raylib/src/raymath.h"
// - - - -
#include <iostream>
#include <stdio.h>
int width, height;

// --
// 
// 
// --

void theehe(Color& c) {
    const int r = GetRandomValue(0, 2);
    if (r == 0)
      c.r++;
    if (r == 1)
      c.g++;
    if (r == 2)
      c.b++;
}

int main(void) {
  width = 1080;
  height = 720;
  std::cout << "hello world" << std::endl;
  InitWindow(width, height, "hello!");
  if (!IsWindowReady())
    exit(EXIT_FAILURE);
  Color c = GRAY;
  SetRandomSeed(time(nullptr));
  char txt[30];
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    theehe(c);
    snprintf(txt, 30, "r: %d\ng: %d\nb: %d\n", c.r, c.g, c.b);
    BeginDrawing();
    ClearBackground(c);
    DrawRectangle(0, 24, 100, 70, WHITE);
    DrawText(txt, 10, 30, 20, BLACK);
    DrawRectangle(0, 0, 100, 24, BLACK);
    DrawFPS(2, 2);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}