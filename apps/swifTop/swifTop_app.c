#include <stdio.h>
#include "../include/app.h"
#include "swifTop_app.h"
#include "dashboard/dashboard.h"
void runSwiftTop()
{
    startDashboard();
}

App swifTopApp = {
    .name = "swifTop",
    .description = "Task Manager",
    .run = runSwiftTop
};
