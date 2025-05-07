#include "UiBaseBlock.hpp"

//# define RAYGUI_IMPLEMENTATION
# include "../include/raygui/src/raygui.h"

void UiBaseBlock::Zero(void) {
  //ZERO_NONE_PTR(__zone);
}

UiBaseBlock::UiBaseBlock(const char* name) : Base(name), __color(WHITE) {
  Zero();
}

UiBaseBlock::UiBaseBlock(const std::string& name) : Base(name) {
}

UiBaseBlock::UiBaseBlock(const char* name, const Vector2& position) : UiBaseBlock(name) {
  __position = position;
}

UiBaseBlock::UiBaseBlock(const std::string& name, const Vector2& position) : UiBaseBlock(name.c_str(), position) {
  __position = position;
}

UiBaseBlock::~UiBaseBlock(void) {
  
}

const Rectangle& UiBaseBlock::GetZone(void) const {
  return __zone;
}

void UiBaseBlock::SetZone(const Rectangle& zone) {
  __zone = zone;
}

void UiBaseBlock::SetColor(const Color& color) {
  __color = color;
}

void UiBaseBlock::_SetParant(UiRenderZone& parant) {
  __parant = &parant;
}

void UiBaseBlock::_UnsetParant(void) {
  __parant = nullptr;
}

void  UiBaseBlock::Draw(int metod) const {
  if (metod == 0)
    DrawRectangleRec(__zone, __color);
  else if (metod > 0)
    DrawRectangleLinesEx(__zone, metod, __color);
}