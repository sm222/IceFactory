#include "DrawTexture2D.hpp"


void DrawTexture2D::Zero(void) {
  ZERO_NONE_PTR(__texture);
}

DrawTexture2D::DrawTexture2D(const char* name) : Object2D(name) {
  __type = TYPE_DRAWTEXTURE2D;
  DEBUG_P(magenta, "DrawTexture2D::");
  Zero();
}


DrawTexture2D::DrawTexture2D(const std::string& name) : Object2D(name) {
  __type = TYPE_DRAWTEXTURE2D;
  DEBUG_P(magenta, "DrawTexture2D::");
  Zero();
}

DrawTexture2D::~DrawTexture2D(void) {
  DEBUG_P(magenta, "DrawTexture2D::~");
}



void  DrawTexture2D::Info(Base &self) {
  DEBUG_P(yello, "DrawTexture2D::info %u %s", self.GetId(), self.GetName());
}


void  DrawTexture2D::Draw(int metod) const {
  (void)metod;
  //DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)
  //DrawTexturePro(__texture, __position, __rotation, __scale, __tint);
  //todo put that in the class
  const Rectangle src = (Rectangle){0, 0, (float)__texture.width, -(float)__texture.height};
  //todo ^
  const Rectangle dest = (Rectangle){__position.x, __position.y, (float)__size.x, (float)__size.y};
  DrawTexturePro(__texture, src, dest, (Vector2){0,0}, __rotation, __tint);
}


bool  DrawTexture2D::SetTexture(const Texture& t) {
  if (IsTextureValid(t)) {
    __texture = t;
    __size.x = t.width;
    __size.y = t.height;
    return true;
  }
  return false;
}

void  DrawTexture2D::RemoveTexture(void) {
  ZERO_NONE_PTR(__texture);
}

void  DrawTexture2D::SetSize(Vector2 size) {
  __size = size;
}


Vector2  DrawTexture2D::GetSize(void) {
  return __size;
}
