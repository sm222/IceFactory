
#ifndef  __UI_RENDER_ZONE_HPP__
# define __UI_RENDER_ZONE_HPP__

# include "../Object/Object.hpp"



/*
*  Define all the default type for ui in one file
*  BaseUi is like Object and is the default block for other block to connect
* 
*/

class UiRenderZone : public Object {
  public:
    UiRenderZone(void);
    ~UiRenderZone(void);
  protected:
    //
  private:
    //
};

#endif
