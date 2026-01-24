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
# include "Import/Model/ModelManager.hpp"
# include "Import/Audio/AudioManager.hpp"
# include "Import/Texture2D/Texture2DManager.hpp"


# define  DEFAULT_CLOSE_KEY KEY_ESCAPE


# include <string>
# include <map>
namespace Engine {
class IceFactory {
  public:
    int                  InitEngine(void);
    int                  Start(void);
    int                  Reboot(int type);
    void                 Stop(void);
    bool                 CloseEngine(void);
    //
    static int           GetEngineStatus(void);
    static const Vector2 GetMonitorSize(void);
    static const Vector2 GetWindowSize(void);
    // Raylib
    static Vector2       FlaotToVec2(float angle);
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
    static float         TimeScale(float in);
    static void          SetTimeScale(float scale);
    //
    Vector2              GiveWindowSize(void);
    bool                 ResizeWindowSize(Vector2 size);
    //! Update
    //! debug and error
    Model*               GiveWhatModel(void);
    //
    IceFactory(void);
    ~IceFactory(void);
    //? Engine data
    // managers - - - - - - - -
    ModelManager        Models;
    AudioManager        Audios;
    Texture2DManager    Textures2D;
    //
    //
    protected:
    //! - - - - - -
    //* Raylib
  private:
    bool                 InitRaylib(void);
    void                 SetupStart(void);
    //
    bool                 TestDependency(void);
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
    //
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
    std::map<t_ControlKeys, t_type_key> __keyMapBind;
    //
    static float                      __timeScale; // defalut 1
    //static 
    // debug / errors tools
    Model                             __what;
  };
};

using Engine::IceFactory;

#endif
