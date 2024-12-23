#include "Camera.hpp"
#include <iostream>

CameraGame::CameraGame(void): cam((Camera3D){{0, 0, 0}, {0,0,0}, {0,1,0}, 90, 0}) 
, status(false), offSet((Vector3){0,0,0}), __dir(0), __pro({0,0}), __pitch(0), __maxPitch(100)
{

}

Vector2 rotate(float angle) {
  return {sin(angle * DEG2RAD), cos(angle * DEG2RAD)};
}

CameraGame::~CameraGame(void) {}

void CameraGame::setBox(void) {
  __pro = rotate(__dir);
  cam.target.x = cam.position.x + (__pro.x);
  cam.target.z = cam.position.z + (__pro.y);
  cam.target.y = __pitch;
}

bool CameraGame::lookUp(float ammont) {
  __pitch -= ammont;
  return true;
}

bool CameraGame::lookDown(float ammont) {
  __pitch += ammont;
  return true;
}

void CameraGame::lookLeft(float ammont) {
  __dir += ammont;
}

void CameraGame::lookRight(float ammont) {
  __dir -= ammont;
}