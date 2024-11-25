//! Object
#ifndef __OBJECT__
# define __OBJECT__

# include <string>
# include <vector>
# include "../Type/Type.hpp"

template <typename T>

class Object {
  protected:
    char  __name[99];
    char* __type;
    VEC3  __position;
  public:
    Object(const char* name);
    Object(const std::string name);
    ~Object(void);
    // get
    const char* GetName(void)     const;
    const char* GetType(void)     const;
    const VEC3  GetPosition(void) const;
    // set
    void SetPosition(const VEC3 position);
    void SetPosition(const VEC3& position);
    void SetPosition(T x, T y, T z);
    //  /
    void SetName(const char* NewName);
    void SetName(const std::string NewName);
};

#endif
