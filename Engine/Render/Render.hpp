#ifndef  __RENDER_HPP__
# define __RENDER_HPP__

# include "../Group/Group.hpp"
# include "../Object/3D/3DCamera/3DCamera.hpp"
# include "Layer/Layer.hpp"

# define MAX_RENDERER_LAYERS 5
# include <map>


typedef std::map<std::string, Layer*> LayersData;

class Render {
  public:
    Render();
    ~Render(void);
    size_t AddLayer(std::string name, Vector2 size);
    bool   ResizeLayer(std::string name, Vector2 size);
    bool   Start(Vector2 window);
    void   Close(void);
    //
    bool   Draw(Camera_3D& c, Group& g, std::string layer);
    bool   Print(std::string layer);
  private:
    LayersData __layers;
    //Group __cameras3D;
    //Group __cameras2D;

    //
};

#endif