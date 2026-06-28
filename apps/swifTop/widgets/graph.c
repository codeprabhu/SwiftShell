#include <stdio.h>

#include "graph.h"

static const char* blocks[] =
{
    "▁",
    "▂",
    "▃",
    "▄",
    "▅",
    "▆",
    "▇",
    "█"
};

void drawLineGraph(
    float history[],
    int size,
    float maxValue
)
{
    for(int i = 0; i < size; i++)
    {
        int level =
            (history[i] / maxValue) * 7;

        if(level < 0)
            level = 0;

        if(level > 7)
            level = 7;

        printf("%s", blocks[level]);
    }

    printf("\n");
}