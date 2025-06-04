# include "../Engine/IceFactory.hpp"
# include "../Engine/Object/DevCube.hpp"
# include "../Engine/Camera/BaseCamera.hpp"
# include "../Engine/Type/RenderType.hpp"
//# include "../Engine/Ui/UiBaseTextBox.hpp"


void UpatePlayer(IceFactory& engine, BaseCamera& PlayerCamera) {
  if (engine.GetEngineStatus() != S_EnginePause) {
    PlayerCamera.Update(
    (Vector3) { engine.timeScale(engine.GetAnalogInput(ForwardBackward) * 5.0f),
                engine.timeScale(engine.GetAnalogInput(LeftRight) * 5.0f),
                0.0f },
    (Vector3) { engine.GetAnalogInput(MouseHorizontal) * 0.05f, // Rotation: yaw
                engine.GetAnalogInput(MouseVertical)   * 0.05f, // Rotation: pitch
                0.0f /* Rotation: roll*/ },
                0);
  }
}

void loop(IceFactory& engine) {
  BaseCamera    PlayerCamera("player");
  //UiRenderZone  uiTest("uiTest", 400, 400);
  //UiBaseBlock   uiBlock("block");
  engine._root.Add(&PlayerCamera);
  Vector2 small = engine.GiveWindowSize();
  PlayerCamera.SetPosition((Vector3){1, 0, 1});
  PlayerCamera.SetCanvas(small);
  PlayerCamera.SetDrawSize(small);
  PlayerCamera.SetTarget(Vector3 {0,0,0});
  PlayerCamera.Set2DDrawPosition(small / 2);
  //-------
  BaseCamera   testCam("testCam");
  PlayerCamera.SetDebug(true);
  testCam.SetPosition({2, 0, 2});
  testCam.SetCanvas(small / 4);
  testCam.SetDrawSize(small / 4);
  testCam.SetTarget({0,0,0});
  testCam.Set2DDrawPosition(small / 7);
  testCam.SetMode(t_camera_mode::camera_texture_keep);
  Color tr = WHITE;
  tr.a /= 5;
  testCam.SetColors(GRAY, tr);
  //
  engine.Textures2D.Add("Engine/Resource/Image/cat.jpg");
  engine.Models.Add("Engine/Resource/Models/Axis_Cube.m3d");
  engine.AddCameraToUpdateList(&PlayerCamera);
  engine.AddCameraToUpdateList(&testCam);
  engine._root.Add(&testCam);
  Room* r = engine.GetRoom(0);
  RenderInstruction rule[3];
  R_SET_CAMERA(0, rule);
  R_SET_LAYER(0, rule);
  R_SET_GROUP(0, rule);
  r->SetRenderRule(rule, 0);
  r->Set3DCamera(&PlayerCamera, 0);
  r->SetLayer(0, small);
  MeshObject mesh("mesh");
  mesh.SetModel(engine.Models.Get("Engine/Resource/Models/Axis_Cube.m3d"));
  Object t("test");
  DevCube cube("cube");
  cube.SetSize({0.5, 0.5, 0.5});
  cube.SetShape(0);
  cube.SetMetod(R_wire);
  BaseGroup  GameTest("gametest");
  GameTest.Add(&t);
  GameTest.Add(&cube);
  GameTest.Add(&mesh);
  r->SetToRender(0, &GameTest, 0);
  r->SetToRender(1, &GameTest, 1);
  BaseGroup newG("mewG");
  t_BaseInterface V;
  t.interface.Get(0, V);
  V._ft.void_void(t);
  newG.Add(&t);
  
  r->SetToRender(&GameTest, 0);
  engine._root.Add(&newG);
  engine._root.Add(&newG);
  engine._root.Remove("mewG");
  engine._root.Add(&newG);
  engine._root.PrintTree();
  engine._root.Remove("mewG");
  engine._root.Remove("mewG");
  //
  engine.Audios.Add("Engine/Resource/Sound/clap.mp3");
  engine.Audios.AddSound("Engine/Resource/Sound/clap.mp3");
  HideCursor();
  DisableCursor();
  //
  int status = IceFactory::GetEngineStatus();
  while (status == S_EngineRun || status == S_EnginePause) {
    //usleep(50000);
    status = IceFactory::GetEngineStatus();
    engine.UpdateEngine();
    UpatePlayer(engine, PlayerCamera);
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
      engine.Audios.Play("Engine/Resource/Sound/clap.mp3");
  }
}

int main(void) {
  IceFactory engine;
  int run = 1;
  engine.Start();
  int kill = 0;
  while (run) {
    if (kill++ > 6) {
      run = 0;
      DEBUG_P(red, "game kill for infinit loop");
    }
    switch (IceFactory::GetEngineStatus()) {
      case S_EngineInit: {
        engine.initEngine();
        break;
      }
      case S_EngineRun: {
        SetTraceLogLevel(LOG_WARNING);
        loop(engine);
        engine.closeEngine();
        break;
      }
      case S_EngineStop: {
        run = 0;
        break;
      }
      case S_EngineReboot: {
        engine.Start();
        engine.initEngine();
        kill = 0;
        break;
      }
      default:
        DEBUG_P(red, "unknow case");
        return 1;
    }
  }
  engine.SetEngineStatus(S_EngineForceStop);
  engine.closeEngine();
  return 0;
}

