#ifndef HISTORY_H
#define HISTORY_H

#include "../models/system_stats.h"
#define HISTORY_SIZE 60

typedef struct 
{
    float cpu[60];
    float ram[60];
    float disk[60];
    int current;

}History;

void initHistory(
    History* history
);

void addSample(
    History* history,
    SystemStats* stats
);

#endif