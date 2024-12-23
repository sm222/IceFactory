#ifndef __TYPE__
# define __TYPE__

# define LOCAL_TYPE false

# if (LOCAL_TYPE)
  # include "LocalType.hpp"
# else
  # include <raylib.h>
  # include <raymath.h>
# endif

enum {
  S_EngineStart,
  S_EngineInit,
  S_EngineRun,
  S_EngineUnload,
  S_EngineStop
};

  typedef struct s_Box {
    Vector3 a[4];
    Vector3 b[4];
    Color   c;
    void Draw(void) {
      for (int i = 0; i < 4; i++) {
        const int tmp = i < 2 ? i + 1 : 0;
        DrawLine3D(a[i], a[tmp], c);
        DrawLine3D(b[i], b[tmp], c);
        DrawLine3D(a[i], b[i], c);
      }
      
    };
  } t_box;


#endif