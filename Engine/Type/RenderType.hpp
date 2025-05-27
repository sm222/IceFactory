#ifndef   __RENDERTYPE__
# define  __RENDERTYPE__

typedef enum {
  R_none    = 0,
  R_hitbox  = 0b00001,
  R_wire    = 0b00010,
  R_mesh    = 0b00100,
  R_texture = 0b01000,
} RenderTypes;


#endif