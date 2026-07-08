#ifndef FILE_SERVICE_H
#define FILE_SERVICE_H

#include "../models/file_entry.h"

int loadDirectory(
    const char *path,
    FileEntry entries[],
    int maxEntries
);

#endif