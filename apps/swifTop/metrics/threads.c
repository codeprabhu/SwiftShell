#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#include "threads.h"

int getThreadCount()
{
    DIR* proc = opendir("/proc");

    if(proc == NULL)
        return 0;

    struct dirent* entry;
    int totalThreads = 0;

    while((entry = readdir(proc)) != NULL)
    {
        if(!isdigit(entry->d_name[0]))
            continue;

        char path[256];

        sprintf(path,
                "/proc/%s/status",
                entry->d_name);

        FILE* fp = fopen(path, "r");

        if(fp == NULL)
            continue;

        char label[64];
        int threads;

        while(fscanf(fp, "%63s", label) != EOF)
        {
            if(strcmp(label, "Threads:") == 0)
            {
                fscanf(fp, "%d", &threads);
                totalThreads += threads;
                break;
            }

            fscanf(fp, "%*[^\n]\n");
        }

        fclose(fp);
    }

    closedir(proc);

    return totalThreads;
}