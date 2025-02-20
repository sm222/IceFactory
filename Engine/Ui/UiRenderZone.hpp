
#ifndef  __UI_RENDER_ZONE_HPP__
# define __UI_RENDER_ZONE_HPP__

# include "../Type/Type.hpp"
# include "UiBaseBlock.hpp" //

class UiBaseBlock;

/*
*  Define all the default type for ui in one file
*  BaseUi is like Object and is the default block for other block to connect
* 
*/

class UiRenderZone {
  //
  public:
  //
    UiRenderZone(const char* name, int const& width, int const& height);
    UiRenderZone(const std::string& name, int const& width, int const& height);
    UiRenderZone(const std::string& name, const Vector2& size);
    ~UiRenderZone(void);
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
    void               Draw(int mode);
    //const Texture2D&   GetFrame(void) const;
  //
  protected:
  //
  //
  private:
    void                       Zero(void);
    int                      __UpdateRender(void);
    //
    char                       __name[MAX_NAME_LEN];
    Vector2                    __offset;
    std::vector<UiBaseBlock*>  __objects;
    RenderTexture2D            __canvas;
    Rectangle                  __zone;
    Color                      __color;
  //
};

class BaseUi {
  public:
    //
    BaseUi(void);
    virtual ~BaseUi(void);
    //
    const ui&      GetData(void)     const ;
    const Color&   GetColor(void)    const ;
    const Vector2& GetOffset(void)   const ;
    const float&   GetRotation(void) const ;
    //
    void           SetData(const t_ui& ui);
    void           SetColor(const Color& color);
    void           SetOffset(const Vector2& position);
    void           SetRotation(const float& rotation);
    void           SetFirst(void);
    //
    void           AddChild(BaseUi* ui);
    //
    virtual void   Draw(int mode) const;
    //
  protected:
    //
    void           Zero(void);
    Vector2        __offset;
    ui             __data;
    Color          __color;
    float          __rotation;
    //
  private:
    //
    int                  Update(void);
    //
    int                  __main;
    RenderTexture2D*     __canvas;
    std::vector<BaseUi*> __child;
    //
};

# include <array>
# include <string>


# define MAX_TEXT_BOX_SIZE 500

class TextBox : public BaseUi {
  public:
    TextBox(void);
    ~TextBox(void) {};
    //
    void Draw(int mode) const;
    //
    void pushText(const std::string& str, int const type, Color const c);
    void SetFontSize(const int& size);
  protected:
    //
    //
  private:
    //
    const size_t                               __max;
    size_t                                     __pushIndex;
    int                                        __fontSize;
    std::array<t_dataText , MAX_TEXT_BOX_SIZE> __text;
    //
};

#endif
