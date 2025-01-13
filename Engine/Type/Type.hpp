#ifndef __TYPE_H__
# define __TYPE_H__


# include <raylib.h>
# include <raymath.h>

# include "KeysName.hpp"
# include "Controls.hpp"

# define TYPE_KEY KeyboardKey


// use define to be redefine at compile time
# ifndef  LOCAL_FILE_PATH
#  define LOCAL_FILE_PATH
#  define RESOURCE "Engine/Resource/"
#  define MODEL    "Models/"
#  define ERR_MESH RESOURCE MODEL "what.glb"
# endif

# ifndef ENGINE_DEF
#  define ENGINE_DEF
#  define ZERO 0
#  define MAX_NUMBER_OBJECTS 600
#  define MAX_NUMBER_MODEL   100 // add meaby later
#  define MAX_TEXTURE        300
#  define MAX_NAME_LEN       100
# endif

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


typedef struct {
  unsigned int targetFps;
  Vector2      targetWindowSize;
} UserSeting;



#endif