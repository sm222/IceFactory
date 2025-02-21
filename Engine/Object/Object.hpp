//! Object
#ifndef  __OBJECT_HPP__
# define __OBJECT_HPP__

# include "../Base/Base.hpp"

# define TYPE_OBJECT "Object"


class Object : public Base {
  public:
    Object(const char* name);
    Object(const std::string& name);
    virtual ~Object(void);
  protected:
    void   Zero(void);
  private:

};

#endif
