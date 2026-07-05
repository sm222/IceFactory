# include "Timer.hpp"

EngineTimer::EngineTimer(timerTime start, bool active) {
  __status = active ? timer_runing : timer_pause;
  __time = start;
  DEBUG_P(TXT_PIK, "time%ld mode%d", __time, __status);
}

EngineTimer::EngineTimer(timerTime start): EngineTimer(start, true) {
}

EngineTimer::EngineTimer(): EngineTimer(TIMER_NO_TIME, false) {
}

EngineTimer::~EngineTimer(void) {}

int    EngineTimer::Update(float deltaTime) {
  switch (__status) {
    case timer_faild:
    case timer_end:
    case timer_pause:
      return __status;
    case timer_runing:
      __time -= deltaTime;
      if (__time <= 0) { __status = timer_end; }
      break ;
  }
  DEBUG_P(TXT_RED, "unknow: timer case:%d", __status);
  return __status;
}

void  EngineTimer::SetTime(timerTime t) { __time = t; }

void  EngineTimer::SetStatus(EmgineTimer_t status) { __status = status; }

timerTime EngineTimer::GetTime(void) const { return __time; }

