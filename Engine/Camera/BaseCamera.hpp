
#ifndef  __BASE_CAMERA__
# define __BASE_CAMERA__

# include "../Type/Type.hpp"
# include "../Object/Object.hpp"

# define BASE_CAMERA "base_camera"

class BaseCamera : public Object {
  
  public:
    BaseCamera(void);
    BaseCamera(const char* name);
    BaseCamera(const std::string name);
    ~BaseCamera(void);
    //
    const Camera3D GetCamera(void) const;
    //void           updatePotision(Vector3 movement, Vector3 rotate, float zoom);
    void           SetPosition(const Vector3 position);
    void           SetPosition(float x, float y, float z);
    void           Update(Vector3 movement, Vector3 rotate, float zoom);

    void           SetTarget(Vector3 position);
    //Draw
    void           Draw(void);
    //
    bool           SetCanvas(const Vector2 size);
    bool           Start(void);
    bool           Stop(void);
    void           DrawFrame(const Vector2 Position, const float angle, const float scale = 1.0f);
    bool           Clear(void);
    //
    Texture2D GetFrame(void);
    //
  private:
    static void     SetActive(int status);
    static int      GetActive(void);
    //
    Camera3D        __camera;
    bool            __status;
    Image           __Iframe;
    RenderTexture2D __Tframe;
    Texture2D       __frame;
    static int      __active;
    //
    Color           __clean;
    Color           __tint;
};



#endif