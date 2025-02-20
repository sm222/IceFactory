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
  ZERO_NONE_PTR(__rotationAngle);
  __scale = {1, 1 ,1};
  ZERO_NONE_PTR(__tint);
  
}

void  MeshObject::SetRotationAngle(const float rotation) {
  __rotationAngle = rotation;
}

void  MeshObject::SetRotationAxis(const Vector3& Axis) {
  __rotationAxis = Axis;
}

void  MeshObject::SetScale(const Vector3& scale) {
  __scale == scale;
}

float MeshObject::GetRotationAngle(void) const {
  return __rotationAngle;
}

Vector3  MeshObject::GetRotationAxis(void) const {
  return __rotationAxis;
}

Vector3  MeshObject::GetScale(void) const {
  return __scale;
}

MeshObject::~MeshObject(void) {
  if (IsModelValid(__model))
    UnloadModel(__model);
}

bool MeshObject::SetErrorModel(Model* ptr) {
  if (ptr == nullptr || !IsModelValid(*ptr))
    return false;
  __errorModel = ptr;
  return true;
}

bool MeshObject::SetModel(const char* name) {
  if (!name)
    return false;
  __model = LoadModel(name);
  if (!IsModelValid(__model))
    return false;
  return true;
}

void MeshObject::DrawModelMode(void(*ft)(Model , Vector3, Vector3, float, Vector3 , Color)) {
  ft(__model, {0,0,0}, __rotationAxis, __rotationAngle, __scale, WHITE);
}

void MeshObject::Draw(int metod) {
  const Vector3 errRotation = {0, 1 , 0};
  static float r = 0;
  if (IsModelValid(__model)) {
    switch (metod) {
      case R_Normal:
        DrawModelMode(&DrawModelEx);
        break;
      case R_Wires:
        DrawModelMode(&DrawModelWiresEx);
        break;
      case R_Points:
        DrawModelMode(&DrawModelPointsEx);
        break;
      default:
        break;
    }
  }
  else if (__errorModel) {
    DrawModelWiresEx(*__errorModel, {0,0,0}, errRotation, r, {1, 1, 1}, WHITE);
    r += 1.5f;
  }
}