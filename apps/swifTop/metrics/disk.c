#include <sys/statvfs.h>

#include "disk.h"

float getDiskUsage()
{
    struct statvfs stat;

    if(statvfs("/", &stat) != 0)
        return 0;

    unsigned long total =
        stat.f_blocks * stat.f_frsize;

    unsigned long available =
        stat.f_bavail * stat.f_frsize;

    unsigned long used =
        total - available;

    return
        ((float)used / total) * 100.0f;
}