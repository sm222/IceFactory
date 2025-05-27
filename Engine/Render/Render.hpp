#ifndef  __RENDER__
# define __RENDER__

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
    RenderTexture2D  __textureList[(ROOM_MAX_CAMERA -1) * 2];
    const Room*      __current;
    bool             __debug;
    //
};

#endif