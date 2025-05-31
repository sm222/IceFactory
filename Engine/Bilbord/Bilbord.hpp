#ifndef  __BILBORD_HPP__
# define __BILBORD_HPP__

# include "../Object/Object3D.hpp"

# define TYPE_BILBORD "BILBORD"

class Bilbord : public Object3D {
  public:
    //
    Bilbord(const char* name);
    Bilbord(const std::string& name);
    virtual ~Bilbord(void);
    //
    void      Draw(int metod) const ;
    //
  protected:
    virtual void   Zero(void);
    Camera       __pov;
    Texture      __texture;
    Rectangle    __src;
    Vector3      __up;
    Vector2      __size;
    Vector2      __origin;
    float        __rotation;
    Color        __tint;
  private:
};

#endif

//DrawBillboardPro
// (Camera camera, Texture2D texture, Rectangle source, 
// Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float 
// rotation, Color tint)
