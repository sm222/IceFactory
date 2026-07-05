#ifndef  __KEYS_NAME_H__
# define __KEYS_NAME_H__

// NEVER set value manually, alway have to be between 'NoKey' and 'K_End'
typedef enum ControlKeys {
  NoKey = 0,
  K_Pause,
  K_Forward,
  K_Backward,
  K_Left,
  K_Right,
  K_Use,
  K_Croutch,
  K_Look_Up,
  K_Look_Down,
  K_Look_Left,
  K_Look_Right,
  K_Reload,
  K_Jump,
  K_End,
} t_ControlKeys;

#endif