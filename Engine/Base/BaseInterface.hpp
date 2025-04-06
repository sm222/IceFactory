#ifndef  __BASE_INTERFACE__
# define __BASE_INTERFACE__

# include "../Type/Type.hpp"

class Base;
//* void
typedef    void(*void__void)(Base& self);

//* void whit param 1 to 3
typedef    void(*void__1)(Base& self, t_types v1);
typedef    void(*void__2)(Base& self, t_types v1, t_types v2);
typedef    void(*void__3)(Base& self, t_types v1, t_types v2, t_types v3);

//* int whit param 1 to 3
typedef     int(*int__1)(Base& self, t_types v1);
typedef     int(*int__2)(Base& self, t_types v1, t_types v2);
typedef     int(*int__3)(Base& self, t_types v1, t_types v2, t_types v3);

//* int whit param 1 to 3
typedef   float(*float__1)(Base& self, t_types v1);
typedef   float(*float__2)(Base& self, t_types v1, t_types v2);
typedef   float(*float__3)(Base& self, t_types v1, t_types v2, t_types v3);

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
  void__void   void_void;
  // void
  void__1   void_1;
  void__2   void_2;
  void__3   void_3;
  // int
  int__1    int_1;
  int__2    int_2;
  int__3    int_3;
  // float
  float__1  float_1;
  float__2  float_2;
  float__3  float_3;
  // vec2
  vec2__1   vec2_1;
  vec2__2   vec2_2;
  vec2__3   vec2_3;
  // vec3
  vec3__1   vec3_1;
  vec3__2   vec3_2;
  vec3__3   vec3_3;
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
    bool Add(void__void ft, const char* name, const char* description);
    //
    bool Add(void__1 ft, t_prototype types, const char* name, const char* description);
    bool Add(void__2 ft, t_prototype types, const char* name, const char* description);
    bool Add(void__3 ft, t_prototype types, const char* name, const char* description);
    //
    bool Add(int__1 ft, t_prototype types, const char* name, const char* description);
    bool Add(int__2 ft, t_prototype types, const char* name, const char* description);
    bool Add(int__3 ft, t_prototype types, const char* name, const char* description);
    //
    bool Add(float__1 ft, t_prototype types, const char* name, const char* description);
    bool Add(float__2 ft, t_prototype types, const char* name, const char* description);
    bool Add(float__3 ft, t_prototype types, const char* name, const char* description);
    //
    bool Add(vec2__1 ft, t_prototype types, const char* name, const char* description);
    bool Add(vec2__2 ft, t_prototype types, const char* name, const char* description);
    bool Add(vec2__3 ft, t_prototype types, const char* name, const char* description);
    //
    bool Add(vec3__1 ft, t_prototype types, const char* name, const char* description);
    bool Add(vec3__2 ft, t_prototype types, const char* name, const char* description);
    bool Add(vec3__3 ft, t_prototype types, const char* name, const char* description);
    //
    bool Get(size_t i, t_BaseInterface& get);
    //
  private:
    bool __Add(t_prototype types, const char* name, const char* description);
    size_t                             __i;
    std::array<t_BaseInterface, max>   __list;
};

# include "BaseInterface.tpp"


# endif