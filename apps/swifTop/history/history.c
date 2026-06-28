#include "history.h"

void initHistory(History* history)
{
     history->current = 0;
    for(int i = 0; i < HISTORY_SIZE; i++)
    {
        history->cpu[i] = 0;
        history->ram[i] = 0;
        history->disk[i] = 0;
    }
}

void addSample(
    History* history,
    SystemStats* stats
)
{
    history->cpu[history->current] = stats->cpuUsage;
    history->ram[history->current] = stats->ramUsage;
    history->disk[history->current] = stats->diskUsage;
    history->current++;

    if(history->current >= HISTORY_SIZE)
        history->current = 0;
}