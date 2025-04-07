#ifndef __RENDER__
# define __RENDER__

# include "../Groups/BaseGroups.hpp"
# include "../Camera/BaseCamera.hpp"
# include "../Room/Room.hpp"

# define REDER_MODE_NO_ROOM 1
# define REDER_DEV_DEBUG 1

class Render {
  public:
    Render(void);
    ~Render(void);
    //
    void    Draw(void) const;
    bool    SetRoom(const Room* room);
    bool    RemoveRoom(void);
  protected:
    //
  private:
    //
    void               DrawRoom(const Room& room) const;
    const Room*      __current;
    //
};



#endif