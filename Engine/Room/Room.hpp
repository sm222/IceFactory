
#ifndef  __ROOM__
# define __ROOM__

# include "../Type/Type.hpp"
# include "../Camera/BaseCamera.hpp"
# include "../Camera/Base2DCamera.hpp"
# include "../Groups/BaseGroups.hpp"
# include "../Object/Object3D.hpp"
//# include "../Ui/UiBaseBlock.hpp"

# define ROOM_MAX_CAMERA 10

typedef enum {
  room_noType = 0,
  room_menu,
  room_game,
  room_loading,
} t_roomType;

struct RoomRenderCamera {
  BaseCamera*    camera;
  BaseGroup*     toRender;
};


class Room {
  public:
    //
    Room (const char* name);
    ~Room(void);
    BaseGroup         root;
    //
    void              SetRoomType(const t_roomType& type);
    t_roomType        GetRoomType(void) const ;
    // Camera stuff
    bool              AddCamera(BaseCamera* camera);
    bool              RemoveCamera(const char* name);
    size_t            GetNumberOfCameras(void) const;
    BaseCamera*       GetCamera(size_t i) const;
    //bool            RemoveCamera(const t_id id); // todo
    bool              SetToRender(size_t index, BaseGroup* group, size_t cameraIndex);
    bool              UnbindToRender(size_t index);
    bool              GetRenderData(size_t index, RoomRenderCamera& data) const;
    BaseGroup*        GetRoot(void);
    // todo
    bool              Add2DCamera(const Base2DCamera* camera);
    bool              Add3DCamera(const BaseCamera* camera);
    //
    
    //
  protected:
    //
    //
  private:
    std::array<Base2DCamera*, ROOM_MAX_CAMERA + 1>      __2DCameras;  /*index is later of rendering */
    std::array<BaseCamera*  , ROOM_MAX_CAMERA + 1>      __3DCameras;  /*                            */
    std::array<BaseGroup*,    ROOM_MAX_CAMERA + 1>      __2DToRender; /*                            */
    std::array<BaseGroup*,    ROOM_MAX_CAMERA + 1>      __3DToRender; /*                            */
    //! old-> v new up
    BaseGroup                                           __cameraList;
    std::array<RoomRenderCamera, ROOM_MAX_CAMERA + 1>   __renderlist;
    //*      last one ( [ROOM_MAX_CAMERA] ) is reserve for the engine ui
    //*                           (consol, debug, fps overlay and other)
    //
    void                        BuildUiEngine(void);
    t_roomType                __roomType;
    BaseGroup                 __engineUi;
    
    //
    char                      __name[MAX_NAME_LEN + 1];
    //
};



#endif // __ROOM__
