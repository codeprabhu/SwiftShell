#include <stdio.h>
#include <time.h>
#include "../clock_app.h"
#include "dashboard.h"

static void clearScreen()
{
    printf("\033[2J");
    printf("\033[H");
}

static void formatTime(int seconds, char* buffer)
{
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;

    sprintf(
        buffer,
        "%02d:%02d:%02d",
        hours,
        minutes,
        secs
    );
}

void renderClockDashboard()
{
    clearScreen();

    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    char timeString[32];
    char dateString[64];
    char dayString[32];

    strftime(timeString,sizeof(timeString),"%H:%M:%S",t);
    strftime(dayString,sizeof(dayString),"%A",t);
    strftime(dateString,sizeof(dateString),"%d %B %Y",t);

    printf("=====================================================\n");
    printf("                  SwiftClock\n");
    printf("=====================================================\n\n");

    printf("                 %s\n\n",timeString);

    printf("                 %s\n",dayString);
    printf("              %s\n\n",dateString);

    printf("=====================================================\n");
    printf("[C] Clock\n");
    printf("[T] Timer\n");
    printf("[S] Stopwatch\n");
    printf("[Q] Quit\n");
    printf("=====================================================\n");
}

void renderTimerDashboard(ClockState* state)
{
    clearScreen();

    char buffer[32];

    formatTime(state->remainingSeconds,buffer);

    printf("=====================================================\n");
    printf("                    Timer\n");
    printf("=====================================================\n\n");

    printf("                 %s\n\n",buffer);

    if(state->running)
        printf("Status : Running\n\n");
    else
        printf("Status : Paused\n\n");

    printf("=====================================================\n");
    printf("[SPACE] Start / Pause\n");
    printf("[R] Reset\n");
    printf("[C] Clock\n");
    printf("[S] Stopwatch\n");
    printf("[Q] Quit\n");
    printf("=====================================================\n");
}

void renderStopwatchDashboard(ClockState* state)
{
    clearScreen();

    char buffer[32];

    formatTime(state->elapsedSeconds,buffer);

    printf("=====================================================\n");
    printf("                  Stopwatch\n");
    printf("=====================================================\n\n");

    printf("                 %s\n\n",buffer);

    if(state->running)
        printf("Status : Running\n\n");
    else
        printf("Status : Paused\n\n");

    printf("=====================================================\n");
    printf("[SPACE] Start / Pause\n");
    printf("[R] Reset\n");
    printf("[C] Clock\n");
    printf("[T] Timer\n");
    printf("[Q] Quit\n");
    printf("=====================================================\n");
}