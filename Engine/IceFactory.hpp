#ifndef  __ICE_FACTORY__
# define __ICE_FACTORY__

# ifndef VERTION
#  define VERTION 0
# endif


//
# include "Type/Type.hpp"
//
# include "Object/Object.hpp"
# include "Object/MeshObject.hpp"
# include "Groups/Groups.hpp"
# include "Render/Render.hpp"
# include "Camera/BaseCamera.hpp"
# include "Ui/UiRenderZone.hpp"
# include "Import/Model/ModelManager.hpp"

# include <raylib.h>
# include <raymath.h>

# include <string>
# include <map>
namespace Engine {
class IceFactory {
  public:
    int                  initEngine(void);
    static int           GetEngineStatus(void);
    static const Vector2 GetMonitorSize(void);
    static const Vector2 GetWindowSize(void);
    // Raylib
    bool                 InitRaylib(void);
    bool                 closeEngine(void);
    static Vector2       flaotToVec2(float angle);
    //
    void               SetEngineStatus(const t_EngineStatus status);
    //
    int                UpdateEngine(void);
    //
    int                UpdateInpus(void);
    float              GetAnalogInput(const t_Controls name) const ;
    //
    int                UpdateEvent(void);
    void               ForceEnvent(const t_EngineEvents envent);
    bool               ReadEnvent(const t_EngineEvents event) const;
    //
    static float       timeScale(float in);
    static void        setTimeScale(float scale);
    //
    Vector2            GiveWindowSize(void);
    //! Update
    //? bool               AddCameraToUpdateList(BaseCamera& camera);
    
    //! debug and error
    Model*             GiveWhatModel(void);
    //
    IceFactory(void);
    ~IceFactory(void);
    ModelManager        Models;
    //
    Groups<Object*>    _mainGroups; //* root
    //
    protected:
    //! - - - - - -
    // Raylib
    private:
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
      static float                      __timeScale;
      //static 
      // debug / errors tools
      Model                             __what;
  };
};

using Engine::IceFactory;

#endif
