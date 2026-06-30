#ifndef GITHUB_REPO_H
#define GITHUB_REPO_H

typedef struct
{
    char name[128];
    char owner[128];
    char description[512];
    char language[128];
    char license[128];
    char homepage[256];

    int stars;
    int forks;
    int watchers;
    int openIssues;

} GitHubRepo;

#endif