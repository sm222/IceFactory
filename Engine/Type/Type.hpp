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
  Event_window_resized,
} t_EngineEvents;

typedef enum EngineStatus{
  S_EngineStart,
  S_EngineInit,
  S_EngineRun,
  S_EnginePause,
  S_EngineUnload,
  S_EngineStop
} t_EngineStatus;


#endif