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
  protected:
    void           Zero(void);
  //  virtual void   Draw(int mode) = 0;
  private:

};

#endif
