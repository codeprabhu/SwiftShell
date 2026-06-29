#include <stdio.h>
#include <unistd.h>

#include "dashboard.h"

#include "../swifTop/models/system_stats.h"
#include "../swifTop/metrics/metrics.h"
#include "../swifTop/history/history.h"
#include "../swifTop/widgets/graph.h"
#include "../swifTop/terminal/terminal.h"

#define GRAPH_WIDTH HISTORY_SIZE
#define WIDTH (GRAPH_WIDTH + 3)
#define VERTICAL "│"

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

void clearScreen()
{
    printf("\033[2J");
    printf("\033[H");
}

void drawHorizontal(const char* left, const char* middle, const char* right)
{
    printf("%s", left);
    for(int i = 0; i < WIDTH; i++)
        printf("%s", middle);
    printf("%s", right);
    putchar('\n');
}

void drawEmptyLine()
{
    printf("│%-*s│\n", WIDTH, "");
}

void renderHeader()
{
    drawHorizontal("┌", "─", "┐");
    printf("│%*sSwiftTop v1.0%*s│\n",
       (WIDTH - 13) / 2,
       "",
       WIDTH - ((WIDTH - 13) / 2) - 13,
       "");
    drawHorizontal("├", "─", "┤");
}

void renderCPUWidget(SystemStats* stats, History* history)
{
    printf("│ CPU Usage : %5.1f%%%44s│\n", stats->cpuUsage, "");
    printf("│ ");
    printf(GREEN);
    drawLineGraph(history, history->cpu);
    printf(RESET);
    printf("  │\n");
}

void renderRAMWidget(SystemStats* stats, History* history)
{
    printf("│ RAM Usage : %5.1f%%%44s│\n", stats->ramUsage, "");
    printf("│ ");
    printf(YELLOW);
    drawLineGraph(history, history->ram);
    printf(RESET);
    printf("  │\n");
}

void renderDiskWidget(SystemStats* stats, History* history)
{
    printf("│ Disk Usage: %5.1f%%%44s│\n",stats->diskUsage, "");
    printf("│ ");
    printf(CYAN);
    drawLineGraph(history, history->disk);
    printf(RESET);
    printf("  │\n");
}

void renderSystemWidget(SystemStats* stats)
{
    printf("│ Processes :  %-49d│\n",stats->processCount);
    printf("│ Threads   :  %-49d│\n",stats->threadCount);
}

void renderFooter()
{
    drawHorizontal("├", "─", "┤");
    printf("│ Press [Q] to Quit%-*s│\n",
       WIDTH - 18,
       "");
    drawHorizontal("└", "─", "┘");
}

void renderDashboard(SystemStats* stats, History* history)
{
    clearScreen();
    renderHeader();
    renderCPUWidget(stats, history);
    drawEmptyLine();
    renderRAMWidget(stats, history);
    drawEmptyLine();
    renderDiskWidget(stats, history);
    drawEmptyLine();
    renderSystemWidget(stats);
    renderFooter();
}

void startDashboard()
{
    enableRawMode();
    SystemStats stats;
    History history;

    initHistory(&history);

    int running = 1;
    while(running)
    {
        if(keyPressed())
        {
            char key = readKey();
            if(key == 'q' || key == 'Q')
                running = 0;
        }

        collectMetrics(&stats);
        addSample(&history, &stats);
        renderDashboard(&stats, &history);
        sleep(1);
    }

    disableRawMode();
}