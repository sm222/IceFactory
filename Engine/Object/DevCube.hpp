#ifndef  __DEV_CUBE__
# define __DEV_CUBE__

# include "Object.hpp"

#define DEV_CUBE_TYPE "DevCube"

class DevCube : public Object {
  protected:
  public:
    DevCube(void);
    DevCube(const char* name);
    DevCube(const std::string& name);
    ~DevCube(void);
    //
    void Draw(int metod);
  private:
};

#endif
