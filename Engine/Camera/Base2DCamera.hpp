#ifndef  __2D_CAMERA__
# define __2D_CAMERA__

# include "../Object/Object2D.hpp"

# define BASE_CAMERA_2D "base_2Dcamera"

class Base2DCamera : public Object2D {
  public:
    Base2DCamera(const char* name);
    Base2DCamera(const std::string& name);
    ~Base2DCamera(void);
    //
    void              Default(void);
    void              Update(const Vector2& movement, const Vector2& target , \
      const float& rotation, const float& zoom);
    void              SetCamera(const Camera2D& camera);
    //
    const Camera2D&   GetCamera(void) const ;
    
    //
  protected:
    virtual void  Zero(void);
    //
    Camera2D      __camera;
    bool          __debug;
    Rectangle     __pov;  // can i make it ?
  private:
    //
};


/*
typedef struct Camera2D {
    Vector2 offset;         // Camera offset (displacement from target)
    Vector2 target;         // Camera target (rotation and zoom origin)
    float rotation;         // Camera rotation in degrees
    float zoom;             // Camera zoom (scaling), should be 1.0f by default
} Camera2D;
*/

#endif