//! Object
#ifndef  __OBJECT_HPP__
# define __OBJECT_HPP__

# include "../Base/Base.hpp"

# define TYPE_OBJECT "Object"

/* 
* this class existe to regroup 2d and 3d
* if something is use by a 2d obj and a 3d one add the option here
  TODO: add Draw here
*/

class Object : public Base {
  public:
    Object(const char* name);
    Object(const std::string& name);
    virtual ~Object(void);
    //
    static void Info(Base& self);
    void        Draw(int metod) const { (void)metod; };
  protected:
    Object(const char* name, unsigned short drawType);
    Object(const std::string& name, unsigned short drawType);
    void           Zero(void);
  private:

};

#endif
