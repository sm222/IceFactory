
#include "ModelManager.hpp"

ModelManager::ModelManager(void): IImport() {
  DEBUG_P(magenta, "ModelManager::");
}


ModelManager::~ModelManager(void) {
  DEBUG_P(magenta, "ModelManager::~");
}


/// @brief
/// @param name
/// @return 
const Model ModelManager::Get(const char* name) const {
  MapModel::const_iterator it = __data.find(name);
  if (it != __data.end()) {
    DEBUG_P(orange, "ModelManager::Get %s", name);
    return it->second;
  }
  Model  null;
  bzero(&null, sizeof(Model));
  return null;
}

bool  ModelManager::IsAllReadyLoad(const char* name) const {
  Model   ref;
  bzero(&ref, sizeof(Model));
  ref = Get(name);
  if (IsModelValid(ref))
    return true;
  return false;
}


/// @brief 
/// @param name 
/// @return -1 duplicate, 1 was add, 0 model not valid
int  ModelManager::Add(const char* name) {
  MapModel::const_iterator it = __data.find(name);
  if (it != __data.end()) {
    DEBUG_P(red, "ModelManager::Add %s is all ready looded", name);
    return -1;
  }
  Model m = LoadModel(name);
  if (IsModelValid(m)) {
    __data[name] = m;
    __total++;
    DEBUG_P(green, "ModelManager::Add %s was load", name);
    return 1;
  }
  DEBUG_P(red, "ModelManager::Add fail to load %s", name);
  return 0;
}


int  ModelManager::Remove(const char* name) {
  MapModel::iterator  it = __data.find(name);
  if (it == __data.end())
    return -1;
  if (IsModelValid(it->second)) {
    UnloadModel(it->second);
    __data.erase(it);
    return 1;
  }
  return 0;
}

// unloadmodel all model and reset the map to empty
void ModelManager::Clear(void) {
  MapModel::const_iterator it;
  for (it = __data.begin(); it != __data.end(); it++ ) {
    Model m = it->second;
    if (IsModelValid(m)) {
      UnloadModel(m);
    }
  }
  __data.clear();
  __total = 0;
}