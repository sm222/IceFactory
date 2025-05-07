#ifndef  __BASE_HPP__
# define __BASE_HPP__

# include "../Type/Type.hpp"
# include "BaseInterface.hpp"

# define TYPE_BASE "TYPE_BASE"
# define MAX_CHILD_FT      100

typedef unsigned int   t_id;
# define PRINT_ID_AT_BUILD 1

enum {
  draw_invalid = 0 ,
  draw_solid   = 0b00000001,
  draw_mesh    = 0b00000010,
  draw_points  = 0b00000100,
  draw_hitbox  = 0b00001000,
  draw_texture = 0b00010000,
};

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
    void                SetIsAlloc(bool);
    bool                GetIsAlloc(void);
    BaseInterface<MAX_CHILD_FT>   interface;
  protected:
    //
    int               __metod;
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
  private:
  //
  static t_id         __totalId;
  //
};


#endif