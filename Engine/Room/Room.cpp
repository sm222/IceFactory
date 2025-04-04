
#include "Room.hpp"

Room::Room(const char* name) {
  DEBUG(PROJECT_ROOT, magenta, "Room::name");
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
}



Room::~Room(void) {
  DEBUG(PROJECT_ROOT, magenta, "Room::~");
}

