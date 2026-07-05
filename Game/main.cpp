# include "../Engine/IceFactory.hpp"


#include "../Engine/Object//3D/Dev/DevCube.hpp"


void loop(IceFactory& engine) {
  int status = IceFactory::GetEngineStatus();
  DevCube3D cube("cube");
  while (status == S_EngineRun || status == S_EnginePause) {
    //usleep(50000);
    status = IceFactory::GetEngineStatus();
    engine.UpdateEngine();
    //UpatePlayer(engine, PlayerCamera);
  }
  DEBUG_P(TXT_GRN, "end of loop");
}


int main(int ac, char** av) {
  IceFactory engine;
  (void)ac; (void)av; // add flags later
  int run = 1;
  engine.Start();
  int kill = 0;
  while (run) {
    if (kill++ > 6) {
      run = 0;
      DEBUG_P(TXT_RED, "Engine kill for infinit loop");
    }
    switch (IceFactory::GetEngineStatus()) {
      case S_EngineInit: {
        engine.InitEngine();
        break;
      }
      case S_EngineRun: {
        SetTraceLogLevel(LOG_WARNING);
        loop(engine);
        engine.CloseEngine();
        break;
      }
      case S_EngineStop: {
        run = 0;
        break;
      }
      case S_EngineReboot: {
        engine.Reboot(0);
        kill = 0;
        break;
      }
      default:
        DEBUG_P(TXT_RED, "unknow case");
        return 1;
    }
  }
  engine.Stop();
  return 0;
}
