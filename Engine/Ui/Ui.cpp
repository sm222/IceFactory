#include "Ui.hpp"

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
    DrawTextureRec((*__canvas).texture, r, {r.x, r.y}, WHITE);
  }
}

void BaseUi::AddChild(BaseUi* ui) {
  __child.push_back(ui);
}