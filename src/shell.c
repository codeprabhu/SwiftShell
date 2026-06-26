#include <stdio.h>
#include <string.h>

#include "../include/shell.h"
#include "../include/plugin_manager.h"
#include "../plugins/hello_plugin.h"

void startShell()
{
    char input[1024];
    
    registerPlugin(&helloPlugin);

    while(1)
    {
        printf("swift> ");
        if(fgets(input, sizeof(input), stdin) == NULL)
        break;

        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "exit") == 0)
            break;

        if(strcmp(input, "plugins") == 0)
        {
            listPlugins();
            continue;
        }

        Plugin* plugin = findPlugin(input);
        if(plugin)
        {
            plugin->execute(0,NULL);
            continue;
        }
        
        printf("Unknown Command: %s\n", input);

    }
    
}