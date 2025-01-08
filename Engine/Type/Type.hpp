#ifndef __TYPE_H__
# define __TYPE_H__


# include <raylib.h>
# include <raymath.h>

# include "KeysName.hpp"
# include "Controls.hpp"

# define TYPE_KEY int

typedef enum EngineEvents {
  Event_none = 0,
  Event_pause,
} t_EngineEvents;

enum {
  S_EngineStart,
  S_EngineInit,
  S_EngineRun,
  S_EnginePause,
  S_EngineUnload,
  S_EngineStop
};


#endif