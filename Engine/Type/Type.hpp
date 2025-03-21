#ifndef __TYPE_H__
# define __TYPE_H__

# include <raylib.h>
# include <raymath.h>

# include <cstring>
# include <iostream>

# include "KeysName.hpp"
# include "Controls.hpp"

# include  <vector>

# ifndef  TXT_COLORS
#  define TXT_COLORS
#  define CS	"\001" //*start code
#  define CE	"\002" //*end   code 
#  define TXT_RED	CS "\e[31m" CE
#  define TXT_GRN	CS "\e[32m" CE
#  define TXT_YEL	CS "\e[33m" CE
#  define TXT_BLU	CS "\e[34m" CE
#  define TXT_MAG	CS "\e[35m" CE
#  define TXT_CYN	CS "\e[36m" CE
#  define TXT_WHT	CS "\e[37m" CE
#  define TXT_ORG	CS "\e[38;5;202m"  CE
#  define TXT_PIK	CS "\e[38;5;176m"  CE
#  define TXT_RESET	CS "\e[0m\022"   CE
#  define TXT_CLE	CS "\e[1;1H\x1b[2J" CE
# endif

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



#endif