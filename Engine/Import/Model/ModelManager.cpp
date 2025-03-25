
#include "ModelManager.hpp"

ModelManager::ModelManager(void): IImport() {
  C_DEBUG("ModelManager Start");
}


ModelManager::~ModelManager(void) {
  C_DEBUG("ModelManager end");
}


/// @brief throw
/// @param name 
/// @return 
const Model& ModelManager::Get(const char* name) const {
  C_DEBUG("ModelManager::Get");
  MapModel::const_iterator it = __data.find(name);
  if (it != __data.end())
    return it->second;
  throw std::runtime_error("missing model");
}

/// @brief 
/// @param name 
/// @return -1 duplicate, 1 was add, 0 model not valid
int  ModelManager::Add(const char* name) {
  C_DEBUG("ModelManager::Add");
  MapModel::const_iterator it = __data.find(name);
  if (it != __data.end()) {
    return -1;
  }
  Model m = LoadModel(name);
  if (IsModelValid(m)) {
    __data[name] = m;
    __total++;
    return 1;
  }
  return 0;
}


int  ModelManager::Remove(const char* name) {
  C_DEBUG("ModelManager::Remove");
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
  C_DEBUG("ModelManager::Clear");
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