
#include "Room.hpp"

Room::Room(const char* name) :
Root("root"), __engineUi("EngineUi"), __cameraList("cameraList")
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
  BuildUiEngine();
}


Room::~Room(void) {
  DEBUG_P(magenta, "Room::~");
}

void Room::SetRoomType(const t_roomType& type) {
  __roomType = type;
}

const t_roomType Room::GetRoomType(void) const {
  return __roomType;
}

void   Room::BuildUiEngine(void) {
  // Todo: build terminal and main menu
}
