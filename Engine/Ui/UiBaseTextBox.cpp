
#include "UiBaseTextBox.hpp"

void UiBaseTextBox::Zero(void) {
  ZERO_NONE_PTR(__index);
  ZERO_NONE_PTR(__mode);
}

UiBaseTextBox::UiBaseTextBox(const char* name) : UiBaseBlock(name) {
  Zero();
  __font = GetFontDefault();
}

UiBaseTextBox::UiBaseTextBox(const std::string& name) : UiBaseBlock(name.c_str()) {

}


UiBaseTextBox::~UiBaseTextBox(void) {
  //DrawTextBoxed()
}

void   UiBaseTextBox::_AddTerminal(const std::string& str) {
  if (__index == MAX_TEXT_BOX_SIZE) {
    __texts[MAX_TEXT_BOX_SIZE - 1] = str;
    return ;
  }
  __texts[__index] = str;
  __index++;
}

void   UiBaseTextBox::Add(const std::string& str) {
  if (__mode == t_terminal) {
    _AddTerminal(str);
  }
}

void  UiBaseTextBox::Clean(void) {
  std::array<std::string, MAX_TEXT_BOX_SIZE>::iterator it;
  for (it = __texts.begin(); it != __texts.end(); it++) {
    (*it).clear();
  }
  __index = 0;
}


void   UiBaseTextBox::Draw(int mode) {
  (void)mode;
  std::array<std::string, MAX_TEXT_BOX_SIZE>::iterator it;
  for (it = __texts.begin(); it != __texts.end() && !(*it).empty(); it++) {
    DrawTextBoxed((*it).c_str());
  }
}

void UiBaseTextBox::DrawTextBoxed(const char* text) {
  (void)text;
}