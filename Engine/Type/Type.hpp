#ifndef __TYPE_H__
# define __TYPE_H__

# include <raylib.h>
# include <raymath.h>

# include <cstring>
# include <iostream>

# include "KeysName.hpp"
# include "Controls.hpp"

# include  <vector>
# include <array>

# include "Debug.h"

# define TYPE_KEY KeyboardKey

// use define to be redefine at compile time
# ifndef  LOCAL_FILE_PATH
#  define LOCAL_FILE_PATH
#  define PROJECT_ROOT "IceFactory"
#  define RESOURCE "Engine/Resource/"
#  define MODEL    "Models/"
#  define ERR_MESH RESOURCE MODEL "what.glb"
# endif

# define DEBUG_P(color, s, ...)   DEBUG(PROJECT_ROOT, color, s, ##__VA_ARGS__)

# ifndef ENGINE_DEF
#  define ENGINE_DEF
#  define ZERO 0
#  define MAX_NUMBER_OBJECTS 600
#  define MAX_NUMBER_MODEL   100 // add meaby later
#  define MAX_TEXTURE        300
#  define MAX_NAME_LEN       100
# endif

# define ZERO_NONE_PTR(var)    memset(&var, ZERO ,sizeof(var))
typedef struct {
  Model        data;
  char         name[MAX_NAME_LEN + 1];
} ImportModel;

typedef struct {
  ModelAnimation  data;
  char            name[MAX_NAME_LEN + 1];
} ImportModelAnimation;


typedef enum EngineEvents {
  Event_none = ZERO,
  Event_pause,
  Event_window_resized,
} t_EngineEvents;

typedef enum EngineStatus{
  S_EngineInit = ZERO,
  S_EngineStart,
  S_EngineRun,
  S_EnginePause,
  S_EngineUnload,
  S_EngineStop
} t_EngineStatus;

typedef enum InputType {
  KeybordMouse = 0,
  Gamepad,
} t_InputType;

typedef struct {
  unsigned int targetFps;
  Vector2      targetWindowSize;
} UserSeting;

typedef struct dataText {
  int         type;
  std::string s;
  Color       c;
} t_dataText;


enum UiType {
  Ui_base = 0,
  Ui_consol
};
typedef struct ui {
  Rectangle window;
  bool      reSizeAble;
  int       type;
} t_ui;

typedef enum {
  t_none = -1, // void
  t_float,
  t_int,
  t_vector2,
  t_vector3,
} t_typesValue;

typedef struct {
  int returnValue;
  int val1;
  int val2;
  int val3;
} t_prototype;

# define prototype(returnValue, val1, val2, val3) (t_prototype){returnValue, val1, val2, val3}

// valid type
union t_types {
  float   f;
  int     i;
  Vector2 vec2;
  Vector3 vec3;
};


#endif