
#ifndef  __BASE_CAMERA__
# define __BASE_CAMERA__

# include "../Type/Type.hpp"
# include "../Object/Object.hpp"

# define BASE_CAMERA "base_camera"

class BaseCamera : public Object {
  
  public:
    BaseCamera();
    BaseCamera(const char* name);
    BaseCamera(const std::string name);
    ~BaseCamera();
    //
    const Camera3D getCamera(void) const;
    //void           updatePotision(Vector3 movement, Vector3 rotate, float zoom);
    //void           SetPosition(const Vector3 position);
    //void           SetPosition(const Vector3& position);
    //void           SetPosition(float x, float y, float z);

    void           setTarget(Vector3 position);
    //Draw
    void           Draw(void);
  private:
    Camera3D        __camera;
    bool            __status;
    Image           __Iframe;
    RenderTexture2D __Tframe;
    static int      __active;
};



#endif