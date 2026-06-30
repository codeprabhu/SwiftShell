#ifndef GITHUB_SERVICE_H
#define GITHUB_SERVICE_H

#include <string.h>

int getUser(const char* username, char* response, size_t size);
int getRepo(const char* owner,const char* repo,char* response,size_t size);
int getIssues(const char* owner,const char* repo,char* response,size_t size);
int getLatestRelease(const char* owner,const char* repo,char* response,size_t size);

#endif