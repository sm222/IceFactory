#ifndef  __DEVFLORE_HPP__
# define __DEVFLORE_HPP__

# include "../obj3D.hpp"
# define  TYPE_DEV_FLORE_3D "TYPE_DEV_FLORE_3D"

class DevFlore : public Obj3D {
  public:
    DevFlore(const char* name);
    virtual ~DevFlore(void);
    //
    virtual void Draw(int mode) const;
  private:
    //
  
};


#endif