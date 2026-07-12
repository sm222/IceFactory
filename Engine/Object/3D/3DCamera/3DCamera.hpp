#ifndef  __CAMERA_3D_HPP__
# define __CAMERA_3D_HPP__

# include "../obj3D.hpp"

# define TYPE_CAMERA_3D "CAMERA_3D"

class Camera_3D : public Obj3D {
  public:
    Camera_3D(const char* name);
    virtual ~Camera_3D(void);
    //* - - - - - - - -  - - - - - - - - - - - - -
    void     SetUp(Vector3 up);
    void     SetFov(float fov);
    void     SetTarget(Vector3 target);
    void     SetProjection(int projection);
    void     SetCamera3D(Camera3D camera);
    //
    Vector3  GetUp(void)         const ;
    float    GetFov(void)        const ;
    Vector3  GetTarget(void)     const ;
    int      GetProjection(void) const ;
    Camera3D GetCamera3D(void)   const ;
    //* - - - - - - - -  - - - - - - - - - - - - -
  protected:
    Vector3  __target;
    Vector3  __up;
    float    __fovy;
    int      __projection;
    float    __zoom;
  private:
    //
};

#endif// __CAMERA_3D_HPP__