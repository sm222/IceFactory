#include "Object2D.hpp"
#include "../Type/RenderType.hpp"


void Object2D::Info(Base &self) {
  printf("Hello %d\n", self.GetId());
}


void   Object2D::Zero(void) {
  memset(&__position, 0, sizeof(__position));
  memset(&__hitBox, 0, sizeof(__hitBox));
  memset(&__renderBox, 0, sizeof(__renderBox));
}


Object2D::Object2D(const char* name) : Object(name) {
  Zero();
  __type = TYPE_OBJECT2D;
  DEBUG_P(magenta, "Object2D::");
}


Object2D::Object2D(const std::string& name) : Object(name) {
  Zero();
  __type = TYPE_OBJECT2D;
  DEBUG_P(magenta, "Object2D::");
}


Object2D::~Object2D(void) {
  DEBUG_P(magenta, "Object2D::~");
}


void   Object2D::Draw(int metod) const {
  if (metod == R_none)
    return;
  if (metod == R_hitbox || metod == R_wire) {
    DrawRectangleLinesEx(__hitBox, 1, RED);
  }
  if (metod == R_mesh || metod == R_texture) {
    DrawRectangleRec(__hitBox, GREEN);
  }
}


void  Object2D::SetPosition(Vector2& position) {
  __position = position;
}


Vector2 Object2D::GetPosition(void) const {
  return __position;
}


void   Object2D::SetHitBox(Rectangle& hitbox) {
  __hitBox = hitbox;
}


Rectangle Object2D::GetHitBox(void) const {
  return  __hitBox;
}



void   Object2D::SeRenderBox(Rectangle& renderBox) {
  __renderBox = renderBox;
}


Rectangle Object2D::GeRenderBox(void) const {
  return  __renderBox;
}