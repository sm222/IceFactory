#include "UiRenderZone.hpp"

unsigned int UiRenderZone::__instanceRunning = 0;

unsigned int  UiRenderZone::__SetNewId(void) {
  unsigned int id = 0;
  return ++id;
}

void UiRenderZone::Zero(void) {
  ZERO_NONE_PTR(__canvas);
}


UiRenderZone::UiRenderZone(const char* name, int const& width, int const& height): Base(name),
  __offset({0,0}), __zone({0, 0, (float)width, (float)height}), __color(WHITE), __instance(0) {
  Zero();
}

UiRenderZone::UiRenderZone(const std::string& name, int const& width, int const& height): UiRenderZone(name.c_str(), width, height) {
}

UiRenderZone::UiRenderZone(const std::string& name, const Vector2& size): UiRenderZone(name, size.x, size.y) {
}


UiRenderZone::~UiRenderZone(void) {
  if (IsRenderTextureValid(__canvas))
    UnloadRenderTexture(__canvas);
}

ssize_t  UiRenderZone::Add(UiBaseBlock* block) {
  if (!block)
    return -1;
  block->_SetParant(*this);
  __objects.push_back(block);
  return __objects.size();
}

ssize_t UiRenderZone::Remove(size_t index) {
  if (index >= __objects.size())
    return -1;
  std::vector<UiBaseBlock*>::iterator it = __objects.begin() + index;
  __objects.erase(it);
  return __objects.size();
}

ssize_t UiRenderZone::Remove(const char* name) {
  if (!name)
    return -1;
  std::vector<UiBaseBlock*>::iterator it;
  const size_t nameLen = strlen(name) + 1;
  for (it = __objects.begin(); it != __objects.end(); it++) {
    const char* s1 = (*it)->GetName();
    if (strncmp(s1, name, nameLen) == 0) {
      (*it)->_UnsetParant();
      __objects.erase(it);
      return __objects.size();
    }
  }
  return -1;
}

ssize_t UiRenderZone::Remove(const std::string& name) {
  if (name.empty())
    return -1;
  std::vector<UiBaseBlock*>::iterator it;
  for (it = __objects.begin(); it != __objects.end(); it++) {
    const char* s1 = (*it)->GetName();
    if (strncmp(s1, name.c_str(), name.length() + 1) == 0) {
      (*it)->_UnsetParant();
      __objects.erase(it);
      return __objects.size();
    }
  }
  return -1;
}

void  UiRenderZone::SetSize(const Vector2& size) {
  __zone.width = size.x;
  __zone.height = size.y;
}

void  UiRenderZone::SetZone(const Rectangle& zone) {
  __zone = zone;
}

void  UiRenderZone::SetPosition(const Vector2& position) {
  __offset.x = position.x;
  __offset.y = position.y;
}

int  UiRenderZone::__UpdateRender(void) {
  if (!IsRenderTextureValid(__canvas)) {
    __canvas = LoadRenderTexture(__zone.width, __zone.height);
    return IsRenderTextureValid(__canvas);
  }
  const Vector2 v1 = {(float)__canvas.texture.width, (float)__canvas.texture.height};
  const Vector2 v2 = {__zone.width, __zone.height};
  if (IsRenderTextureValid(__canvas) && v1 != v2) {
    UnloadRenderTexture(__canvas);
    return __UpdateRender();
  }
  return true;
}


void  UiRenderZone::Render(void) {
  __UpdateRender();
  BeginTextureMode(__canvas);
  ClearBackground(BLANK);
  std::vector<UiBaseBlock*>::iterator it;
  for (it = __objects.begin(); it != __objects.end(); it++) {
    (*it)->Draw(0);
  }
  EndTextureMode();
}

void  UiRenderZone::Draw(int mode) {
  (void)mode;
  Rectangle r = __zone;
  r.height *= -1;
  DrawTextureRec(__canvas.texture, r, __offset, __color);
}
