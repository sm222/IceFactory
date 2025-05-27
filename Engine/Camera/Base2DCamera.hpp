#ifndef  __2D_CAMERA__
# define __2D_CAMERA__

# include "../Object/Object2D.hpp"

# define BASE_CAMERA_2D "base_2Dcamera"

class Base2DCamera : public Object2D {
  public:
    Base2DCamera(const char* name);
    Base2DCamera(const std::string& name);
    virtual ~Base2DCamera(void);
    //
  protected:
    //
    Camera2D      __camera;
  private:
    //
};


#endif