# include "Render.hpp"

Render::Render(void) {
  DEBUG_P(TXT_MAG, "Init");
}

size_t Render::AddLayer(std::string name, Vector2 size) {
  __layers[name] = new Layer(size);
  return __layers.size();
}

void Render::Close(void) {
  for (auto it = __layers.begin(); it != __layers.end(); it++ ) {
    Layer* l = it->second;
    delete l;
  }
  __layers.clear();
}

Render::~Render(void) {
  DEBUG_P(TXT_MAG, "End");
}

