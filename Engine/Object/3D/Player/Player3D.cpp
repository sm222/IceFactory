# include "Player3D.hpp"

Player3D::Player3D(const char* name) : Camera_3D(name) {
  ZERO_NONE_PTR(__looking);
  ZERO_NONE_PTR(__groud);
  __speed = 0.2f;
  __type = TYPE_PLAYER_3D;
}

Player3D::~Player3D(void) {
  //
}


void Player3D::Looking(Vector2 mouse) {
  __looking.x = mouse.x * __mouseSpeed;
  __looking.y = mouse.y * __mouseSpeed;
  __looking.z = 0;
  const float camlock = 45.0f;
  if (DEG2RAD * __looking.y > camlock || DEG2RAD * __looking.y < -camlock)
    __looking.y = camlock;
}


bool     Player3D::Move(Vector3 dir) {
  __dir = dir;
  return true;
}

void Player3D::Apply(void) { 
  __Update();
}


// feel lazy for that,
// try to do it later better
//! why z and y not the same here
void Player3D::__Update(void) {
  Camera3D c = GetCamera3D();
  UpdateCameraPro(&c, __dir, __looking, 0);
  SetCamera3D(c);
}
