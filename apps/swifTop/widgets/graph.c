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

int drawLineGraph(
    History* history,
    float values[]
)
{
    float minimum = values[0];
    float maximum = values[0];
    {
        for(int i = 1; i < HISTORY_SIZE; i++)
        {
            if(values[i] < minimum)
                minimum = values[i];

            if(values[i] > maximum)
                maximum = values[i];
        }

        if(maximum - minimum < 1.0f)
            maximum = minimum + 1.0f;
    }

    for(int i = 0; i < HISTORY_SIZE; i++)
    {
        int index =
            (history->current + i) % HISTORY_SIZE;

        float value = values[index];

        float normalized;
        {
            normalized =
                (value - minimum) /
                (maximum - minimum);
        }

        if(normalized < 0)
            normalized = 0;

        if(normalized > 1)
            normalized = 1;

        int level = normalized * 7;

        printf("%s", blocks[level]);
    }

    return HISTORY_SIZE;
}