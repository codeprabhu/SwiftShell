#include "../include/plugin_manager.h"

#include "hello_plugin.h"
#include "notes_plugin.h"

void loadPlugins()
{
    registerPlugin(&helloPlugin);
    registerPlugin(&notesPlugin);
}