#include "MeshObject.hpp"


MeshObject::MeshObject(void) : Object() {
  __type = MESH_OBJECT_TYPE;
  Clean();
}

MeshObject::MeshObject(const char* name) : Object(name) {
  __type = MESH_OBJECT_TYPE;
  Clean();
}

MeshObject::MeshObject(const std::string& name) : Object(name) {
  __type = MESH_OBJECT_TYPE;
  Clean();
}

void MeshObject::Clean(void) {
  __errorModel = nullptr;
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