#include "metrics.h"

void collectMetrics(SystemStats* stats)
{
    stats->cpuUsage = 42;
    stats->ramUsage = 63;

    stats->diskUsage = 31;

    stats->processCount = 286;

    stats->threadCount = 1843;
}