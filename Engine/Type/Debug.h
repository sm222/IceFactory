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
  magenta,
  orange,
  pink,
} e_debug_color;


static void Debug(const char* file_no_null, int line, const char* root, e_debug_color color, const char* s, ...) {
  #if DEBUG_STATUS
  {
    char buff[10001];
    va_list va;
    va_start(va, s);
    vsnprintf(buff, 10000, s, va);
    size_t i = 0;
    if (root) {
      i = strlen(file_no_null);
      size_t rootNameLen = strlen(root);
      while (strncmp(file_no_null + i, root, rootNameLen) != 0) {
        i--;
      }
    }
    const char* c = TXT_WHT;
    if (color == blue)
      c = TXT_BLU;
    if (color == red)
      c = TXT_RED;
    if (color == green)
      c = TXT_GRN;
    if (color == yello)
      c = TXT_YEL;
    if (color == magenta)
      c = TXT_MAG;
    if (color == orange)
      c = TXT_ORG;
    if (color == pink)
      c = TXT_PIK;
    fprintf(stderr, "%s%s:%d%s %s\n", c, file_no_null + i, line, TXT_RESET, buff);
    va_end(va);
  }
  # else
  {
    (void)file_no_null;
    (void)line;
    (void)color;
    (void)dep;
    (void)s;
  }
  #endif
}

# define DEBUG(root, color, s, ...)    Debug(__FILE__, __LINE__, root, color, s, ##__VA_ARGS__)


#endif