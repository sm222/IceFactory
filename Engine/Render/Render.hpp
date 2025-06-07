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
    bool    SetRoom(Room* room);
    bool    RemoveRoom(void);
    int     Update(void) ;
  protected:
    //
  private:
    //
    const Camera2D   __defaultPov = {(Vector2){0,0}, (Vector2){0,0}, 0, 1};
    void               DrawRoom(const Room& room) const;
    Room*            __current;
    bool             __debug;
    //
};

#endif