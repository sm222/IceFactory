
#ifndef  __BASE_CAMERA__
# define __BASE_CAMERA__

# include "../Type/Type.hpp"
# include "../Object/Object.hpp"

# define BASE_CAMERA "base_camera"

typedef enum {
  none,
  camera_texture, // output all inside of a 2DrenderTexture
} t_camera_mode;

class BaseCamera : public Object {
  
  public:
    BaseCamera(void);
    BaseCamera(const char* name);
    BaseCamera(const std::string name);
    ~BaseCamera(void);
    //
    const Camera3D  GetCamera(void) const;
    void            SetPosition(const Vector3 position);
    void            SetPosition(float x, float y, float z);
    void            Update(Vector3 movement, Vector3 rotate, float zoom);

    void            SetTarget(Vector3 position);
    //Draw
    void            Draw(void);
    //
    bool            SetCanvas(const Vector2 size);
    bool            Start(void);
    bool            Stop(void);
    void            DrawFrame(const Vector2 Position, const float angle, const float scale = 1.0f);
    bool            Clear(void);
    bool            SetMode(const t_camera_mode mode);
    //
    const Texture2D GetFrame(void);
    const Vector2   GetFrameSize(void);
    
    //
  private:
    void                   Zero(void);
    static void            SetActive(unsigned int status);
    static unsigned int    GetNewID(void);
    static int             GetActive(void);
    //
    Camera3D                 __camera;
    bool                     __status;
    Image                    __Iframe;
    RenderTexture2D          __Tframe;
    Texture2D                __frame;
    static unsigned int      __active;
    //
    unsigned int             __CameraID;
    static unsigned int      __cameraNumber;
    t_camera_mode            __mode;
    //
    Color                    __clean;
    Color                    __tint;
};



#endif