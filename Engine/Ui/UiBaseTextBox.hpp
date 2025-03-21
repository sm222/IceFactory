#ifndef  __UI_BASE_TEXT_BOX_HPP__
# define __UI_BASE_TEXT_BOX_HPP__

# include "UiBaseBlock.hpp"

# include <array>

# define MAX_TEXT_BOX_SIZE 1000

typedef enum {
  t_terminal,
  t_chat,
} t_text_box_type;

typedef struct TextBoxStr {
  std::string  str;
  Color        color;
} t_TextBoxStr;


class UiBaseTextBox : public UiBaseBlock {
  public:
    //
    UiBaseTextBox(const char* name);
    UiBaseTextBox(const std::string& name);
    ~UiBaseTextBox(void);
    //
    void         Add(const std::string& str);
    void         Draw(int mode);
    void         Clean(void);
    //
    protected:
    void        _AddTerminal(const std::string& name);
    //
    void         Zero(void);
    std::array<std::string, MAX_TEXT_BOX_SIZE>  __texts;
    size_t                                      __index;
    t_text_box_type                             __mode;
    //
    Font                                        __font;
    float                                       __fontSize;
    float                                       __spacing;
    bool                                        __wordWrap;
    int                                         __selectStart;
    int                                         __selectLength;
    Color                                       __selectBackTint;
    Color                                       __selectTint;
    Color                                       __tint;
    //
    private:
    //
    void          DrawTextBoxed(const char* text);
    //
};


#endif