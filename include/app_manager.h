#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include "app.h"

void registerApp(App* app);
#define MAX_APPS 100

App* findApp(const char* name);
void listApps();

#endif