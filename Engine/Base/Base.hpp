#ifndef  __BASE_HPP__
# define __BASE_HPP__

# include "../Type/Type.hpp"
# include "BaseInterface.hpp"

# define TYPE_BASE "TYPE_BASE"
# define MAX_CHILD_FT      100
# define MAX_INHERITANCE   10

# define DRAW_INHERITANCE(var) do {                                     \
  for (int i = 0; i < MAX_INHERITANCE; i++) { printf("%s\n", !var[i] ? "[]" : var[i]); } \
} while(0);

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
    t_id                GetId(void)   const ;
    void                PrintId(void) const ;
    static t_id         GetCurrentMaxId(void);
    //
    virtual void        Draw(int metod) const;
    // Set
    void                SetName(const char* name);
    void                SetName(const std::string& name);
    //
    void                Help(void);
    // child Ft
    static void         Hello(Base& self);
    //
    int                 GetMetod(void)   const ;
    void                SetMetod(const int metod);
    void                SetIsAlloc(bool) ;
    bool                GetIsAlloc(void) ;
    unsigned short      GetDrawType(void) const ;
    BaseInterface<MAX_CHILD_FT>   interface;
  protected:
    //
    int                     __metod;
    // 2 = 2D, 3 = 3D else garbage, set in constructor
    unsigned short          __drawType = 0; // can't be const becose f u i guess
    Base(const char* name, unsigned short drawType);
    Base(const std::string& name, unsigned short drawType);
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
    bool              __isAlloc;
    //
    bool              __AddInheritance(void);
    void              __DrawInheritance(void);
    const char*const*   GetInheritance(void);
    const char*       __inheritance[MAX_INHERITANCE];
  private:
  //
  static t_id         __totalId;
  //
};


#endif