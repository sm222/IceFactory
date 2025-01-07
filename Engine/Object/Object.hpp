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
    char        __name[100];
    const char* __type;
    Vector3     __position;
  public:
    Object(void);
    Object(const char* name);
    Object(const std::string name);
    virtual ~Object(void);
    //
    virtual void Draw(void);             // must be public
    static void  CallDraw(Object* self); // this one too
    // get
    const char*    GetName(void)     const;
    const char*    GetType(void)     const;
    const Vector3  GetPosition(void) const;
    // set
    virtual void SetPosition(const Vector3 position);
    virtual void SetPosition(float x, float y, float z);
    //
    virtual void MoveTowards(const Vector3 direction, const float speed = 1.0f);
    //  /
    void SetName(const char* NewName);
    void SetName(const std::string NewName);
};

#endif
