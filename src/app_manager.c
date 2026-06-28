#include <stdio.h>
#include <string.h>
#include "../include/app_manager.h"

static App* apps[MAX_APPS];
static int appCount = 0;

void registerApp(App* app)
{
    if(appCount < MAX_APPS)
        apps[appCount++] = app;
}

App* findApp(const char* name)
{
    for(int i = 0; i < appCount; i++)
    {
        if(strcmp(apps[i]-> name, name) == 0)
            return apps[i];
    }   

    return NULL;
}

void listApps()
{
    for(int i = 0; i < appCount; i++)
        printf("%s - %s\n", apps[i]->name, apps[i]->description);
}

