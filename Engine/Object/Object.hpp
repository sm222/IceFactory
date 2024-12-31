//! Object
#ifndef __OBJECT__
# define __OBJECT__

# include <string>
# include <vector>
# include "../Type/Type.hpp"
# include <string.h>
# include <strings.h>

#define OBJECT_TYPE "Object"

class Object {
  protected:
    char        __name[99];
    const char* __type;
    Vector3     __position;
  public:
    Object(void);
    Object(const char* name);
    Object(const std::string name);
    static void  CallDraw(Object* self);
    virtual void Draw(void);
    virtual ~Object(void);
    // get
    const char*    GetName(void)     const;
    const char*    GetType(void)     const;
    const Vector3  GetPosition(void) const;
    // set
    virtual void SetPosition(const Vector3 position);
    virtual void SetPosition(const Vector3& position);
    virtual void SetPosition(float x, float y, float z);
    //  /
    void SetName(const char* NewName);
    void SetName(const std::string NewName);
};

#endif
