#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "github_service.h"
#include "../src/services/http/http.h"

int getUser(const char* username, char* response, size_t size)
{
    char url[512];
    snprintf(url, sizeof(url), "https://api.github.com/users/%s",username);
    return httpGet(url, response, size);
}