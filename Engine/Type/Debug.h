#ifndef   __DEBUG__
# define  __DEBUG__

# include <stdio.h>
# include <stdarg.h>

# define  DEBUG_STATUS 1

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


typedef enum {
  white = 0,
  green,
  red,
  blue,
  yello,
} e_debug_color;

static void Debug(int m = 0, const char* s = "", ...) {
  # if DEBUG_STATUS
  {
    char b[1001];
    va_list va;
    va_start(va, s);
    vsnprintf(b, 1000, s, va);
    switch (m) {
      case green:
        printf("%sLOG -> %s%s\n", TXT_GRN, b, TXT_RESET);
        break;
      case red:
        printf("%sLOG -> %s%s\n", TXT_RED, b, TXT_RESET);
        break;
      case blue:
        printf("%sLOG -> %s%s\n", TXT_BLU, b, TXT_RESET);
        break;
      case yello:
        printf("%sLOG -> %s%s\n", TXT_YEL, b, TXT_RESET);
      default:
        printf("LOG -> %s\n", b);
        break;
    }
    va_end(va);
  }
  # else
  {
    (void)m;
    (void)s;
  }
  #endif
}

# define DEBUG(mode, msg)  Debug(mode, msg "\n%d : %s", __LINE__, __FILE__)

// error
# define E_DEBUG(msg)      DEBUG(red,   msg) 
// class
# define C_DEBUG(msg)      DEBUG(blue,  msg) 
// warning
# define W_DEBUG(msg)      DEBUG(yello, msg) 
// log
# define L_DEBUG(msg)      DEBUG(green, msg) 



#endif