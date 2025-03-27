#ifndef  __KEYS_NAME_H__
# define __KEYS_NAME_H__

// NEVER set value manually, alway have to be between 'NoKey' and 'K_End'
typedef enum ControlKeys {
  NoKey = 0,
  K_pause,
  K_forward,
  K_backward,
  K_left,
  K_right,
  K_use,
  K_croutch,
  K_End,
} t_ControlKeys;

#endif