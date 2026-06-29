#include <dirent.h>
#include <ctype.h>
#include <stdio.h>

#include "process.h"

int getProcessCount()
{
    DIR* proc = opendir("/proc");

    if(proc == NULL)
        return 0;

    struct dirent* entry;
    int count = 0;

    while((entry = readdir(proc)) != NULL)
    {
        if(isdigit(entry->d_name[0]))
            count++;
    }

    closedir(proc);

    return count;
}