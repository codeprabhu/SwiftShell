#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "http.h"

int httpGet(const char* url, char* response, size_t maxSize)
{
    char command[1024];
    snprintf(command, sizeof(command), "curl -s \"%s\"", url);
    FILE* fp = popen(command, "r");

    response[0] = '\0';

    if(fp == NULL)
        return -1;

    char buffer[512];
    while(fgets(buffer, sizeof(buffer), fp))
    {
        if(strlen(response) + strlen(buffer) + 1 >= maxSize)
            break;
        
        strcat(response, buffer);
    }
    pclose(fp);
    return 0;
}
