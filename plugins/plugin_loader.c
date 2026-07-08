#include "../include/plugin_manager.h"

#include "swiftsays/swiftsays_plugin.h"
#include "notes/notes_plugin.h"
#include "ask/ask_plugin.h"
#include "github/github_plugin.h"
#include "weather/weather_plugin.h"
#include "ascii/ascii_plugin.h"
#include "dvd/dvd_plugin.h"

void loadPlugins()
{
    registerPlugin(&swiftsaysPlugin);
    registerPlugin(&notesPlugin);
    registerPlugin(&askPlugin);
    registerPlugin(&githubPlugin);
    registerPlugin(&weatherPlugin);
    registerPlugin(&asciiPlugin);
    registerPlugin(&dvdPlugin);
}