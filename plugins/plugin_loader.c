#include "../include/plugin_manager.h"

#include "hello/hello_plugin.h"
#include "notes/notes_plugin.h"
#include "ask/ask_plugin.h"
#include "github/github_plugin.h"
#include "weather/weather_plugin.h"

void loadPlugins()
{
    registerPlugin(&helloPlugin);
    registerPlugin(&notesPlugin);
    registerPlugin(&askPlugin);
    registerPlugin(&githubPlugin);
    registerPlugin(&weatherPlugin);
}