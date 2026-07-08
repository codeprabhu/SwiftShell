#define _DEFAULT_SOURCE
#include <dirent.h>
#include <string.h>

#include "file_service.h"

int loadDirectory(
    const char *path,
    FileEntry entries[],
    int maxEntries
)
{
    DIR *dir = opendir(path);

    if(dir == NULL)
        return -1;

    struct dirent *entry;

    int count = 0;

    while(
        (entry = readdir(dir)) != NULL
        &&
        count < maxEntries
    )
    {
        strcpy(
            entries[count].name,
            entry->d_name
        );

        entries[count].isDirectory =
            (entry->d_type == DT_DIR);

        count++;
    }

    closedir(dir);

    return count;
}