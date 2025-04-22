#include "Render.hpp"



Render::Render(void) {
  DEBUG_P(magenta, "Render::");
}

Render::~Render(void) {
  DEBUG_P(magenta, "Render::~");
}

int   __DrawGroup(const BaseGroup* group, const RoomRenderCamera data) {
  int totalPass = 1;
  for (size_t i = 0; i < group->Size(); i++) {
    const Base* ptr = data.toRender->GetByIndex(i);
    const char* type = ptr->GetType();
    if (strcmp(type, TYPE_BASE_GROUP) == 0)
      totalPass += __DrawGroup((const BaseGroup*)ptr, data);
    else
      ptr->Draw(ptr->GetMetod());
  }
  return totalPass;
}

// make smaller later
void Render::DrawRoom(const Room& room) const {
  if (room.GetRoomType() == room_noType && 0) {
    BeginDrawing();
    ClearBackground(BLANK);
    EndDrawing();
    return;
  }
  static Graph g[ROOM_MAX_CAMERA];
  for (size_t i = 0; i < ROOM_MAX_CAMERA; i++) {
    g[i].sampleRate = 1;
    g[i].amplitude = 0.4;
    g[i].graphLen = GRAF_LEN / 4;
  }
  static Graph total = {.sampleRate = 1, .amplitude = 0.8, .graphLen = GRAF_LEN / 4};
  Ray  rays[4 * ROOM_MAX_CAMERA];
  for (size_t i = 0; i < ROOM_MAX_CAMERA; i++) {
    for (size_t j = 0; j < 4; j++) {
      RoomRenderCamera data = room.GetRenderData(i);
      rays[(i * 4) + j] = {{0,0,0},{0,0,0}};
      if (data.camera && data.camera->GetDebug())
        rays[(i * 4) + j] = data.camera->GetRay(j);
    }
  }
  for (size_t i = 0; i < ROOM_MAX_CAMERA; i++) {
    RoomRenderCamera data = room.GetRenderData(i);
    if (data.camera) {
      clock_t s = clock();
      data.camera->Start();
      ClearBackground(data.camera->GetCleanColor());
      for (size_t j = 0; j < ROOM_MAX_CAMERA * 4 - 1; j++) {
        if (rays[j].direction != (Vector3){0,0,0} && rays[j].position != (Vector3){0,0,0})
        DrawRay(rays[j], WHITE);
      }
      __DrawGroup(data.toRender, data);
      data.camera->Stop();
      UpdateGraffValue(&g[i], clock() - s);
    }
  }
  clock_t s = clock();
  BeginDrawing();
  for (size_t i = 0; i < ROOM_MAX_CAMERA; i++) {
    RoomRenderCamera data = room.GetRenderData(i);
    if (data.camera && data.camera->GetMode() == camera_texture) { data.camera->DrawFrameAuto(); }
  }
  DrawGraph(&g[0], 100, 400);
  DrawGraph(&g[1], 100, 550);
  UpdateGraffValue(&total, clock() - s);
  DrawGraph(&total, 100, 800);
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