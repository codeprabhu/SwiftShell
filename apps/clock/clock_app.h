#ifndef CLOCK_APP_H
#define CLOCK_APP_H

#include <time.h>
#include "../include/app.h"
typedef struct
{
    int running;
    int elapsedSeconds;
    int remainingSeconds;
    time_t startTime;

} ClockState;
typedef enum
{
    CLOCK_MODE,
    TIMER_MODE,
    STOPWATCH_MODE

} ClockMode;
void startClock(void);
extern App clockApp;
#endif