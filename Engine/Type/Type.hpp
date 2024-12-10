#ifndef __TYPE__
# define __TYPE__

# define LOCAL_TYPE false

# if (LOCAL_TYPE)
  # include "LocalType.hpp"
# else
  # include <raylib.h>
# endif

enum {
  S_EngineStart,
  S_EngineInit,
  S_EngineRun,
  S_EngineUnload,
  S_EngineStop
};

#endif