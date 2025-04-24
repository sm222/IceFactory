#ifndef   __DEBUG__
# define  __DEBUG__

// Made by Antoine
//* https://github.com/sm222
//

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <limits.h>
# include <math.h>


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
  cyan,
} e_debug_color;

# define  DEBUG_STATUS 1
# define  DEBUG_SLEEP  0

inline void Debug(const char* file_no_null, int line, const char* root, e_debug_color color, const char* s, ...) {
  #if DEBUG_STATUS
  {
    # if (DEBUG_SLEEP)
      usleep(DEBUG_SLEEP);
    # endif
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
    if (color == blue)    { c = TXT_BLU; }
    if (color == red)     { c = TXT_RED; }
    if (color == green)   { c = TXT_GRN; }
    if (color == yello)   { c = TXT_YEL; }
    if (color == magenta) { c = TXT_MAG; }
    if (color == orange)  { c = TXT_ORG; }
    if (color == pink)    { c = TXT_PIK; }
    if (color == cyan)    { c = TXT_CYN; }
    fprintf(stdout, "%s%s:%d%s %s\n", c, file_no_null + i, line, TXT_RESET, buff);
    va_end(va);
  }
  # else
  {
    (void)file_no_null;
    (void)line;
    (void)color;
    (void)root;
    (void)s;
  }
  #endif
}

# define DEBUG(root, color, s, ...)    Debug(__FILE__, __LINE__, root, color, s, ##__VA_ARGS__)

# define GRAF_LEN 1000

typedef double t_Graph[GRAF_LEN];

struct Graph {
  unsigned int        sampleRate;
  unsigned int        tick;
  t_Graph             graph;
  float               amplitude;
  size_t              graphLen = 100;
  const size_t        maxGraphLen = GRAF_LEN;
  bool                init;
};

inline void    UpdateGraff(Graph* data) {
  if (GRAF_LEN <= 1 || !data)
    return;
  for (size_t i = 0; i < GRAF_LEN - 1; i++) {
    data->graph[i] = data->graph[i + 1];
  }
}

inline void UpdateGraffValue(Graph* data, double v) {
  if (!data || (data->tick++ < data->sampleRate))
    return;
  data->graph[data->graphLen - 1] = v;
  UpdateGraff(data);
  data->tick = 0;
}

inline void ResetGraff(Graph* data) {
  data->tick = 0;
  for (size_t i = 0; i < GRAF_LEN; i++) {
    data->graph[i] = 0;
  }
}

# ifdef RAYLIB_H
inline void  DrawGraph(Graph* data, int x, int y) {
  if (!data)
    return;
  double min = LONG_MAX, max = LONG_MIN;
  for (size_t i = 0; i < GRAF_LEN; ++i) {
    if (data->graph[i] != 0) {
      min = data->graph[i] < min ? data->graph[i] : min;
      max = data->graph[i] > max ? data->graph[i] : max;
      Color c = GREEN;
      if (data->graph[i] == max)
        c = RED;
      else if (data->graph[i] < max && data->graph[i] > max * 0.9)
        c = YELLOW;
      else if (data->graph[i] == min && data->graph[i]) {
        c = GRAY;
      }
      DrawLine(x + i, y, x + i, y - (data->graph[i] * data->amplitude), c);
    }
  }
  const size_t buffSize = 150;
  char         buff[buffSize];
  DrawLine(x, y - 100, x + data->graphLen, y - 100, RED);
  snprintf(buff, buffSize - 1, "min : %.2f max : %.2f, last : %.2f", min, max, data->graph[data->graphLen - 2]);
  DrawText(buff, x + 10, y + 10, 10, GREEN);
  DrawLine(x, y, x + data->graphLen, y, BLUE);
}
# endif


//void Drawgraf()


#endif