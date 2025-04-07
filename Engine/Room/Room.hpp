
#ifndef  __ROOM__
# define __ROOM__

# include "../Type/Type.hpp"
# include "../Camera/BaseCamera.hpp"
# include "../Groups/BaseGroups.hpp"
//# include "../Ui/UiBaseBlock.hpp"

typedef enum {
  room_noType = 0,
  room_menu,
  room_game,
  room_loading,
} t_roomType;

class Room {
  public:
    //
    Room (const char* name);
    ~Room(void);
    BaseGroup     Root;
    //
    void              SetRoomType(const t_roomType& type);
    const t_roomType  GetRoomType(void)                    const ;
    //
  protected:
    //
    //
  private:
    BaseGroup                  __cameraList;
    //
    void                        BuildUiEngine(void);
    t_roomType                __roomType;
    BaseGroup                 __engineUi;
    
    //
    char          __name[MAX_NAME_LEN + 1];
    //
};



#endif // __ROOM__
