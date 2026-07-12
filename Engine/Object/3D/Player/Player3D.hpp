#ifndef  __PLAYER_3D_HPP__
# define __PLAYER_3D_HPP__

# include "../3DCamera/3DCamera.hpp"

# define  TYPE_PLAYER_3D "TYPE_PLAYER_3D"


class Player3D : public Camera_3D  {
  public:
    Player3D(const char* name);
    virtual ~Player3D(void);
    //
    bool     Move(Vector3 dir);
    void     Looking(Vector2 mouse);
    //
    void     SetSpeed(float speed) { __speed = speed; };
    float    GetSpeed(void) const  { return  __speed; };
    //
    void     SetGround(float ground) { __groud = ground; };
    float    GetGround(void) const   { return   __groud; };
    void     Apply(void);
  private:
    void        __Update(void);
    float       __speed;
    float       __mouseSpeed = 50;
    Vector3     __looking;
    Vector3     __dir;
  //
    float       __groud     = 4;
    const float __fakeGroud = -1000;
};


#endif