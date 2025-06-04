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


bool   Render::SetRoom(Room* room) {
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


static unsigned int __DrawGroupType(const BaseGroup& group, const unsigned short t) {
  unsigned int totalPass = 1;
  for (size_t i = 0; i < group.Size(); i++) {
    const Base* ptr = group.GetByIndex(i);
    const char* type = ptr->GetType();
    if (strcmp(type, TYPE_BASE_GROUP) == 0)
      totalPass += __DrawGroupType((const BaseGroup&)*ptr, t);
    else {
      if (ptr->GetDrawType() == t) {
        totalPass++;
        ptr->Draw(ptr->GetMetod());
      }
    }
  }
  return totalPass;
}


int DrawFrame3D(const BaseCamera& camera, const BaseGroup& group, RenderTexture2D& layer) {
  BeginTextureMode(layer);
  ClearBackground(BLANK);
  BeginMode3D(camera.GetCamera());
  __DrawGroupType(group, 3);
  EndMode3D();
  EndTextureMode();
  return 0;
}


static int DrawFrame(const Base* camera, const BaseGroup& group, RenderTexture2D& layer) {
  int error = 0;
  if (!camera)
    return ++error;
  const char* type = camera->GetType();
  if (strcmp(BASE_CAMERA, type) == 0) {
    BaseCamera& renderDevice = *(BaseCamera*)camera;
    DrawFrame3D(renderDevice, group, layer);
  }
  else if (strcmp("camera_2D", type) == 0) {
    printf(" -");
  }
  else {
    error++;
  }
  return error;
}


int   Render::Update(void) {
  int error = 0;
  if (!__current)
    return ++error;
  const Instruction& in = __current->GetRenderRule();
  for (size_t i = 0; i < in.size(); i++) {
    const RenderInstruction c = R_GET_CAMERA(in[i]);
    const RenderInstruction l = R_GET_LAYER(in[i]);
    const RenderInstruction g = R_GET_GROUP(in[i]);
    if (!c && !l && !g)
      continue ;
    else if (!c || !l || !g) {
      DEBUG_P(red, "Render::Update c:%d l:%d g:%d", c, l, g);
      error++;
      continue ;
    }
    if (!__current->GetLayerValid(i)) {
      DEBUG_P(red, "Render::Update [%zu]Rtexture not valid", i);
      error++;
      continue ;
    }
    const BaseGroup* group = __current->GetToRender(i);
    if (!group || !group->Size()) {
      error++;
      DEBUG_P(red, "Render::Update [%zu]no group", i);
      continue ;
    }
    const Base* camera = __current->GetPov(i);
    if (!camera) {
      DEBUG_P(red, "Render::Update [%zu] messing camera", i);
      error++;
      continue ;
    }
    DrawFrame(camera, *group, __current->GetLayer(i));
  }
  BeginDrawing();
  ClearBackground(BLACK);
  for (unsigned short i = 0; i < __current->GetLayerSize(); i++) {
    RenderTexture2D& t = __current->GetLayer(i);
    if (IsRenderTextureValid(t)) {
      const Rectangle src = {0,0, (float)t.texture.width, -(float)t.texture.height};
      DrawTextureRec(t.texture, src, (Vector2){0,0}, WHITE);
    }
  }
  DrawFPS(0, 0);
  EndDrawing();
  //DrawTexturePro(
  //  Texture2D texture, 
  //  Rectangle source, Rectangle dest, 
  //  Vector2 origin, float rotation, Color tint)
  return error;
}
