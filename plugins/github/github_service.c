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

int getRepo(const char* owner,const char* repo,char* response,size_t size)
{
    char url[512];
    snprintf(url,sizeof(url),"https://api.github.com/repos/%s/%s",owner,repo);
    return httpGet(url,response,size);
}

int getIssues(const char* owner,const char* repo,char* response,size_t size)
{
    char url[512];
    snprintf(url,sizeof(url),"https://api.github.com/repos/%s/%s/issues",owner,repo);
    return httpGet(url,response,size);
}

int getLatestRelease(const char* owner,const char* repo,char* response,size_t size)
{
    char url[512];
    snprintf(url,sizeof(url),"https://api.github.com/repos/%s/%s/releases/latest",owner,repo);
    return httpGet(url,response,size);
}

