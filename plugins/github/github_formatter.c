#include <stdio.h>

#include "github_formatter.h"

void printGitHubUser(
    GitHubUser* user
)
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