#ifndef  __DEV_CUBE__
# define __DEV_CUBE__

# include "Object3D.hpp"

#define DEV_CUBE_TYPE "DevCube"

class DevCube : public Object3D {
  protected:
  public:
    DevCube(void);
    DevCube(const char* name);
    DevCube(const std::string& name);
    ~DevCube(void);
    //
    void  SetShape(int shape)   { __shape = shape; };
    void  SetSize(Vector3 size) { __size = size;   };
    //
    void Draw(int metod) const;
  private:
    int      __shape;
    Vector3  __size;
};

#endif
