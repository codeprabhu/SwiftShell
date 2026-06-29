#include <stdio.h>

#include "cpu.h"

static unsigned long previousIdle = 0;
static unsigned long previousTotal = 0;

float getCPUUsage()
{
    FILE* fp = fopen("/proc/stat", "r");

    if(fp == NULL)
        return 0;

    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;

    fscanf(fp,
           "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
           &user,
           &nice,
           &system,
           &idle,
           &iowait,
           &irq,
           &softirq,
           &steal);

    fclose(fp);

    unsigned long idleTime = idle + iowait;

    unsigned long nonIdle =
        user +
        nice +
        system +
        irq +
        softirq +
        steal;

    unsigned long total = idleTime + nonIdle;
    if(previousTotal == 0)
    {
        previousTotal = total;
        previousIdle = idleTime;
        return 0;
    }

    unsigned long totalDiff = total - previousTotal;
    unsigned long idleDiff = idleTime - previousIdle;

    previousTotal = total;
    previousIdle = idleTime;

    if(totalDiff == 0)
        return 0;

    float cpuUsage =
        100.0f * (1.0f - ((float)idleDiff / totalDiff));

    return cpuUsage;
}