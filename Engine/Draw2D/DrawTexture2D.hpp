#ifndef  __DRAWTEXTURE_HPP__
# define __DRAWTEXTURE_HPP__

#include "../Object/Object2D.hpp"

# define TYPE_DRAWTEXTURE2D "TYPE_DRAWTEXTURE2D"

class DrawTexture2D : public Object2D {
  public:
    //
    DrawTexture2D(const char* name);
    DrawTexture2D(const std::string& name);
    virtual ~DrawTexture2D(void);
    //
    static void    Info(Base& self);
    void           Draw(int metod)   const ;
    bool           SetTexture(const Texture&);
    void           RemoveTexture(void);
    void           SetSize(Vector2 size);
    Vector2        GetSize(void);
  protected:
    //
    virtual void   Zero(void);
    Texture2D    __texture;
    Vector2      __size;
    float        __rotation = 0;
    float        __scale = 1;
    Color        __tint = WHITE;
  private:
    //
};

#endif