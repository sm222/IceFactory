#include "HideIceFactory.hpp"
#include "Type/Type.hpp"
#include <iostream>
#include <exception>

IceFactory* IceFactory::__instance     = nullptr;
bool        IceFactory::__raylib       = false;
Vector2     IceFactory::__screenSize   = {800 ,800};
std::string IceFactory::__GameName     = "def";
int         IceFactory::__engineStatus = 0;

IceFactory::IceFactory(void)  {

}


IceFactory::~IceFactory(void) {}

IceFactory* IceFactory::Instance(void) {
  if (!__instance) {
    __instance = new IceFactory();
    if (!__instance)
      throw std::runtime_error("new fail");
  }
  __engineStatus = S_EngineStart;
  return __instance;
}

void IceFactory::endEngine(void) {
  __engineStatus = S_EngineStop;
  if (__instance) {
    delete __instance;
    __instance = nullptr;
  }
}

int IceFactory::GetEngineStatus(void) {
  return __engineStatus;
}

int getStatusEngine(void) {
  return IceFactory::GetEngineStatus();
}

void initEngine(void) {
  IceFactory::Instance();
}

void initRaylib(void) {
  IceFactory* e = IceFactory::Instance();
  if (!e->IceFactoryInitRayLib())
    throw std::runtime_error("raylib fail");

}

void closeEngine(void) {
  IceFactory::endEngine();
  std::cout << "end" << std::endl;
}

