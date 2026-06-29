#include "metrics.h"
#include "cpu.h"
#include "memory.h"
#include "threads.h"
#include "disk.h"
#include "process.h"

void collectMetrics(SystemStats* stats)
{
    stats->cpuUsage = getCPUUsage();
    stats->ramUsage = getRAMUsage();
    stats->diskUsage = getDiskUsage();
    stats->processCount = getProcessCount();
    stats->threadCount = getThreadCount();
}