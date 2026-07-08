#include <stdio.h>
#include "../thirdParty/raylib/src/raylib.h"
#include "../thirdParty/raylib/src/raymath.h"

Vector2  FlaotToVec2(float angle) {
  return (Vector2){sin(angle * DEG2RAD), cos(angle * DEG2RAD)};
}

int main(void) {
  unsigned int f =  \
  FLAG_WINDOW_RESIZABLE \
  | FLAG_WINDOW_TRANSPARENT \
  | FLAG_VSYNC_HINT \
  | FLAG_MSAA_4X_HINT;
  SetConfigFlags(f);
  InitWindow(1080, 720, "raylib example - basic window");
  SetTraceLogLevel(0);
  SetTargetFPS(144);
  Image flower = LoadImage("dev2.png");
  Texture2D img = LoadTextureFromImage(flower);
  RenderTexture2D layer = LoadRenderTexture(1080, 720);
  float s = 0;
  const Camera3D camera = {{-1,0,-1}, {0,0,0}, {0,1,0}, 90, CAMERA_PERSPECTIVE};
  while (!WindowShouldClose()) {
    BeginTextureMode(layer);
    ClearBackground(BLANK);
    DrawText("Hello world", 10, 10, 20, RED);
    BeginMode3D(camera);
    Vector2 balls = FlaotToVec2(s);
    DrawSphere((Vector3){0,1,0}, 0.5f, GREEN);
    DrawSphere((Vector3){0,-1,0}, 0.5f, RED);
    DrawSphere((Vector3){balls.x,0,balls.y}, 0.5f, BLUE);
    EndMode3D();
    EndTextureMode();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    Rectangle r = {0,0, img.width , img.height};
    const float a = img.width;
    const float b = img.height;
    s += 100 * GetFrameTime();
    Rectangle r2 = {a * 2,b * 2, a * 4, b * 4};
    DrawTexturePro(img, r, r2, (Vector2){a * 2 , b * 2}, s, WHITE);
    const Rectangle src = {0,0, layer.texture.width, -layer.texture.height};
    const Rectangle dest = {0,0, 1080, 720};
    DrawTexturePro(layer.texture, src, dest, (Vector2){0, 0}, 0, WHITE);
    DrawFPS(0, 0);
    EndDrawing();
  }
  UnloadTexture(img);
  UnloadImage(flower);
  UnloadRenderTexture(layer);
  CloseWindow();
  return 0;
}