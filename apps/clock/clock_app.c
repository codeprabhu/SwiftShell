#include <unistd.h>
#include <time.h>

#include "clock_app.h"
#include "../include/app.h"
#include "dashboard/dashboard.h"
#include "../spotify/terminal/terminal.h"
void startClock()
{
    enableRawMode();

    ClockMode mode = CLOCK_MODE;

    ClockState state = {0};

    state.remainingSeconds = 15 * 60;

    int running = 1;

    while(running)
    {
        switch(mode)
        {
            case CLOCK_MODE:
                renderClockDashboard();
                break;

            case TIMER_MODE:
                renderTimerDashboard(&state);
                break;

            case STOPWATCH_MODE:
                renderStopwatchDashboard(&state);
                break;
        }

        if(keyPressed())
        {
            char key = readKey();

            switch(key)
            {
                case 'c':
                case 'C':
                    mode = CLOCK_MODE;
                    break;

                case 't':
                case 'T':
                    mode = TIMER_MODE;
                    break;

                case 's':
                case 'S':
                    mode = STOPWATCH_MODE;
                    break;

                case ' ':

                    if(mode != CLOCK_MODE)
                    {
                        if(!state.running)
                        {
                            state.running = 1;
                            state.startTime = time(NULL);
                        }
                        else
                        {
                            state.running = 0;
                        }
                    }

                    break;

                case 'r':
                case 'R':

                    state.running = 0;

                    if(mode == TIMER_MODE)
                    {
                        state.remainingSeconds = 15 * 60;
                    }

                    if(mode == STOPWATCH_MODE)
                    {
                        state.elapsedSeconds = 0;
                    }

                    break;

                case 'q':
                case 'Q':

                    running = 0;
                    break;
            }
        }

        if(mode == STOPWATCH_MODE && state.running)
        {
            state.elapsedSeconds =
                time(NULL) - state.startTime;
        }

        if(mode == TIMER_MODE && state.running)
        {
            int elapsed =
                time(NULL) - state.startTime;

            state.remainingSeconds =
                15 * 60 - elapsed;

            if(state.remainingSeconds <= 0)
            {
                state.remainingSeconds = 0;
                state.running = 0;
            }
        }

        usleep(100000);
    }

    disableRawMode();
}

App clockApp =
{
    .name = "clock",
    .description = "Clock, Timer and Stopwatch",
    .run = startClock
};