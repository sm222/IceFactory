#ifndef  __MESH_OBJECT_H__
# define __MESH_OBJECT_H__

# include "Object3D.hpp"

#define MESH_OBJECT_TYPE "Mesh_Object"

class MeshObject : public Object3D {
  public:
    MeshObject(const char* name);
    MeshObject(const std::string& name);
    virtual ~MeshObject(void);
    bool     SetErrorModel(Model* ptr);
    bool     SetErrorModel(const Model model);
    //
    bool     SetModel(const Model model);
    // edit object
    void     SetRotationAngle(const float rotation);
    void     SetRotationAxis(const Vector3& Axis);
    void     SetScale(const Vector3& scale);
    // get value
    float    GetRotationAngle(void) const;
    Vector3  GetRotationAxis(void) const;
    Vector3  GetScale(void) const;
    //
    void        Draw(int metod) const;
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