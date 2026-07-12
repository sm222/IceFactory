#ifndef  __OBJ_3D_HPP__
# define __OBJ_3D_HPP__

# include "../obj.hpp"

# define  TYPE_OBJ_3D "TYPE_OBJ_3D"

class Obj3D : public Obj {
  public:
    Obj3D(const char* name);
    virtual ~Obj3D(void);
    //* - - - - - - - -  - - - - - - - - - - - - -
    virtual void Draw(int mode) const;
    //* - - - - - - - -  - - - - - - - - - - - - -
    virtual void SetPosition(Vector3 position);
    Vector3      GetPosition(void) const ;
    void         Tranform(Vector3 dir);
    //* - - - - - - - -  - - - - - - - - - - - - -
    void        SetBoundingBox(BoundingBox box);
    BoundingBox GetBoundingBox(void) const ;
    //
  protected:
    virtual void   Zero(void);
    Vector3      __position;
    BoundingBox  __boundingBox;
    //
  private:
    //
};

#endif// __OBJ_3D_HPP__