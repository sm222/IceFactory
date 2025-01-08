#ifndef  __ICE_FACTORY__
# define __ICE_FACTORY__

# ifndef VERTION
#  define VERTION 0
# endif

//
# include "Type/Type.hpp"
//
# include "Object/Object.hpp"
# include "Groups/Groups.hpp"
# include "Render/Render.hpp"
# include "Camera/FpsCamera.hpp"

# include <raylib.h>
# include <raymath.h>
# include <string>
# include <map>
namespace Engine {
class IceFactory {
  public:
    int                initEngine(void);
    static int         GetEngineStatus(void);
    bool               initRaylib(void);
    bool               closeRaylib(void);
    bool               closeEngine(void);
    static Vector2     flaotToVec2(float angle);
    //
    int                UpdateEngine(void);
    //
    int                UpdateInpus(void);
    float              getAnalogInput(const t_Controls name);
    //
    int                UpdateEvent(void);
    void               ForceEnvent(const t_EngineEvents envent);
    bool               ReadEnvent(const t_EngineEvents event);
    //
    static float       timeScale(float in);
    static void        setTimeScale(float scale);
    //
    Vector2            GiveWindowSize(void);

    //
    IceFactory(void);
    ~IceFactory(void);
    //
    Groups<Object*>    _mainGroups;
    //
    protected:
    //! - - - - - -
    private:
      bool              IceFactoryInitRayLib(void);
      //
      //
      static int                        __engineStatus;
      static bool                       __raylib;
      //
      RenderTexture2D                   __viewport;
      IceFactory*                       __instance;
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
  };
};

using Engine::IceFactory;

/*
    class Singleton {
    public:
        static Singleton* Instance();
    protected:
        Singleton();
    private:
        static Singleton* _instance;
    };

    Singleton* Singleton::_instance = 0;
    
    Singleton* Singleton::Instance () {
        if (_instance == 0) {
            _instance = new Singleton;
        }
        return _instance;
    }
*/

int  getStatusEngine(void);





#endif
