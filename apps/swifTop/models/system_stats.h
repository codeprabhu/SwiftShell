#ifndef SYSTEM_STATS_H
#define SYSTEM_STATS_H

typedef struct 
{
    float cpuUsage;
    float ramUsage;
    float diskUsage;
    int processCount;
    int threadCount;
}SystemStats;

#endif