#ifndef  __BASE_INTERFACE__
# define __BASE_INTERFACE__

# include "../Type/Type.hpp"

class Base;
//* void
typedef void(*v__v)(Base& self);

//* void whit param 1 to 3
typedef void(*v__1)(Base& self, t_types v1);
typedef void(*v__2)(Base& self, t_types v1, t_types v2);
typedef void(*v__3)(Base& self, t_types v1, t_types v2, t_types v3);

//* int whit param 1 to 3
typedef int(*i__1)(Base& self, t_types v1);
typedef int(*i__2)(Base& self, t_types v1, t_types v2);
typedef int(*i__3)(Base& self, t_types v1, t_types v2, t_types v3);

//* vec2 whit param 1 to 3
typedef Vector2(*vec2__1)(Base& self, t_types v1);
typedef Vector2(*vec2__2)(Base& self, t_types v1, t_types v2);
typedef Vector2(*vec2__3)(Base& self, t_types v1, t_types v2, t_types v3);

//* vec3 whit param 1 to 3
typedef Vector3(*vec3__1)(Base& self, t_types v1);
typedef Vector3(*vec3__2)(Base& self, t_types v1, t_types v2);
typedef Vector3(*vec3__3)(Base& self, t_types v1, t_types v2, t_types v3);

/// @brief name on the left return value
/// @brief name on the right is number of params
union function_type {
  void*  ptr; // null check at run time
  v__v   v_v;
  // void
  v__1   v_1;
  v__2   v_2;
  v__3   v_3;
  // int
  i__1   i_1;
  i__2   i_2;
  i__3   i_3;
  // vec2
  vec2__1  vec2_1;
  vec2__2  vec2_2;
  vec2__3  vec2_3;
  // vec3
  vec3__1  vec3_1;
  vec3__2  vec3_2;
  vec3__3  vec3_3;
};

typedef struct s_BaseInterface {
  function_type _ft;
  t_prototype   _types;
  const char*   _name;
  const char*   _description;
} t_BaseInterface;

template <size_t max>
class BaseInterface {
  public:
    BaseInterface(void);
    ~BaseInterface(void);
    //
    bool Add(v__v ft, t_prototype types, const char* name, const char* description);
    bool Get(size_t i, t_BaseInterface& get);
    //
  private:
    void __Add(t_prototype types, const char* name, const char* description);
    size_t                             __i;
    std::array<t_BaseInterface, max>   __list;
};

# include "BaseInterface.tpp"


# endif