#include <stdio.h>
#include <string.h>
#include "memory.h"

float getRAMUsage()
{
    FILE* fp = fopen("/proc/meminfo", "r");
    if(fp == NULL)
        return 0;

    unsigned long total = 0;
    unsigned long available = 0;

    char label[64];
    while(fscanf(fp, "%63s", label) != EOF)
    {
         if(strcmp(label, "MemTotal:") == 0)
        {
            fscanf(fp, "%lu", &total);
        }
        else if(strcmp(label, "MemAvailable:") == 0)
        {
            fscanf(fp, "%lu", &available);
        }

        fscanf(fp, "%*[^\n]\n");
    }

    fclose(fp);

    if(total == 0)
        return 0;

    return
        100.0f *
        (1.0f -
        ((float)available / total));
}