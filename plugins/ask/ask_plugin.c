#include <stdio.h>
#include <string.h>

#include "../src/services/ai/ai.h"
#include "ask_plugin.h"

void ask_execute(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: ask <prompt>\n");
        return;
    }

    char prompt[2048] = "";

    for(int i = 1; i < argc; i++)
    {
        strcat(prompt, argv[i]);

        if(i != argc - 1)
            strcat(prompt, " ");
    }

    askAI(prompt);
}

Plugin askPlugin =
{
    .name = "ask",
    .description = "Local AI Assistant",
    .execute = ask_execute
};