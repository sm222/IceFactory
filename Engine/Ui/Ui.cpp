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