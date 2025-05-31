#include "DrawTexture.hpp"


void DrawTexture::Zero(void) {
  ZERO_NONE_PTR(__texture);
}

DrawTexture::DrawTexture(const char* name) : Object2D(name) {
  __type = TYPE_DRAWTEXTURE;
  DEBUG_P(magenta, "DrawTexture::");
  Zero();
}


DrawTexture::DrawTexture(const std::string& name) : Object2D(name) {
  __type = TYPE_DRAWTEXTURE;
  DEBUG_P(magenta, "DrawTexture::");
  Zero();
}

DrawTexture::~DrawTexture(void) {
  DEBUG_P(magenta, "DrawTexture::~");
}



void  DrawTexture::Info(Base &self) {
  DEBUG_P(yello, "DrawTexture::info %u %s", self.GetId(), self.GetName());
}


void  DrawTexture::Draw(int metod) const {
  if (metod) {
    DrawTextureEx(__texture, __position, __rotation, __scale, __tint);
  }
}


bool  DrawTexture::SetTexture(const Texture& t) {
  if (IsTextureValid(t)) {
    __texture = t;
    return true;
  }
  return false;
}

void  DrawTexture::RemoveTexture(void) {
  ZERO_NONE_PTR(__texture);
}