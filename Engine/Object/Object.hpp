//! Object
#ifndef __OBJECT__
# define __OBJECT__

# include <string>
# include <vector>
# include "../Type/Type.hpp"
# include <string.h>
# include <strings.h>


class Object {
  protected:
    char    __name[99];
    char*   __type;
    Vector3 __position;
  public:
    Object(const char* name);
    Object(const std::string name);
    ~Object(void);
    // get
    const char*    GetName(void)     const;
    const char*    GetType(void)     const;
    const Vector3  GetPosition(void) const;
    // set
    void SetPosition(const Vector3 position);
    void SetPosition(const Vector3& position);
    void SetPosition(float x, float y, float z);
    //  /
    void SetName(const char* NewName);
    void SetName(const std::string NewName);
};

#endif
