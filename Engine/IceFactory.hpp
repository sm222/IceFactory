#ifndef  __ICE_FACTORY__
# define __ICE_FACTORY__

# ifndef VERTION
#  define VERTION
#  define VERSION_MAJOR 0
#  define VERSION_MINOR 3
#  define VERSION_PATCH 0
# endif

//
# include "Type/Type.hpp"
# include "Group/Group.hpp"
//
# include "Import/Model/ModelManager.hpp"
# include "Import/Audio/AudioManager.hpp"
# include "Import/Texture2D/Texture2DManager.hpp"

# include "Render/Render.hpp"


# define  DEFAULT_CLOSE_KEY KEY_ESCAPE


# include <string>
# include <map>
namespace Engine {
class IceFactory {
  public:
    // build stop
    IceFactory(void);
    ~IceFactory(void);
    int                  InitEngine(void);
    int                  Start(void);
    int                  Reboot(int type);
    void                 Stop(void);
    bool                 CloseEngine(void);
    // STATUS
    static int           GetEngineStatus(void);
    void                 SetEngineStatus(const t_EngineStatus status);
    // WINDOW
    static const Vector2 GetMonitorSize(void);
    static const Vector2 GetWindowSize(void);
    Vector2              GiveWindowSize(void);
    bool                 ResizeWindowSize(Vector2 size);
    // RAYLIB
    // MATH
    static Vector2       FlaotToVec2(float angle);
    // TIMER
    
    // UPDATE
    int                  UpdateEngine(void);
    int                  UpdateInpus(void);
    int                  UpdateEvent(void);
    void                 ForceEnvent(const t_EngineEvents envent);
    // INPUTS
    float                GetAnalogInput(const t_Controls name) const ;
    bool                 ReadEnvent(const t_EngineEvents event) const;
    // TIME
    static float         TimeScale(float in);
    static void          SetTimeScale(float scale);
    // ERROR
    Model*               GiveWhatModel(void);
    // MANAGERS
    ModelManager        Models;
    AudioManager        Audios;
    Texture2DManager    Textures2D;
    //todo:             text manger ? dose font too ?
    ///!Manager
    //todo:             gamepad
    //todo:             keybord
    //
    protected:
    //! - - - - - -
    //* Raylib
  private:
    // INIT
    bool                 InitRaylib(void);
    void                 SetupStart(void);
    bool                 TestDependency(void);
    bool                 IceFactoryInitRayLib(void);
    // END
    bool                 CloseRaylib(void);
    //! - - - - - - - - - - - - - - - - -
    // KEYBORD
    void                 SetKeyMapToKey(t_ControlKeys action, KeyboardKey key);
    void                 UpdateKeybord(void);
    void                _SetFpsControl(void);
    // USER
    UserSeting                          __userSeting;
    // ENGINE
    static t_EngineStatus               __engineStatus;
    static bool                         __raylib;
    // RENDER
    Render                              __render;
    Vector2                             __screenSize;
    std::string                         __gameName;
    //
    std::map<t_EngineEvents, bool>      __EngineEvent;
    //
    std::map<t_Controls, bool>          __numericMap;
    std::map<t_Controls, float>         __analogMap;
    int                                 __inputSelect;
    unsigned int                        __numberGamepads;
    //
    std::map<t_ControlKeys, t_type_key> __keyMapBind;
    //
    static float                        __timeScale; // defalut 1
    //static 
    // debug / errors tools
    Model                               __what;
    //Group
    Group                               __root;
  };
};

using Engine::IceFactory;

#endif
