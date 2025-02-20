#include "UiRenderZone.hpp"

void UiRenderZone::Zero(void) {
  ZERO_NONE_PTR(__canvas);
}

UiRenderZone::UiRenderZone(const char* name, int const& width, int const& height):
  __offset({0,0}), __zone({0, 0, (float)width, (float)height}), __color(WHITE) {
  Zero();
  if (!name) {
    sprintf(__name, "noName");
  }
  else {
    size_t len = strlen(name);
    if (len > MAX_NAME_LEN) {
      memcpy(__name, name, MAX_NAME_LEN - 1);
      __name[MAX_NAME_LEN] = 0;
    }
    else {
      memcpy(__name, name, len);
      __name[len] = 0;
    }
  }
}

UiRenderZone::UiRenderZone(const std::string& name, int const& width, int const& height):
  __offset({0,0}), __zone({0, 0, (float)width, (float)height}), __color(WHITE) {
  Zero();
  size_t len = name.length();
  if (len > MAX_NAME_LEN) {
    memcpy(__name, name.c_str(), MAX_NAME_LEN - 1);
    __name[MAX_NAME_LEN] = 0;
  }
  else {
    memcpy(__name, name.c_str(), len);
    __name[len] = 0;
  }
}

UiRenderZone::UiRenderZone(const std::string& name, const Vector2& size):
  __offset({0,0}), __zone({0, 0, size.x, size.y}), __color(WHITE) {
  Zero();
  size_t len = name.length();
  if (len > MAX_NAME_LEN) {
    memcpy(__name, name.c_str(), MAX_NAME_LEN - 1);
    __name[MAX_NAME_LEN] = 0;
  }
  else {
    memcpy(__name, name.c_str(), len);
    __name[len] = 0;
  }
}


UiRenderZone::~UiRenderZone(void) {
  if (IsRenderTextureValid(__canvas))
    UnloadRenderTexture(__canvas);
}


ssize_t  UiRenderZone::Add(UiBaseBlock* block) {
  if (!block)
    return -1;
  block->SetParant(*this);
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
      (*it)->UnsetParant();
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
      (*it)->UnsetParant();
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
  __zone.x = position.x;
  __zone.y = position.y;
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
    //(*it)
  }
  EndTextureMode();
}

void  UiRenderZone::Draw(int mode) {
  (void)mode;
  Rectangle r = __zone;
  r.height *= -1;
  DrawTextureRec(__canvas.texture, r, __offset, __color);
  //DrawTextureRec(__canvas.texture, )
}

//* //////////////////////////////
//* //////////////////////////////

//* //////////////////////////////
//* //////////////////////////////


void BaseUi::Zero(void) {
  ZERO_NONE_PTR(__data);
  ZERO_NONE_PTR(__color);
  ZERO_NONE_PTR(__offset);
  ZERO_NONE_PTR(__rotation);
  ZERO_NONE_PTR(__main);
  __canvas = nullptr;
}

BaseUi::BaseUi(void) {
  Zero();
}


BaseUi::~BaseUi(void) {
  if (__canvas)
    delete __canvas;
}

// Set

const ui& BaseUi::GetData(void) const {
  return __data;
}

const Color& BaseUi::GetColor(void) const {
  return __color;
}

const Vector2& BaseUi::GetOffset(void) const {
  return __offset;
}

const float& BaseUi::GetRotation(void) const {
  return __rotation;
}

// Get

void BaseUi::SetData(const t_ui& ui) {
  __data = ui;
  Update();
}

void BaseUi::SetColor(const Color& color) {
  __color = color;
}

void BaseUi::SetOffset(const Vector2& position) {
  __offset = position;
}

void BaseUi::SetRotation(const float& rotation) {
  __rotation = rotation;
}

int BaseUi::Update(void) {
  if (__main == 0)
    return true;
  if (!__canvas) {
    std::cout << "error: Update " << this << " <-" << std::endl;
    return -1;
  }
  if (IsRenderTextureValid(*__canvas)) {
    UnloadRenderTexture(*__canvas);
  }
  (*__canvas) = LoadRenderTexture(__data.window.width, __data.window.height);
  return IsRenderTextureValid(*__canvas);
}

void BaseUi::SetFirst(void) {
  if (__main == 0 && !__canvas) {
    __main = 1;
    __canvas = new RenderTexture2D;
    if (__canvas) {
      RenderTexture2D& t = (*__canvas);
      ZERO_NONE_PTR(t);
      Update();
    }
  }
}

//
void BaseUi::Draw(int mode) const {
  int f = 0;
  if (__canvas && __main == 1) {
    BeginTextureMode(*__canvas);
    f = 1;
    ClearBackground(__color);
  }
  else
    DrawRectanglePro(__data.window, __offset, __rotation, __color);
  std::vector<BaseUi*>::const_iterator it;
  for (it = __child.begin(); it != __child.end(); it++) {
    (*it)->Draw(++mode);
  }
  if (f) {
    EndTextureMode();
    Rectangle r = __data.window;
    r.height *= -1;
    DrawTextureRec((*__canvas).texture, r, {__offset.x, __offset.y}, WHITE);
  }
}

void BaseUi::AddChild(BaseUi* ui) {
  __child.push_back(ui);
}

TextBox::TextBox(void): __max(MAX_TEXT_BOX_SIZE), __pushIndex(0) {

}

void  TextBox::Draw(int mode) const {
  (void)mode;
  for (size_t i = 0; !__text[i].s.empty() && i < __max; i++) {
    Vector2 DrawP = {__data.window.x + __offset.x, __data.window.y + __offset.y};
    DrawText(__text[i].s.c_str(), DrawP.x, DrawP.y + (i * __fontSize), __fontSize, __text[i].c);
  }
}

void  TextBox::pushText(const std::string& str, int const type, Color const c) {
  size_t i = 0;
  while (__text[i].s.length() > 0) {
    i++;
  }
  if (i < __max) {
    __text[i] = {.type = type, .s = str, .c = c};
  }
}

void  TextBox::SetFontSize(const int& size) {
  __fontSize = size;
}