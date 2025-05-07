#include "Render.hpp"



Render::Render(void) {
  DEBUG_P(magenta, "Render::");
}

Render::~Render(void) {
  DEBUG_P(magenta, "Render::~");
}

unsigned int __DrawGroup(const BaseGroup* group, const RoomRenderCamera data) {
  unsigned int totalPass = 1;
  for (size_t i = 0; i < group->Size(); i++) {
    const Base* ptr = data.toRender->GetByIndex(i);
    const char* type = ptr->GetType();
    if (strcmp(type, TYPE_BASE_GROUP) == 0)
      totalPass += __DrawGroup((const BaseGroup*)ptr, data);
    else {
      totalPass++;
      ptr->Draw(ptr->GetMetod());
    }
  }
  return totalPass;
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
  __DrawGroup(data->toRender, (*data));
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


bool   Render::SetRoom(const Room* room) {
  if (!room) {
    DEBUG_P(red, "Render::SetRoom no room was given");
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