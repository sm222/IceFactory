#ifndef  __OBJ_HPP__
# define __OBJ_HPP__

# include "../Base/Base.hpp"
# define TYPE_OBJ "TYPE_OBJ"

class Obj : public Base {
  public:
    Obj(const char* name);
    virtual ~Obj(void);
  protected:
    //
  private:
    //
};

#endif