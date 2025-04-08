#include "BaseCamera.hpp"
#include <iostream>

unsigned int BaseCamera::__active = 0;
unsigned int BaseCamera::__cameraNumber = 0;


BaseCamera::BaseCamera(const char* name) : Object(name), __CameraID(GetNewID()) {
  Default();
  __type = BASE_CAMERA;
  DEBUG_P(magenta, "BaseCamera::char Name:%s", name);
}

BaseCamera::BaseCamera(const std::string& name) : Object(name), __CameraID(GetNewID()) {
  Default();
  __type = BASE_CAMERA;
  DEBUG_P(magenta, "BaseCamera::char Name:%s", name.c_str());
}

bool BaseCamera::SetMode(const t_camera_mode mode) {
  if (!__active) {
    DEBUG_P(orange, "BaseCamera::SetMode %d", mode);
    __mode = mode;
    return true;
  }
  return false;
}

t_camera_mode BaseCamera::GetMode(void) const {
  return __mode;
}


BaseCamera::~BaseCamera(void) {
  if (IsRenderTextureValid(__RenderTexture)) {
    UnloadRenderTexture(__RenderTexture);
  }
  DEBUG_P(magenta, "BaseCamera::~ %s", this->GetName());
}

void BaseCamera::SetTarget(const Vector3& position) {
  __camera.target = position;
  # if (CAMEA_LOGS)
    DEBUG_P(green, "BaseCamera::SetTarget x:%f y:%f z:%f", position.x, position.y, position.z);
  # endif
}

void BaseCamera::SetPosition(const Vector3& position) {
  __camera.position = position;
  # if (CAMEA_LOGS)
  DEBUG_P(green, "BaseCamera::SetPosition x:%f y:%f z:%f", position.x, position.y, position.z);
  # endif
}

void BaseCamera::SetPosition(float x, float y, float z) {
  this->SetPosition({x, y, z});
  # if (CAMEA_LOGS)
    DEBUG_P(green, "BaseCamera::SetPosition x:%f y:%f z:%f", x, y, z);
  # endif
}

Vector3 BaseCamera::GetPosition(void) const {
  return __camera.position;
}


const Camera3D BaseCamera::GetCamera(void) const {
  DEBUG_P(orange, "BaseCamera::GetCamera %s", this->GetName());
  return __camera;
}

void BaseCamera::Draw(int metod) const {
  (void)metod;
}

// return false if camera is not set in texture mode or LoadRenderTexture fail
bool BaseCamera::SetCanvas(const Vector2& size) {
  if (__mode == camera_texture) {
    if (IsRenderTextureValid(__RenderTexture)) {
      UnloadRenderTexture(__RenderTexture);
    }
    __RenderTexture = LoadRenderTexture((int)size.x, (int)size.y);
    return IsRenderTextureValid(__RenderTexture);
  }
  return false;
}

void  BaseCamera::Update(const Vector3& movement, const Vector3& rotate, const float& zoom) {
  # if (CAMEA_LOGS && 0)
    DEBUG_P(green, "BaseCamera::Update\nmove-> x:%f y:%f z:%f\nrotate-> x:%f y:%f z:%f zoom: %f", \
    movement.x, movement.y, movement.z, rotate.x, rotate.y, rotate.z, zoom);
  # endif
  UpdateCameraPro(&__camera, movement, rotate, zoom);
}

// static
void BaseCamera::SetActive(unsigned int status) {
  __active = status;
}

// static
unsigned int BaseCamera::GetActive(void) {
  return __active;
}

int BaseCamera::Start(void) {
  if (BaseCamera::GetActive() < 1) {
    BaseCamera::SetActive(__CameraID);
    if (__mode == camera_texture && IsRenderTextureValid(__RenderTexture)) {
      BeginTextureMode(__RenderTexture);
      ClearBackground(BLANK);
    }
    else if (__mode == camera_texture)
      return camera_texture;
    BeginMode3D(__camera);
    return camera_run;
  }
  return camera_blank;
}

bool BaseCamera::Stop(void) {
  if (BaseCamera::GetActive() == __CameraID) {
    EndMode3D();
    BaseCamera::SetActive(0);
    if (IsRenderTextureValid(__RenderTexture) && __mode == camera_texture) {
      EndTextureMode();
    }
    return true;
  }
  return false;
}

bool BaseCamera::Clear(void) {
  return true;
}

const Vector2 BaseCamera::GetFrameSize(void) {
  return ((Vector2){(float)__RenderTexture.texture.width, (float)__RenderTexture.texture.height});
}


void  BaseCamera::DrawFrame(const Vector2& Position) {
  if (__mode == t_camera_mode::camera_texture)
    DrawTextureRec(__RenderTexture.texture, {Position.x, Position.y, (float)__RenderTexture.texture.width, -(float)__RenderTexture.texture.height}, Position, WHITE);
}

const Texture2D BaseCamera::GetFrame(void) {
  return __RenderTexture.texture;
}

void  BaseCamera::SetColors(Color clean, Color tint) {
  __clean = clean;
  __tint = tint;
}

Color  BaseCamera::GetCleanColor(void) const {
  return __clean;
}

Color  BaseCamera::GetTintColor(void) const {
  return __tint;
}

//! future problem ? //? switch for t_id ?
unsigned int BaseCamera::GetNewID(void) {
  return ++__cameraNumber;
}

void BaseCamera::Default(void) {
  Zero();
  __clean = BLACK;
  __tint = WHITE;
  __mode = camera_texture;
  __camera.up = {0, 1, 0};
  __camera.fovy = 90;
}

void BaseCamera::Zero(void) {
  ZERO_NONE_PTR(__status);
  ZERO_NONE_PTR(__RenderTexture);
  ZERO_NONE_PTR(__active);
  ZERO_NONE_PTR(__CameraID);
  ZERO_NONE_PTR(__mode);
  ZERO_NONE_PTR(__camera);
}