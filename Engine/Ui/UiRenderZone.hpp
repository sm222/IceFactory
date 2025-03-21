
#ifndef  __UI_RENDER_ZONE_HPP__
# define __UI_RENDER_ZONE_HPP__

# include "../Type/Type.hpp"
# include "UiBaseBlock.hpp" //
# include "../Base/Base.hpp"
# include <memory>

class UiBaseBlock;

/*
*  Define all the default type for ui in one file
*  BaseUi is like Object and is the default block for other block to connect
* 
*/

class UiRenderZone : public Base {
  //
  public:
  //
    UiRenderZone(const char* name, int const& width, int const& height);
    UiRenderZone(const std::string& name, int const& width, int const& height);
    UiRenderZone(const std::string& name, const Vector2& size);
    virtual ~UiRenderZone(void);
  //
    ssize_t            Add(UiBaseBlock* block);
    //
    ssize_t            Remove(size_t index);
    ssize_t            Remove(const char* name);
    ssize_t            Remove(const std::string& name);
    //
    void               SetSize(const Vector2& size);
    void               SetZone(const Rectangle& zone);
    void               SetPosition(const Vector2& position);
  //
    void               Render(void);
    virtual void       Draw(int mode);
    //const Texture2D&   GetFrame(void) const;
  //
  protected:
  //
    void                         Zero(void);
    int                        __UpdateRender(void);
    Vector2                    __offset;
    std::vector<UiBaseBlock*>  __objects;
    RenderTexture2D            __canvas;
    Rectangle                  __zone;
    Color                      __color;
  //
  private:
    //
    static unsigned int        __SetNewId(void);
    const  unsigned int        __instance;
    static unsigned int        __instanceRunning;
    //
  //
};

#endif
