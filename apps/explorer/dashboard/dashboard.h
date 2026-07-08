#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "../models/file_entry.h"

void renderFileDashboard(
    const char *path,
    FileEntry entries[],
    int count,
    int selected
);

#endif