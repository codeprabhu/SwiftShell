#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ai.h"

void askAI(const char* prompt)
{
    char command[4096];

    snprintf(command,
             sizeof(command),
             "ollama run llama3:8b \"%s\"",
             prompt);
    printf("Thinking...\n\n");
    FILE* fp = popen(command, "r");

    if(fp == NULL)
    {
        printf("Failed to start Ollama.\n");
        return;
    }

    char buffer[512];

    while(fgets(buffer, sizeof(buffer), fp))
    {
        printf("%s", buffer);
        fflush(stdout);
    }

    pclose(fp);
}