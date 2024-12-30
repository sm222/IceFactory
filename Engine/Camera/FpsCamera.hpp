
#ifndef  __FPS_CAMERA_HPP__
# define __FPS_CAMERA_HPP__

# include "../Type/Type.hpp"
# include "../Object/Object.hpp"


// Class declaration
class FpsCamera {
  public:
    FpsCamera(void);
    ~FpsCamera(void);
    //
    //
    const Camera3D getCamera(void) const;
    //
    void           updatePotision(Vector3 movement, Vector3 rotate, float zoom);
    void           setPotision(Vector3 p);
    //

  private:
    Camera3D        __cam;
    bool            __status;
    Image           __Iframe;
    RenderTexture2D __Tframe;
};

#endif // CAMERA_HPP_
