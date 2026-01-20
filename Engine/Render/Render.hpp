#ifndef  __RENDER__
# define __RENDER__

# define REDER_MODE_NO_ROOM 1
# define REDER_DEV_DEBUG 1


class Render {
  public:
    Render(void);
    ~Render(void);
    //
    void    Draw(void) const;
    int     Update(void) ;
  protected:
    //
  private:
    //
    bool             __debug;
    //
};

#endif