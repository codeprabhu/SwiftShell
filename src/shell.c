#include <stdio.h>
#include <string.h>

#include "../include/shell.h"
#include "../include/plugin_manager.h"
#include "../include/parser.h"
#include "../include/dispatcher.h"

#include "../plugins/plugin_loader.h"
void startShell()
{
    char input[1024];
    
    loadPlugins();

    while(1)
    {
        printf("swift> ");
        if(fgets(input, sizeof(input), stdin) == NULL)
        break;

        input[strcspn(input, "\n")] = '\0';

        ParsedCommand cmd = parseInput(input);
        
        dispatchCommand(&cmd);
        
        freeParsedCommand(&cmd);

    }
    
}