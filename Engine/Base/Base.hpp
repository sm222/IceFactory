#ifndef  __BASE_HPP__
# define __BASE_HPP__

# include "../Type/Type.hpp"
# include "BaseInterface.hpp"
# include <array>

# define TYPE_BASE "TYPE_BASE"
# define MAX_CHILD_FT      100

typedef unsigned int   t_id;
# define PRINT_ID_AT_BUILD 1

class BaseGroup;

class Base {
  public:
    Base(const char* name);
    Base(const std::string& name);
    virtual ~Base(void);
    //
    // Get
    const char*         GetName(void) const ;
    const char*         GetType(void) const ;
    const t_id          GetId(void)   const ;
    void                PrintId(void) const ;
    static t_id         GetCurrentMaxId(void);
    // Set
    void                SetName(const char* name);
    void                SetName(const std::string& name);
    //
    void                Help(void);
    // child Ft
    static void         Hello(Base& self);
    //
    BaseInterface<MAX_CHILD_FT>   interface;
  protected:
    //
    static t_id         MakeId(void);
    virtual void        Zero(void) = 0;
    void                SetFtList(void);
    // 
    char              __name[MAX_NAME_LEN + 1];
    const char*       __type;
    const t_id        __id;
    //
    const Base*       __parent;
    //
    friend              BaseGroup; // use for 
    bool              __SetParent(const Base& parant);
    bool              __SetParantNone(void);
    //
  private:
  //
  static t_id         __totalId;
  //
};


#endif