
#ifndef  __BASE_CAMERA__
# define __BASE_CAMERA__

# include "../Type/Type.hpp"
# include "../Object/Object.hpp"

# define BASE_CAMERA "base_camera"

# define CAMEA_LOGS 1

enum {
  camera_blank = 3,
  camera_run = 2,
};

typedef enum {
  none,
  camera_texture,      // output all inside of a 2DrenderTexture
  camera_texture_keep, // to use on a bilbord or on a model
} t_camera_mode;

class BaseCamera : public Object {
  public:
    BaseCamera(const char* name);
    BaseCamera(const std::string& name);
    ~BaseCamera(void);
    //
    const Camera3D         GetCamera(void) const;
    void                   SetPosition(const Vector3& position);
    void                   SetPosition(float x, float y, float z);
    void                   Update(const Vector3& movement, const Vector3& rotate, const float& zoom);
    void                   Default(void);
    //
    Vector3                GetPosition(void)     const ;
    //
    Vector2                GetDrawPosition(void) const ;
    void                   SetDrawPosition(const Vector2& position);
    //
    Vector2                GetDrawSize(void)     const ;
    void                   SetDrawSize(const Vector2& size);
    //
    float                  GetRotation(void)     const ;
    void                   SetRotation(const float rotation);
    //
    void                   SetTarget(const Vector3& position);
    //Draw
    void                   Draw(int metod)       const;
    //
    bool                   SetCanvas(const Vector2& size);
    int                    Start(void);
    bool                   Stop(void);
    void                   DrawFrameAuto(void)                                         const ;
    void                   DrawFrame(const Vector2& position)                          const ;
    void                   DrawFrameSize(const Vector2& Position, const Vector2& size) const ;
    bool                   Clear(void);
    bool                   SetMode(const t_camera_mode mode);
    t_camera_mode          GetMode(void)       const ;
    //
    const Texture2D        GetFrame(void);
    const Vector2          GetFrameSize(void);
    //
    void                   SetColors(Color clean, Color tint);
    Color                  GetCleanColor(void) const ;
    Color                  GetTintColor(void)  const ;
    //
    Ray                    GetRay(size_t i)    const ;
    bool                   GetDebug(void)      const ;
    void                   SetDebug(bool);
    //
  protected:
    void                   Zero(void);
    static void            SetActive(unsigned int status);
    static unsigned int    GetNewID(void);
    static unsigned int    GetActive(void);
    //
    Camera3D                 __camera;
    bool                     __status;
    RenderTexture2D          __RenderTexture;
    static unsigned int      __active;
    //
    Vector2                  __drawPosition;
    Vector2                  __drawSize;
    float                    __rotation = 0;
    //
    unsigned int             __CameraID;
    static unsigned int      __cameraNumber;
    t_camera_mode            __mode;
    //
    Color                    __clean;
    Color                    __tint;
    // debug
    bool                     __debug = false;
    Ray                      __rays[4];
  private:
    //
};



#endif