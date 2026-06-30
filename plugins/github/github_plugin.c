#include <stdio.h>
#include <string.h>

#include "github_plugin.h"
#include "github_service.h"
#include "github_parser.h"
#include "github_formatter.h"
#include "models/github_user.h"

#define MAX_HTTP_SIZE 32768

void github_execute(int argc, char** argv)
{
    if(argc < 3)
    {
        printf("Usage:\n");
        printf("github user <username>\n");
        return;
    }

    if(strcmp(argv[1], "user") == 0)
    {
        char response[MAX_HTTP_SIZE];
        GitHubUser user;

        if(getUser(argv[2],response,sizeof(response)) != 0)
        {
            printf("Request failed.\n");
            return;
        }
        if(parseGitHubUser(response,&user) != 0)
        {
            printf("Failed to parse JSON.\n");
            return;
        }

        printGitHubUser(&user);
    }
    else
        printf("Unknown github command.\n");
}
Plugin githubPlugin = 
    {
        .name = "github",
        .description = "GitHub CLI",
        .execute= github_execute
    };