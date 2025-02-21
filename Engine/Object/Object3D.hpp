#ifndef  __OBJECT_3D_HPP__
# define __OBJECT_3D_HPP__

# include "Object.hpp"

# define TYPE_OBJECT3D "Object3D"

class Object3D : Object {
  public:
    //
    Object3D(const char* name);
    Object3D(const std::string& name);
    ~Object3D(void);
    //
    const Vector3&  GetPosition(void) const ;
    const Vector3&  GetRotation(void) const ;
      //
    void            SetPosition(const Vector3& position);
    void            SetRotation(const Vector3& rotation);
    //
  protected:
  virtual void   Zero(void);
    Vector3    __position;
    Vector3    __rotation;
  private:
};

#endif