#ifndef  __ENGINE_TIMER__
# define __ENGINE_TIMER__

# include "../Type/Type.hpp"
# define TIMER_NO_TIME 0

typedef enum {
  timer_faild,
  timer_end,
  timer_pause,
  timer_runing,
} EmgineTimer_t;

typedef long double timerTime;

class EngineTimer {
  public:
    EngineTimer(timerTime start, bool active);
    EngineTimer(timerTime start);
    EngineTimer(void);
    ~EngineTimer(void);
    int       Update(float deltaTime);
    void      SetTime(timerTime t);
    void      SetStatus(EmgineTimer_t status);
    timerTime GetTime(void) const;
    //
  private:
    timerTime  __time;
    int        __status;
};

#endif