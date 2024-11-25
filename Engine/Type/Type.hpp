#ifndef __TYPE__
# define __TYPE__

# define LOCAL_TYPE false

# if (LOCAL_TYPE)
  # include "LocalType.hpp"
# else
  # include <raylib.h>
# endif

# define VEC2 Vector2
# define VEC3 Vector3

#endif