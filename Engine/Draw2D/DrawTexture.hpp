#ifndef  __DRAWTEXTURE_HPP__
# define __DRAWTEXTURE_HPP__

#include "../Object/Object2D.hpp"

# define TYPE_DRAWTEXTURE "TYPE_DRAWTEXTURE"

class DrawTexture : public Object2D {
  public:
    //
    DrawTexture(const char* name);
    DrawTexture(const std::string& name);
    virtual ~DrawTexture(void);
    //
    static void    Info(Base& self);
    void           Draw(int metod)   const ;
    bool           SetTexture(const Texture&);
    void           RemoveTexture(void);
  protected:
    //
    virtual void   Zero(void);
    Texture2D    __texture;
    float        __rotation = 0;
    float        __scale = 1;
    Color        __tint;
  private:
    //
};

#endif