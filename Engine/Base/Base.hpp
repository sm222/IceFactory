#ifndef  __BASE_HPP__
# define __BASE_HPP__

# include "../Type/Type.hpp"
# include "BaseInterface.hpp"
# include <array>

# define TYPE_BASE "TYPE_BASE"
# define MAX_CHILD_FT      100

class Base {
  public:
    Base(const char* name);
    Base(const std::string& name);
    virtual ~Base(void);
  //
    // Get
    const char*         GetName(void) const ;
    const char*         GetType(void) const ;
    // Set
    void                SetName(const char* name);
    void                SetName(const std::string& name);
    //
    void                Help(void);
    // child Ft
      static void       Hello(Base& self);
    //
    BaseInterface<MAX_CHILD_FT>   interface;
    protected:
  //
    virtual void        Zero(void) = 0;
    void                SetFtList(void);
    char              __name[MAX_NAME_LEN + 1];
    const char*       __type;
  //
  private:
  //
  //
};


#endif