#ifndef  __HIDE_ICE_FACTORY__
# define __HIDE_ICE_FACTORY__

# include <raylib.h>
# include <raymath.h>
# include <string>


namespace Engine {
  class IceFactory {
    public:
      static IceFactory* Instance(void);
      static void        endEngine(void);
      bool               IceFactoryInitRayLib(void);
      static int         GetEngineStatus(void);
    protected:
      IceFactory(void);
      ~IceFactory(void);
    private:
      //
      //
      static int         __engineStatus;
      static IceFactory* __instance;
      static bool        __raylib;
      static Vector2     __screenSize;
      static std::string __GameName;
  };
};

using Engine::IceFactory;

#endif