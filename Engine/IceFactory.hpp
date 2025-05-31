#ifndef  __ICE_FACTORY__
# define __ICE_FACTORY__

# ifndef VERTION
#  define VERTION
#  define VERSION_MAJOR 0
#  define VERSION_MINOR 2
#  define VERSION_PATCH 0
# endif

//
# include "Type/Type.hpp"
//
# include "Object/Object.hpp"
# include "Object/MeshObject.hpp"
# include "Render/Render.hpp"
# include "Camera/BaseCamera.hpp"
# include "Import/Model/ModelManager.hpp"
# include "Import/Audio/AudioManager.hpp"
# include "Groups/BaseGroups.hpp"
# include "Room/Room.hpp"

# define  MAX_ROOM 3

# include "Render/Render.hpp"

# include <string>
# include <map>
namespace Engine {
class IceFactory {
  public:
    int                  initEngine(void);
    int                  Start(void);
    int                  Reboot(int type); // todo
    void                 Stop(void);       // todo
    bool                 TestDependency(void);
    
    bool                 closeEngine(void);
    
    static int           GetEngineStatus(void);
    static const Vector2 GetMonitorSize(void);
    static const Vector2 GetWindowSize(void);
    // Raylib
    static Vector2       flaotToVec2(float angle);
    //
    void                 SetEngineStatus(const t_EngineStatus status);
    //
    int                  UpdateEngine(void);
    //
    int                  UpdateInpus(void);
    float                GetAnalogInput(const t_Controls name) const ;
    //
    int                  UpdateEvent(void);
    void                 ForceEnvent(const t_EngineEvents envent);
    bool                 ReadEnvent(const t_EngineEvents event) const;
    //
    static float         timeScale(float in);
    static void          setTimeScale(float scale);
    //
    Vector2              GiveWindowSize(void);
    //! Update
    bool                 AddCameraToUpdateList(BaseCamera* camera);
    Room*                GetRoom(size_t index);                    //! Debug
    //! debug and error
    Model*               GiveWhatModel(void);
    //
    IceFactory(void);
    ~IceFactory(void);
    //? Engine data
    
    ModelManager        Models;
    AudioManager        Audios;
    //
    BaseGroup          _root;       //
    //
    protected:
    //! - - - - - -
    // Raylib
  private:
    bool                InitRaylib(void);
    void                SetupStart(void);
    //! room 0 is alway here as a backup
    std::array<Room*, MAX_ROOM + 1>  __roomsEngine;
    Room*                            __currentRoom;
    //
    bool                 CloseRaylib(void);
    bool                 IceFactoryInitRayLib(void);
    //! - - - - - - - - - - - - - - - - -
    //* - - - KEYBORD
    void                 SetKeyMapToKey(t_ControlKeys action, KeyboardKey key);
    void                 UpdateKeybord(void);
    void                _SetFpsControl(void);
    //
    UserSeting                        __userSeting;
    //
    static t_EngineStatus             __engineStatus;
    static bool                       __raylib;
    //
    Render                            __renderEngine;
    //
    std::vector<BaseCamera*>          __autoReSizeCamera;
    //
    Vector2                           __screenSize;
    std::string                       __gameName;
    //
    std::map<t_EngineEvents, bool>    __EngineEvent;
    //
    std::map<t_Controls, bool>        __numericMap;
    std::map<t_Controls, float>       __analogMap;
    int                               __inputSelect;
    unsigned int                      __numberGamepads;
    //
    std::map<t_ControlKeys, TYPE_KEY> __keyMapBind;
    //
    static float                      __timeScale; // defalut 1
    //static 
    // debug / errors tools
    Model                             __what;
  };
};

using Engine::IceFactory;

#endif
