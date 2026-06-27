#include <stdlib.h>
#include <string.h>

#include "../include/parser.h"

#define MAX_ARGS 64

ParsedCommand parseInput(char* input)
{
    ParsedCommand cmd;
    cmd.argc = 0;
    cmd.argv = malloc(sizeof(char*) * MAX_ARGS);
    char* token = strtok(input, " ");

    while( token != NULL)
    {
        cmd.argv[cmd.argc++] = strdup(token);
        token = strtok(NULL, " ");
    }
    return cmd;
}

void freeParsedCommand(ParsedCommand* cmd)
{
    for(int i = 0; i < cmd->argc; i++)
        free(cmd->argv[i]);
    
    free(cmd->argv);
}