#ifndef  __MESH_OBJECT_H__
# define __MESH_OBJECT_H__

# include "Object.hpp"

#define MESH_OBJECT_TYPE "Mesh_Object"

class MeshObject : public Object {
  public:
    MeshObject(void);
    MeshObject(const char* name);
    MeshObject(const std::string& name);
    virtual ~MeshObject(void);
    bool     SetErrorModel(Model* ptr);
  //
  void          Draw(void);
  private:
  void          Clean(void);
  Model         __model;
  Texture2D     __texture;
  BoundingBox   __bondingBox;
  //!
  Model*        __errorModel;
};

#endif