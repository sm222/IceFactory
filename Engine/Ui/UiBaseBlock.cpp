#include "UiBaseBlock.hpp"

void UiBaseBlock::Zero(void) {
  ZERO_NONE_PTR(__zone);
}

UiBaseBlock::UiBaseBlock(const char* name) {
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

UiBaseBlock::UiBaseBlock(const std::string& name) {
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

UiBaseBlock::UiBaseBlock(const char* name, const Vector2& position) : UiBaseBlock(name) {
  __position = position;
}

UiBaseBlock::UiBaseBlock(const std::string& name, const Vector2& position) : UiBaseBlock(name) {
  __position = position;

}

const Rectangle& UiBaseBlock::GetZone(void) const {
  return __zone;
}

const char* UiBaseBlock::GetName(void) const {
  return __name;
}


void UiBaseBlock::SetParant(UiRenderZone& parant) {
  __parant = &parant;
}

void UiBaseBlock::UnsetParant(void) {
  __parant = nullptr;
}