
#ifndef  __CAMERAGAME_HPP__
# define __CAMERAGAME_HPP__

# include "../Type/Type.hpp"


// Class declaration
class CameraGame {
  public:
    CameraGame(void);
    ~CameraGame(void);
    //
    //
    const Camera3D getCamera(void) const;
    //
    void           updatePotision(Vector3 movement, Vector3 rotate, float zoom);
    void           setPotision(Vector3 p);
    //

  private:
    Camera3D   __cam;
    bool       __status;
};

#endif // CAMERA_HPP_
