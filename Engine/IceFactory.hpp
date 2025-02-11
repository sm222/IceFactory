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
# include "Ui/Ui.hpp"

# include <raylib.h>
# include <raymath.h>

# include <string>
# include <map>
namespace Engine {
class IceFactory {
  public:
    int                initEngine(void);
    static int         GetEngineStatus(void);
    //
    bool               initRaylib(void);
    bool               closeRaylib(void);
    bool               closeEngine(void);
    static Vector2     flaotToVec2(float angle);
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
    bool               AddCameraToUpdateList(BaseCamera& camera);

    //! debug and error
    Model*             GiveWhatModel(void);
    //
    IceFactory(void);
    ~IceFactory(void);
    //
    Groups<Object*>    _mainGroups; //* root
    //
    protected:
    //! - - - - - -
    private:
      bool              IceFactoryInitRayLib(void);
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
      //
      std::map<t_ControlKeys, TYPE_KEY> __keyMapBind;
      //
      static float                      __timeScale;
      //static 
      // debug / errors tools
      Model                             __what;
      float                             __whatA;
  };
};

using Engine::IceFactory;

int  getStatusEngine(void);

#endif
