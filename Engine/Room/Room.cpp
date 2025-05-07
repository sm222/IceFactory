
#include "Room.hpp"

Room::Room(const char* name) :
root("root"),  __cameraList("cameraList"), __engineUi("EngineUi")
{
  DEBUG_P(magenta, "Room::name");
  if (name) {
    const size_t len = strlen(name);
    if (len < MAX_NAME_LEN) {
      memcpy(__name, name, len);
    }
    else {
      memcpy(__name, name, MAX_NAME_LEN);
      __name[MAX_NAME_LEN] = 0;
    }
  }
  else {
    memcpy(__name, "no_name", 8);
  }
  __roomType = room_noType;
  for (size_t i = 0; i < ROOM_MAX_CAMERA + 1; i++) {
    __renderlist[i].camera = nullptr;
    __renderlist[i].toRender = nullptr;
  }
  BuildUiEngine();
}


Room::~Room(void) {
  root.DeAllocAll();
  DEBUG_P(magenta, "Room::~");
}

void Room::SetRoomType(const t_roomType& type) {
  __roomType = type;
}

t_roomType Room::GetRoomType(void) const {
  return __roomType;
}

bool Room::AddCamera(BaseCamera* camera) {
  if (!camera || strcmp(camera->GetType(), BASE_CAMERA) != 0) {
    DEBUG_P(red, "Room::AddCamera no camera or invalid");
    return false;
  }
  if (GetNumberOfCameras() >= ROOM_MAX_CAMERA) {
    DEBUG_P(red, "too many camera: max set by engine is %d", ROOM_MAX_CAMERA);
    return false;
  }
  __cameraList.Add(camera);
  return true;
}

bool Room::RemoveCamera(const char* name) {
  return __cameraList.Remove(name);
}

size_t  Room::GetNumberOfCameras(void) const {
  return __cameraList.Size();
}

BaseCamera* Room::GetCamera(size_t i) const {
  const size_t n = GetNumberOfCameras();
  if (n <= i) {
    DEBUG_P(red, "Room::GetCamera out of bound i%u nbr Camera %u", i, n);
    return nullptr;
  }
  Base* ptr = __cameraList.GetByIndex(i);
  return (BaseCamera*)ptr;
}

bool  Room::SetToRender(size_t index, BaseGroup* group, size_t cameraIndex) {
  if (!group) {
    DEBUG_P(red, "Room::SetToRender no groups");
    return false;
  }
  if (index >= ROOM_MAX_CAMERA) {
    DEBUG_P(red, "Room::SetToRender bad index, max value is %d", ROOM_MAX_CAMERA);
    return false;
  }
  BaseCamera* camera = GetCamera(cameraIndex);
  if (!camera) {
    DEBUG_P(red, "HERE");
    return false;
  }
  DEBUG_P(green, "Room::SetToRender set at %u", index);
  __renderlist[index].camera = camera;
  __renderlist[index].toRender = group;
  return true;
}

bool Room::UnbindToRender(size_t index) {
  if (index >= ROOM_MAX_CAMERA) {
    DEBUG_P(red, "Room::UnbindToRender out of boud, max is %u, index was %u", ROOM_MAX_CAMERA , index);
    return false;
  }
  __renderlist[index].camera   = nullptr;
  __renderlist[index].toRender = nullptr;
  return true;
}

bool  Room::GetRenderData(size_t index, RoomRenderCamera& data) const {
  data.camera = nullptr;
  data.toRender = nullptr;
  if (index >= ROOM_MAX_CAMERA) {
    DEBUG_P(red, "Room::GetRenderData out of boud, max is %u, index was %u", ROOM_MAX_CAMERA , index);
    return false;
  }
  data = __renderlist[index];
  return true;
}

BaseGroup*  Room::GetRoot(void) {
  return &root;
}


void   Room::BuildUiEngine(void) {
  // Todo: build terminal and main menu
}
