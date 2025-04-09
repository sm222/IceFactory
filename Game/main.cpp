# include "../Engine/IceFactory.hpp"
# include "../Engine/Object/DevCube.hpp"
# include "../Engine/Camera/BaseCamera.hpp"
# include "../Engine/Ui/UiBaseTextBox.hpp"
# include <iostream>

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

int rm = 0;

static void Button004(void) {

}

void loop(IceFactory& engine) {
  BaseCamera    PlayerCamera("player");
  UiRenderZone  uiTest("uiTest", 400, 400);
  UiBaseBlock   uiBlock("block");
  engine._root.Add(&PlayerCamera);
  SetTargetFPS(144);
  Vector2 small = engine.GiveWindowSize();
  PlayerCamera.SetPosition((Vector3){1, 0, 1});
  PlayerCamera.SetCanvas(small);
  PlayerCamera.SetTarget(Vector3 {0,0,0});
  //-------
  engine.AddCameraToUpdateList(&PlayerCamera);
  Room* r = engine.GetRoom(0);
  Object t("test");
  DevCube cube("cube");
  cube.SetSize({0.5, 0.5, 0.5});
  cube.SetShape(0);
  cube.SetMetod(draw_solid | draw_mesh);
  BaseGroup  GameTest("gametest");
  GameTest.Add(&t);
  GameTest.Add(&cube);
  r->SetToRender(0, &GameTest, 0);
  BaseGroup newG("mewG");
  t_BaseInterface V;
  t.interface.Get(0, V);
  V._ft.void_void(t);
  newG.Add(&t);
  engine._root.Add(&newG);
  engine._root.Add(&newG);
  engine._root.Remove("mewG");
  engine._root.Add(&newG);
  engine._root.PrintTree();
  engine._root.Remove("mewG");
  engine._root.Remove("mewG");
  //
  HideCursor();
  DisableCursor();
  //
  while (!WindowShouldClose()) {
    engine.UpdateEngine();
    if (engine.ReadEnvent(Event_window_resized)) {
      PlayerCamera.SetCanvas(engine.GiveWindowSize());
    }
    UpatePlayer(engine, PlayerCamera);
    //
    if (IsKeyPressed(KEY_L)) {
      rm++;
      if (rm > 2)
        rm = 0;
    }
    if (engine.ReadEnvent(Event_pause)) {
      if (IsCursorHidden()) {
        ShowCursor();
        EnableCursor();
        engine.SetEngineStatus(S_EnginePause);
      }
      else {
        HideCursor();
        DisableCursor();
        engine.SetEngineStatus(S_EngineRun);
      }
    }
    //
    //
    uiTest.Render();
    PlayerCamera.Start();
    DrawPlane({0,-1, 0}, {40, 40}, GRAY);
    PlayerCamera.Stop();
    //BeginDrawing();
    //PlayerCamera.DrawFrame({0,0});
    //uiTest.Draw(0);
    //DrawFPS(0,0);
    ////
    ////
    //EndDrawing();
    //PlayerCamera.Clear();
  }
}

int main(void) {
  IceFactory engine;
  int run = 1;
  Groups<Object*> newGroup;
  while (run) {
    switch (IceFactory::GetEngineStatus()) {
      case S_EngineInit:
        engine.initEngine();
        break;
      case S_EngineStart:
        engine.InitRaylib();
        break;
      case S_EngineRun:
        engine._mainGroups.AddChild(&newGroup);
        SetTraceLogLevel(LOG_WARNING);
        loop(engine);
        engine._mainGroups.Delete(-1);
        engine.closeEngine();
        break;
      case S_EngineStop:
        run = 0;
        break;
      default:
        break;
    }
  }
  return 0;
}