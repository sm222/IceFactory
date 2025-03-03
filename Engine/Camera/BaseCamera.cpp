#include "BaseCamera.hpp"
#include <iostream>

unsigned int BaseCamera::__active = 0;
unsigned int BaseCamera::__cameraNumber = 0;


BaseCamera::BaseCamera(void) : Object(), 
__camera((Camera3D){{0, 0, 0}, {0,0,0}, {0,1,0}, 90, 0}) , __status(false) {
  Zero();
  __type = BASE_CAMERA;
  __CameraID = GetNewID();
  __mode = camera_texture;
}

BaseCamera::BaseCamera(const char* name) : Object(name) {
  Zero();
  __type = BASE_CAMERA;
  __CameraID = GetNewID();
  __mode = camera_texture;
}

BaseCamera::BaseCamera(const std::string& name) : Object(name) {
  Zero();
  __type = BASE_CAMERA;
  __CameraID = GetNewID();
  __mode = camera_texture;
}

bool BaseCamera::SetMode(const t_camera_mode mode) {
  if (!__active) {
    __mode = mode;
    return true;
  }
  return false;
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

// return false if camera is not set in texture mode or LoadRenderTexture fail
bool BaseCamera::SetCanvas(const Vector2 size) {
  if (__mode == camera_texture) {
    if (IsRenderTextureValid(__Tframe)) {
      UnloadRenderTexture(__Tframe);
      __Tframe = LoadRenderTexture(size.x, size.y);
    }
    return IsRenderTextureValid(__Tframe);
  }
  return false;
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
  if (BaseCamera::GetActive() < 1) {
    BaseCamera::SetActive(__CameraID);
    if (__mode == camera_texture && IsRenderTextureValid(__Tframe)) {
      BeginTextureMode(__Tframe);
      ClearBackground(BLANK);
    }
    else if (__mode == camera_texture)
      return false;
    BeginMode3D(__camera);
    return true;
  }
  return false;
}

bool BaseCamera::Stop(void) {
  EndMode3D();
  BaseCamera::SetActive(0);
  if (IsRenderTextureValid(__Tframe) && __mode == camera_texture) {
      EndTextureMode();
      __Iframe = LoadImageFromTexture(__Tframe.texture);
      ImageFlipVertical(&__Iframe);
      __frame = LoadTextureFromImage(__Iframe);
      UnloadImage(__Iframe);
  }
  return true;
}

bool BaseCamera::Clear(void) {
  if (IsTextureValid(__frame) && __mode == camera_texture) {
    UnloadTexture(__frame);
    return true;
  }
  return false;
}

const Vector2 BaseCamera::GetFrameSize(void) {
  return ((Vector2){(float)__Tframe.texture.width, (float)__Tframe.texture.height});
}


void  BaseCamera::DrawFrame(const Vector2 Position, const float angle, const float scale) {
  if (__mode == t_camera_mode::camera_texture)
    DrawTextureEx(__frame, Position, angle, scale, WHITE);
}

const Texture2D BaseCamera::GetFrame(void) {
  return __frame;
}

// future problem ?
unsigned int BaseCamera::GetNewID(void) {
  return ++__cameraNumber;
}

void BaseCamera::Zero(void) {
  ZERO_NONE_PTR(__status);
  ZERO_NONE_PTR(__Iframe);
  ZERO_NONE_PTR(__Tframe);
  ZERO_NONE_PTR(__frame);
  ZERO_NONE_PTR(__active);
  ZERO_NONE_PTR(__CameraID);
  ZERO_NONE_PTR(__mode);
  ZERO_NONE_PTR(__clean);
  ZERO_NONE_PTR(__tint);
}