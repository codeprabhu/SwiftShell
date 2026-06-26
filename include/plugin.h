#ifndef PLUGIN_H
#define PLUGIN_H

typedef struct Plugin
{
    const char* name;
    const char* description;

    void (*execute)(int argc, char** argv);

}Plugin;

#endif