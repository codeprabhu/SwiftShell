#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include "plugin.h"
#define MAX_PLUGINS 100

void registerPlugin(Plugin* plugin);
Plugin* findPlugin(const char* name);

void listPlugins();
#endif