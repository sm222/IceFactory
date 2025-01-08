#include "BaseCamera.hpp"
#include <iostream>

unsigned int BaseCamera::__active = 0;
unsigned int BaseCamera::__cameraNumber = 0;

BaseCamera::BaseCamera(void) : Object(), 
__camera((Camera3D){{0, 0, 0}, {0,0,0}, {0,1,0}, 90, 0}) , __status(false) {
  __type = BASE_CAMERA;
  __CameraID = GetNewID();
}

BaseCamera::BaseCamera(const char* name) : Object(name) {
  __type = BASE_CAMERA;
  __CameraID = GetNewID();
}

BaseCamera::BaseCamera(const std::string name) : Object(name) {
  __type = BASE_CAMERA;
  __CameraID = GetNewID();
}

BaseCamera::~BaseCamera(void) {
  if (IsRenderTextureValid(__Tframe)) {
    UnloadRenderTexture(__Tframe);
  }
}

void BaseCamera::SetTarget(Vector3 position) {
  __camera.target = position;
}

void BaseCamera::SetPosition(const Vector3 position) {
  __camera.position = position;
  __position = position;
}

void BaseCamera::SetPosition(float x, float y, float z) {
  this->SetPosition({x, y, z});
}


const Camera3D BaseCamera::GetCamera(void) const {
  return __camera;
}

void BaseCamera::Draw(void) {
  return ;
}

bool BaseCamera::SetCanvas(const Vector2 size) {
  //if (IsRenderTextureValid(__Tframe)) {
  //  UnloadRenderTexture(__Tframe);
  //}

  __Tframe = LoadRenderTexture(size.x, size.y);
  return IsRenderTextureValid(__Tframe);
}

void  BaseCamera::Update(Vector3 movement, Vector3 rotate, float zoom) {
  UpdateCameraPro(&__camera, movement, rotate, zoom);
}

void BaseCamera::SetActive(unsigned int status) {
  __active = status;
}

int BaseCamera::GetActive(void) {
  return __active;
}

bool BaseCamera::Start(void) {
  if (BaseCamera::GetActive() < 1 && IsRenderTextureValid(__Tframe)) {
    BaseCamera::SetActive(1);
    BeginTextureMode(__Tframe);
    ClearBackground(BLANK);
    BeginMode3D(__camera);
    return true;
  }
  return false;
}

bool BaseCamera::Stop(void) {
  if (IsRenderTextureValid(__Tframe)) {
    EndMode3D();
    EndTextureMode();
    BaseCamera::SetActive(0);
    __Iframe = LoadImageFromTexture(__Tframe.texture);
    ImageFlipVertical(&__Iframe);
    __frame = LoadTextureFromImage(__Iframe);
    UnloadImage(__Iframe);
    return true;
  }
  return false;
}

bool BaseCamera::Clear(void) {
  if (IsTextureValid(__frame)) {
    UnloadTexture(__frame);
    return true;
  }
  return false;
}

void  BaseCamera::DrawFrame(const Vector2 Position, const float angle, const float scale) {
  DrawTextureEx(__frame, Position, angle, scale, WHITE);
}

const Texture2D BaseCamera::GetFrame(void) {
  return __frame;
}

unsigned int BaseCamera::GetNewID(void) {
  return ++__cameraNumber;
}