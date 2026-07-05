#ifndef  __DEVCUBE3D_HPP__
# define __DEVCUBE3D_HPP__

# include "../obj3D.hpp"
# define  TYPE_DEV_CUBE_3D "TYPE_DEV_CUBE_3D"

class DevCube3D : public Obj3D {
  public:
    DevCube3D(const char* name);
    virtual ~DevCube3D(void);
    //
    virtual void Draw(int mode) const;
    virtual void SetPosition(Vector3 position);
  private:
    //
  
};

#endif