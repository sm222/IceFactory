
#ifndef  __ROOM__
# define __ROOM__

# include "../Type/Type.hpp"
# include "../Camera/BaseCamera.hpp"
# include "../Camera/Base2DCamera.hpp"
# include "../Groups/BaseGroups.hpp"
# include "../Object/Object3D.hpp"
//# include "../Ui/UiBaseBlock.hpp"

# define ROOM_MAX_CAMERA 10 //! remove after

# define ROOM_MAX_LAYER  100


typedef enum {
  room_noType = 0,
  room_menu,
  room_game,
  room_loading,
} t_roomType;

typedef unsigned short RenderInstruction;
typedef std::array<RenderInstruction[3], ROOM_MAX_LAYER> Instruction;

# define R_SET_LAYER( i, dest) dest[0] = (i + 1)
# define R_SET_CAMERA(i, dest) dest[1] = (i + 1)
# define R_SET_GROUP( i, dest) dest[2] = (i + 1)

# define R_IS_VALID_LAYER( dest) dest[0] > 0 ? true : false
# define R_IS_VALID_CAMERA(dest) dest[1] > 0 ? true : false
# define R_IS_VALID_GROUP( dest) dest[2] > 0 ? true : false

# define R_GET_LAYER(dest)     dest[0] - 1
# define R_GET_CAMERA(dest)    dest[1] - 1
# define R_GET_GROUP(dest)     dest[2] - 1

struct RoomRenderCamera {
  BaseCamera*    camera;
  BaseGroup*     toRender;
};

typedef struct {
  bool            drawOnScrean;
  Rectangle       src;
  Rectangle       dest;
  Vector2         origin;
  float           rotation;
  Color           tint;
}  t_layerSetting;

typedef struct {
  bool            IsLValid;
  RenderTexture2D l;
  bool            drawOnScrean; // if false all oter parm under don't matter
  Rectangle       src;
  Rectangle       dest;
  Vector2         origin;
  float           rotation;
  Color           tint;
}  t_layer;


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
    bool              Set2DCamera(const Base2DCamera* camera, unsigned short i);
    bool              Set3DCamera(const BaseCamera* camera  , unsigned short i);
    //
    const Instruction&  GetRenderRule(void) const;
    bool                SetRenderRule(RenderInstruction rules[3], size_t i);
    
    bool                SetLayerSetting(unsigned short i, t_layerSetting& setting);
    RenderTexture2D&    GetLayer(unsigned short i);
    bool                GetLayerValid(unsigned short i) const ;
    const BaseGroup*    GetToRender(unsigned short i);
    const Base*         GetPov(unsigned short i);
    //
    unsigned short      GetLayerSize(void) const;

    int  SetToRender(BaseGroup* group, unsigned short i);
    //
    int                 InitLayer(unsigned short i, Vector2 size);
    int                 SetLayer(unsigned short i, Vector2 size);
    const t_layer&      GetLayerData(unsigned short i);
    int                 CloseLayer(unsigned short i);
    //
  protected:
    //
    //
  private:
    //todo v
    std::array<BaseGroup*,    ROOM_MAX_LAYER * 2>       __ToRender; /*                            */
    std::array<Base*,         ROOM_MAX_CAMERA + 1>      __Cameras;  /*                            */
    Instruction                                         __renderInstruction;
    std::array<t_layer, 255>                            __layers;
    //! old-> v ^ <- new
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
