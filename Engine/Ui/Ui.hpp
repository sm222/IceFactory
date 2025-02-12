
#ifndef  __UI_H__
# define __UI_H__

# include "../Type/Type.hpp"

/*
*  Define all the default type for ui in one file
*  BaseUi is like Object and is the default block for other block to connect
* 
*/

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
