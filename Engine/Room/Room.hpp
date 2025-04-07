
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
    BaseGroup         root;
    //
    void              SetRoomType(const t_roomType& type);
    const t_roomType  GetRoomType(void)                    const ;
    // Camera stuff
    bool              AddCamera(BaseCamera* camera);
    bool              RemoveCamera(const char* name);
    size_t            GetNumberOfCameras(void) const;
    const BaseCamera* GetCamera(size_t i) const;
    //bool            RemoveCamera(const t_id id); // todo
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
