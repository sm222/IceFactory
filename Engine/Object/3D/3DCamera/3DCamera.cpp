#include "3DCamera.hpp"

Camera_3D::Camera_3D(const char* name) : Obj3D(name) {
  ZERO_NONE_PTR(__target);
  __up = {0.0f, 1.0f, 0.0f};
  __fovy = 90;
  __projection = CAMERA_PERSPECTIVE;
  __type = TYPE_CAMERA_3D;
}

Camera_3D::~Camera_3D (void) {
  //
}

//*********
//*
//*  Set
//*
//*********


void Camera_3D::SetUp(Vector3 up) {
  __up = up;
}

void Camera_3D::SetFov(float fov) {
  __fovy = fov;
}

void Camera_3D::SetTarget(Vector3 target) {
  __target = target;
}

void Camera_3D::SetProjection(int projection) {
  __projection = projection;
}

void Camera_3D::SetCamera3D(Camera3D camera) {
  __position = camera.position;
  __target = camera.target;
  __up = camera.up;
  __fovy = camera.fovy;
  __projection  = camera.projection;
}

//*********
//*
//*  Get
//*
//*********

Vector3  Camera_3D::GetUp(void)         const {
  return __up;
}

float    Camera_3D::GetFov(void)        const {
  return __fovy;
}

Vector3  Camera_3D::GetTarget(void)     const {
  return __target;
}

int      Camera_3D::GetProjection(void) const {
  return __projection;
}


Camera3D Camera_3D::GetCamera3D(void) const {
  return {
    __position,
    __target,
    __up,
    __fovy,
    __projection
  };
}
