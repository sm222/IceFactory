#include "Texture2DManager.hpp"

Texture2DManager::Texture2DManager(void): IImport() {
  DEBUG_P(magenta, "Texture2DManager::");
}


Texture2DManager::~Texture2DManager(void) {
  DEBUG_P(magenta, "Texture2DManager::~");
}


/// @brief
/// @param name
/// @return 
const Texture2D Texture2DManager::Get(const char* name) const {
  MapTexture2D::const_iterator it = __data.find(name);
  if (it != __data.end()) {
    DEBUG_P(orange, "Texture2DManager::Get %s", name);
    return it->second;
  }
  Texture2D  null;
  ZERO_NONE_PTR(null);
  return null;
}

bool  Texture2DManager::IsAllReadyLoad(const char* name) const {
  Texture2D   ref;
  ZERO_NONE_PTR(ref);
  ref = Get(name);
  if (IsTextureValid(ref))
    return true;
  return false;
}


/// @brief 
/// @param name 
/// @return -1 duplicate, 1 was add, 0 Texture2D not valid
int  Texture2DManager::Add(const char* name) {
  MapTexture2D::const_iterator it = __data.find(name);
  if (it != __data.end()) {
    DEBUG_P(red, "Texture2DManager::Add %s is already loaded", name);
    return -1;
  }
  Texture2D t = LoadTexture(name);
  if (IsTextureValid(t)) {
    __data[name] = t;
    __total++;
    DEBUG_P(green, "Texture2DManager::Add %s was loaded", name);
    return 1;
  }
  DEBUG_P(red, "Texture2DManager::Add fail to load %s", name);
  return 0;
}


int  Texture2DManager::Remove(const char* name) {
  MapTexture2D::iterator  it = __data.find(name);
  if (it == __data.end())
    return -1;
  if (IsTextureValid(it->second)) {
    UnloadTexture(it->second);
    __data.erase(it);
    return 1;
  }
  return 0;
}

// unloadmodel all model and reset the map to empty
void Texture2DManager::Clear(void) {
  MapTexture2D::const_iterator it;
  for (it = __data.begin(); it != __data.end(); it++ ) {
    Texture2D t = it->second;
    if (IsTextureValid(t)) {
      UnloadTexture(t);
    }
  }
  __data.clear();
  __total = 0;
}