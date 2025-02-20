//! Object
#ifndef __OBJECT__
# define __OBJECT__

# include "../Base/Base.hpp"

# define TYPE_OBJECT "Object"


typedef enum RenderMode {
  R_Normal = 0,
  R_Wires,
  R_Points
} t_RenderMode;

class Object : public Base {
  protected:
    void        Zero(void);
    Object(void);
  public:
    Object(const char* name);
    Object(const std::string& name);
    virtual ~Object(void);
};

#endif
