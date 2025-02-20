#ifndef  __UI_BASE_BLOCK__
# define __UI_BASE_BLOCK__

# include "../Type/Type.hpp"
# include "UiRenderZone.hpp"

class UiRenderZone;

class UiBaseBlock {
  friend class UiRenderZone;
  public:
  //
  UiBaseBlock(const char* name);
  UiBaseBlock(const std::string& name);
  UiBaseBlock(const char* name, const Vector2& position);
  UiBaseBlock(const std::string& name, const Vector2& position);
  //
    // Set

    // Get
    const Rectangle&  GetZone(void) const;
    const char*       GetName(void) const;
  //
  protected:
  //
  //
  private:
  //
  void       Zero(void);
  void       SetParant(UiRenderZone& parant);
  void       UnsetParant(void);
  //
  UiRenderZone* __parant;
  //
  Vector2       __position;
  Rectangle     __zone;
  Color         __color;
  char          __name[MAX_NAME_LEN];
  //
};

#endif