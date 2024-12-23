
#ifndef  __CAMERAGAME_HPP__
# define __CAMERAGAME_HPP__

# include "../Type/Type.hpp"


// Class declaration
class CameraGame {
  public:
    CameraGame(void);
    ~CameraGame(void);
    //
    void       setBox(void);
    bool       lookUp(float ammont);
    bool       lookDown(float ammont);
    void       lookLeft(float ammont);
    void       lookRight(float ammont);
    Camera3D   cam;
    bool       status;
    Vector3    offSet;
    t_box      box;

  private:
    float    __dir;
    Vector2  __pro;
    float    __pitch;
    float    __maxPitch;
};

#endif // CAMERA_HPP_
