#include <stdio.h>
#include <string.h>

#include "../include/dispatcher.h"
#include "../include/plugin_manager.h"
#include "../include/app_manager.h"
#include "../include/executor.h"

void dispatchCommand(ParsedCommand* cmd)
{
    if(cmd-> argc == 0)
        return;

    if(strcmp(cmd->argv[0], "plugins") == 0)
    {
        listPlugins();
        return;
    }

    Plugin* plugin = findPlugin(cmd->argv[0]);
    if(plugin)
    {
        plugin->execute(cmd->argc, cmd->argv);
        return;
    }

    App* app = findApp(cmd->argv[0]);
    if(app)
    {
        app-> run();
        return;
    }
    
    executeExternal(cmd);
}