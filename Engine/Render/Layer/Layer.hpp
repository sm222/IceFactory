#ifndef  __ENGINE_LAYER__
# define __ENGINE_LAYER__

#include "../../Type/Type.hpp"

typedef enum {
  layer_invalide,
  layer_valid,
  layer_other, // somone allready rendering
  layer_drawing,
  layer_rendering,
  layer_init,
  layer_error,
} layerStatus;

class Layer {
  public:
    Layer(Vector2 size);
    ~Layer(void);
    layerStatus             Start(void);
    layerStatus             Stop(void);
    const RenderTexture2D   GetFrame(void) const ;
    layerStatus             ReSize(Vector2 size);
  private:
    bool                    Init(void);
    RenderTexture2D       __data;
    Vector2               __size;
    static unsigned short __actifLayer;
    layerStatus           __status;
};

#endif