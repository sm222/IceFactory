# include "Render.hpp"

Render::Render(void) {
  DEBUG_P(TXT_MAG, "Init");
}

size_t Render::AddLayer(std::string name, Vector2 size) {
  __layers[name] = new Layer(size);
  return __layers.size();
}

bool  Render::ResizeLayer(std::string name, Vector2 size) {
  auto it = __layers.find(name);
  if (it != __layers.end()) {
    DEBUG_P(TXT_YEL, "resize x:%f y:%f", size.x, size.y);
    return it->second->ReSize(size) == layer_valid;
  }
  return false;
}

bool Render::Start(Vector2 window) {
  AddLayer("main", window);
  return IsRenderTextureValid(__layers["main"]->GetFrame());
}

void Render::Close(void) {
  for (auto it = __layers.begin(); it != __layers.end(); it++ ) {
    Layer* l = it->second;
    delete l;
  }
  __layers.clear();
}

static void __drawGroup(Group& g) {
  auto it = g.GetStart();
  for ( ; it != g.GetEnd(); it++) {
    const Obj* o = (const Obj*)*it;
    o->Draw(0);
  }
}

bool Render::Draw(Camera_3D& c, Group& g, std::string layer) {
  auto it = __layers.find(layer);
  if (it != __layers.end()) {
    it->second->Start();
    ClearBackground(BLANK);
    BeginMode3D(c.GetCamera3D());
    __drawGroup(g);
    EndMode3D();
    it->second->Stop();
    return true;
  }
  DEBUG_P(TXT_RED, "nope");
  return false;
}

bool Render::Print(std::string layer) {
  char s[200];
  auto it = __layers.find(layer);
  if (it != __layers.end()) {
    const RenderTexture2D t = it->second->GetFrame();
    const Rectangle src = {0, 0, (float)t.texture.width, -(float)t.texture.height};
    const Rectangle dst = {0, 0, (float)t.texture.width,  (float)t.texture.height};
    DrawTexturePro(t.texture, src, dst, {0, 0}, 0, WHITE);
    snprintf(s, 200, "%f %f", (float)t.texture.width, (float)t.texture.height);
    DrawText(s, 60, 60, 10, GREEN);
    return true;
  }
  return false;
}

Render::~Render(void) {
  DEBUG_P(TXT_MAG, "End");
}

