#ifndef GITHUB_USER_H
#define GITHUB_USER_H

typedef struct
{
    char login[128];
    char name[128];
    char bio[512];
    char location[128];

    int followers;
    int following;
    int publicRepos;

} GitHubUser;

#endif