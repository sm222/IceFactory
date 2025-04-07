#ifndef  __UI_BASE_BLOCK_HPP__
# define __UI_BASE_BLOCK_HPP__

# include "../Base/Base.hpp"
# include "UiRenderZone.hpp"

class UiRenderZone;

class UiBaseBlock : public Base {
  friend class UiRenderZone;
  public:
    //
    UiBaseBlock(const char* name);
    UiBaseBlock(const std::string& name);
    UiBaseBlock(const char* name, const Vector2& position);
    UiBaseBlock(const std::string& name, const Vector2& position);
    ~UiBaseBlock(void);
    //
    // Set
    void              SetZone(const Rectangle& zone);
    void              SetColor(const Color& color);
    // Get
    const Rectangle&  GetZone(void) const;
    //
  protected:
    //
    void              Zero(void);
    void             _SetParant(UiRenderZone& parant);
    void             _UnsetParant(void);
    //
    virtual void      Draw(int metod) const;
    //
    UiRenderZone* __parant;
    Vector2       __position;
    Rectangle     __zone;
    Color         __color;
    //
  private:
    //
    //
};

#endif