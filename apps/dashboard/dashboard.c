#include <stdio.h>
#include <unistd.h>

#include "dashboard.h"
#include "../swifTop/models/system_stats.h"
#include "../swifTop/metrics/metrics.h"
#include "../swifTop/history/history.h"
#include "../swifTop/widgets/graph.h"

void renderStats(SystemStats* stats, History* history)
{
    printf("CPU       : %.1f%%\n", stats->cpuUsage);
    drawLineGraph(history->cpu, HISTORY_SIZE, 100);
    printf("\n");

    printf("RAM       : %.1f%%\n", stats->ramUsage);
    drawLineGraph(history->ram, HISTORY_SIZE, 100);
    printf("\n");

    printf("Disk      : %.1f%%\n", stats->diskUsage);
    drawLineGraph(history->disk, HISTORY_SIZE, 100);
    printf("\n");

    printf("Processes : %d\n", stats->processCount);
    printf("Threads   : %d\n", stats->threadCount);
}

void renderHeader()
{
    printf("====================================\n");
    printf("          SwiftTop v1.0\n");
    printf("====================================\n\n");
    
}

void renderFooter()
{
    printf("\nPress q to quit\n");
}

void renderFrame(SystemStats* stats, History* history)
{
    printf("\033[2J");
    printf("\033[H");
    renderHeader();

    renderStats(stats, history);

    renderFooter();
}


void startDashboard()
{
    SystemStats stats;
    History history;
    
    initHistory(&history);
    while (1)
    {
        collectMetrics(&stats);
        addSample(&history, &stats);
        renderFrame(&stats, &history);

        sleep(1);
    }
}