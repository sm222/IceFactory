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
    bool     SetModel(const char* name);
  //
    void        Draw(int metod);
  protected:
    void        DrawModelMode(void(*ft)(Model , Vector3, Vector3, float, Vector3 , Color));
  private:
    void          Zero(void);
    Model         __model;
    Texture2D     __texture;
    BoundingBox   __bondingBox;
    //
    Vector3      __rotationAxis;
    float        __rotationAngle;
    //
    Vector3      __scale;
    Color        __tint;
    //
    //!
    Model*       __errorModel;
};

#endif