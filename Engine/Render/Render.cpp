#include "Render.hpp"



Render::Render(void) {
  DEBUG_P(magenta, "Render::");
}

Render::~Render(void) {
  DEBUG_P(magenta, "Render::~");
}



void   __DrawGroup(const BaseGroup* group, const RoomRenderCamera data) {
  for (size_t i = 0; i < group->Size(); i++) {
    const Base* ptr = data.toRender->GetByIndex(i);
    const char* type = ptr->GetType();
    if (strcmp(type, TYPE_BASE_GROUP) == 0)
      __DrawGroup((const BaseGroup*)ptr, data);
    else
      ptr->Draw(ptr->GetMetod());
  }
}

void Render::DrawRoom(const Room& room) const {
  if (room.GetRoomType() == room_noType && 0) {
    BeginDrawing();
    ClearBackground(BLANK);
    EndDrawing();
    return;
  }
  for (size_t i = 0; i < ROOM_MAX_CAMERA; i++) {
    RoomRenderCamera data = room.GetRenderData(i);
    if (data.camera) {
      data.camera->Start();
      ClearBackground(data.camera->GetCleanColor());
      __DrawGroup(data.toRender, data);
      DrawCube({0,0,0}, 0.01, 0.01, 0.01, BLUE);
      data.camera->Stop();
    }
  }
  BeginDrawing();
  for (size_t i = 0; i < ROOM_MAX_CAMERA; i++) {
    RoomRenderCamera data = room.GetRenderData(i);
    if (data.camera && data.camera->GetMode() == camera_texture)
      data.camera->DrawFrame({0,0});
  }
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