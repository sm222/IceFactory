//! Object
#ifndef  __OBJECT2D_HPP__
# define __OBJECT2D_HPP__

# include "Object.hpp"

# define TYPE_OBJECT2D "Object2D"

/*
*/

class Object2D : public Object {
  public:
    Object2D(const char* name);
    Object2D(const std::string& name);
    virtual ~Object2D(void);
    //
    static void Info(Base& self);
    void        Draw(int metod) const { (void)metod; };
  protected:
    void           Zero(void);
  private:
    Vector2     __position;
    Rectangle   __hitBox;

};

#endif
