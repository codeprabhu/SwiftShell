#ifndef GITHUB_RELEASE_H
#define GITHUB_RELEASE_H

typedef struct
{
    char tag[64];
    char name[256];
    char published[64];
    char body[4096];

} GitHubRelease;

#endif