#include "MeshObject.hpp"


MeshObject::MeshObject(const char* name) : Object3D(name) {
  Zero();
  __type = MESH_OBJECT_TYPE;
}

MeshObject::MeshObject(const std::string& name) : Object3D(name) {
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
  __scale = scale;
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
}

bool MeshObject::SetErrorModel(Model* ptr) {
  if (ptr == nullptr || !IsModelValid(*ptr))
    return false;
  __errorModel = ptr;
  return true;
}

bool MeshObject::SetModel(const Model model) {
  if (IsModelValid(model)) {
    __model = model;
    DEBUG_P(green, "MeshObject::SetModel %s model was set", this->__name);
    return true;
  }
  DEBUG_P(red, "MeshObject::SetModel %s model was not set", this->__name);
  return false;
}

void MeshObject::DrawModelMode(void(*ft)(Model , Vector3, Vector3, float, Vector3 , Color))  {
  ft(__model, {0,0,0}, __rotationAxis, __rotationAngle, __scale, WHITE);
}


void MeshObject::Draw(int metod) const {
  (void)metod;
  if (IsModelValid(__model)) {
    DrawModel(this->__model, this->__position, 1, WHITE);
  }
}
