#include "MeshObject.hpp"


MeshObject::MeshObject(void) : Object() {
  Zero();
  __type = MESH_OBJECT_TYPE;
}

MeshObject::MeshObject(const char* name) : Object(name) {
  Zero();
  __type = MESH_OBJECT_TYPE;
}

MeshObject::MeshObject(const std::string& name) : Object(name) {
  Zero();
  __type = MESH_OBJECT_TYPE;
}

void MeshObject::Zero(void) {
  __errorModel = nullptr;
  ZERO_NONE_PTR(__model);
  ZERO_NONE_PTR(__texture);
  ZERO_NONE_PTR(__bondingBox);
}

MeshObject::~MeshObject(void) {

}

bool MeshObject::SetErrorModel(Model* ptr) {
  if (ptr == nullptr || !IsModelValid(*ptr))
    return false;
  __errorModel = ptr;
  return true;
}

void MeshObject::Draw(void) {
  const Vector3 errRotation = {0, 1 , 0};
  static float r = 0;
  if (IsModelValid(__model)) {
    printf("yes\n");
  }
  else if (__errorModel) {
    DrawModelWiresEx(*__errorModel, __position, errRotation, r, {1, 1, 1}, WHITE);
    r += 1.5f;
  }
}