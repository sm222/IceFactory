#ifndef  __OBJ_3D_HPP__
# define __OBJ_3D_HPP__

# include "../obj.hpp"

class Obj3D : public Obj {
  public:
    Obj3D(const char* name);
    ~Obj3D(void);
    //
    virtual void Draw(int mode) const;
    
    //
  protected:
    Vector3      __position;
    BoundingBox  __boundingBox;
    //
  private:
    //
};

#endif// __OBJ_3D_HPP__