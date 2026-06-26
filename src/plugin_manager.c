#include <stdio.h>
#include <string.h>
#include "../include/plugin_manager.h"

static Plugin* plugins[MAX_PLUGINS];
static int pluginCount = 0;

void registerPlugin(Plugin* plugin)
{
    if(pluginCount < MAX_PLUGINS)
        plugins[pluginCount++] = plugin;
}

Plugin* findPlugin(const char* name)
{
    for(int i = 0; i < pluginCount; i++)
    {
        if(strcmp(plugins[i]-> name, name) == 0)
            return plugins[i];
    }   

    return NULL;
}

void listPlugins()
{
    for(int i = 0; i < pluginCount; i++)
        printf("%s - %s\n", plugins[i]->name, plugins[i]->description);
}

