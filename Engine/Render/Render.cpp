#include "Render.hpp"



Render::Render(void) {
  DEBUG_P(TXT_MAG, "");
}

Render::~Render(void) {
  DEBUG_P(TXT_MAG, "");
}


void  SetRays(Ray rays[4 * ROOM_MAX_CAMERA], RoomRenderCamera* data, size_t i, size_t j) {
  rays[(i * 4) + j] = {{0,0,0},{0,0,0}};
  if (data->camera && data->camera->GetDebug())
    rays[(i * 4) + j] = data->camera->GetRay(j);
}


void  DrawOnLayer(const struct RoomRenderCamera* data) {
  if (!data->camera || !data->toRender)
    return ;
  //const clock_t s = clock();
  data->camera->Start();
  ClearBackground(data->camera->GetCleanColor());
  data->camera->Stop();
  //UpdateGraffValue(g, clock() - s);
}


void Render::DrawRoom(const Room& room) const {
  Ray  rays[4 * ROOM_MAX_CAMERA];
  for (size_t i = 0; i < ROOM_MAX_CAMERA; i++) {
    for (size_t j = 0; j < 4; j++) {
      RoomRenderCamera data;
      if (room.GetRenderData(i, data))
        SetRays(rays, &data, i, j);
    }
  }
  for (size_t i = 0; i < ROOM_MAX_CAMERA; i++) {
    RoomRenderCamera data;
    if (room.GetRenderData(i, data))
      DrawOnLayer(&data);
  }
  //clock_t s = clock();
  BeginDrawing();
  for (size_t i = 0; i < ROOM_MAX_CAMERA; i++) {
    RoomRenderCamera data;
    room.GetRenderData(i, data);
    if (data.camera && data.camera->GetMode() == camera_texture) { data.camera->DrawFrameAuto(); }
  }
  DrawFPS(10, 10);
  EndDrawing();
}



void   Render::Draw(void) const {
  if (!__current) {
    BeginDrawing();
    #if (REDER_MODE_NO_ROOM)
      ClearBackground(BLACK);
    #endif
    #if (!REDER_DEV_DEBUG)
      DrawText("error : no room", 10, 10, 30, RED);
    #endif
    EndDrawing();
    return ;
  }
  DrawRoom(*__current);
}


bool   Render::SetRoom(Room* room) {
  if (!room) {
    DEBUG_P(TXT_RED, "Render::SetRoom no room was given");
    return false;
  }
  __current = room;
  return true;
}

bool   Render::RemoveRoom(void) {
  if (__current) {
    __current = nullptr;
    return true;
  }
  return false;
}




int DrawFrame3D(const BaseCamera& camera, RenderTexture2D& layer) {
  BeginTextureMode(layer);
  ClearBackground(BLANK);
  BeginMode3D(camera.GetCamera());
  EndMode3D();
  EndTextureMode();
  return 0;
}

int DrawFrame2D(const Camera2D& camera, RenderTexture2D& layer) {
  BeginTextureMode(layer);
  ClearBackground(BLANK);
  BeginMode2D(camera);
  EndMode2D();
  EndTextureMode();
  return 0;
}




int   Render::Update(void) {
  int error = 0;
  if (!__current)
    return ++error;
  BeginDrawing();
  ClearBackground(BLANK);
  for (unsigned short i = 0; i < 255; i++) {
    const t_layer& data = __current->GetLayerData(i);
    if (data.drawOnScrean) {
      const Rectangle src = {0,0, (float)data.l.texture.width, -(float)data.l.texture.height};
      DrawTexturePro(data.l.texture, src, data.dest, data.origin, data.rotation, data.tint);
      const Color C = (Color){0,255,0,60};
      DrawRectangleLinesEx((Rectangle){0,0, (float)data.l.texture.width, (float)data.l.texture.height}, 4, C);
    }
  }
  DrawFPS(700, 700);
  EndDrawing();
  //DrawTexturePro(
  //  Texture2D texture, 
  //  Rectangle source, Rectangle dest, 
  //  Vector2 origin, float rotation, Color tint)
  return error;
}
