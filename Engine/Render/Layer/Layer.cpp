#include "Layer.hpp"


unsigned short Layer::__actifLayer = 0;

bool  Layer::Init(void) {
  __data = LoadRenderTexture(__size.x, __size.y);
  return IsRenderTextureValid(__data);
}

Layer::Layer(Vector2 size) {
  __size = size;
  if (__size.x < 1 || __size.y < 1) {
    __status = layer_invalide;
    DEBUG_P(TXT_RED, "layer try init with invalid value x:%f y:%f", __size.x, __size.y);
  }
  __status = layer_init;
  if (!Init()) {
    DEBUG_P(TXT_RED, "layer fail to init");
    return;
  }
  __status = layer_valid;
}

Layer::~Layer(void) {
  if (IsRenderTextureValid(__data))
    UnloadRenderTexture(__data);
}

layerStatus  Layer::Start(void) {
  if (__actifLayer) { return layer_other; }
  if (__status == layer_init || __status == layer_invalide) { return  layer_invalide; }
  if (__status == layer_drawing) {
    DEBUG_P(TXT_ORG, "try to use a layer all ready bussy");
    return __status;
  }
  BeginTextureMode(__data);
  __actifLayer++;
  __status = layer_rendering;
  return __status;
}

layerStatus  Layer::ReSize(Vector2 size) {
  if (__status != layer_valid) { return layer_error; }
  if (size.x < 1 || size.y < 1) { return layer_invalide; }
  if (size == __size) { return __status; }
  if (IsRenderTextureValid(__data)) {
    __size = size;
    DEBUG_P(TXT_WHT, "%d", __status);
    UnloadRenderTexture(__data);
    __data = LoadRenderTexture(__size.x, __size.y);
    __status = IsRenderTextureValid(__data) ? layer_valid : layer_invalide;
    return __status;
  }
  return layer_invalide;
}

layerStatus  Layer::Stop(void) {
  if (__status != layer_rendering) {
    return layer_error;
  }
  EndTextureMode();
  __actifLayer--;
  __status = layer_valid;
  return __status;
}

const RenderTexture2D Layer::GetFrame(void) const {
  return __data;
}
