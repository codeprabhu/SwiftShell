#include <stdio.h>

#include "github_formatter.h"

void printGitHubUser(GitHubUser* user)
{
    printf("\n");
    printf("GitHub User\n");
    printf("----------------------------\n");
    printf("Name        : %s\n", user->name);
    printf("Username    : %s\n", user->login);
    printf("Followers   : %d\n", user->followers);
    printf("Following   : %d\n", user->following);
    printf("Repositories: %d\n", user->publicRepos);
    printf("Location    : %s\n", user->location);
    printf("Bio         : %s\n", user->bio);
    printf("\n");
}

void printGitHubRepo(GitHubRepo* repo)
{
    printf("\n");
    printf("Repository\n");
    printf("----------------------------\n");
    printf("Name         : %s\n",repo->name);
    printf("Owner        : %s\n",repo->owner);
    printf("Description  : %s\n",repo->description);
    printf("Language     : %s\n",repo->language);
    printf("Stars        : %d\n",repo->stars);
    printf("Forks        : %d\n",repo->forks);
    printf("Watchers     : %d\n",repo->watchers);
    printf("Open Issues  : %d\n",repo->openIssues);
    printf("License      : %s\n",repo->license);
    printf("Homepage     : %s\n",repo->homepage);
    printf("\n");
}

void printGitHubIssues(GitHubIssue issues[],int count)
{
    printf("\n");
    printf("Open Issues\n");
    printf("-----------------------------\n");
    for(int i = 0; i < count; i++)
    {
        printf("#%-8d %s\n",
               issues[i].number,
               issues[i].title);
    }
    printf("\n");
}

void printGitHubRelease(GitHubRelease* release)
{
    printf("\n");
    printf("Latest Release\n");
    printf("----------------------------\n");
    printf("Version     : %s\n",release->tag);
    printf("Name        : %s\n",release->name);
    printf("Published   : %s\n",release->published);
    printf("\nRelease Notes\n");
    printf("----------------------------\n");
    printf("%.500s\n",release->body);
    printf("\n");
}