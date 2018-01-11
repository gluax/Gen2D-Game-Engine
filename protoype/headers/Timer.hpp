#ifndef _Timer_HPP
#define _Timer_HPP

#include <SDL.h>

class Timer {

public:

  static Timer* Instance();
  static void Release();

  void Reset();
  float DeltaTime();

  void TimeScale(float t);
  float TimeScale();

  void Update();

private:
  
  static Timer *sInstance;

  unsigned int mStartTicks;
  unsigned int mElapsedTicks;
  float mDeltaTime;
  float mTimeScale;

  Timer();
  ~Timer();
};

#endif