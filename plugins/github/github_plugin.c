#include <stdio.h>
#include <string.h>

#include "github_plugin.h"
#include "github_service.h"
#include "github_parser.h"
#include "github_formatter.h"


#define MAX_HTTP_SIZE (1024*1024)
static void handleRepo(int argc, char** argv)
{
    if(argc < 3)
    {
        printf("Usage:\n");
        printf("github repo owner/repository\n");
        return;
    }
    char owner[128];
    char repoName[128];
    if(sscanf(argv[2], "%127[^/]/%127s", owner, repoName) != 2)
    {
        printf("Format: owner/repository\n");
        return;
    }
    char response[MAX_HTTP_SIZE];
    GitHubRepo repo;
    if(getRepo(owner,
               repoName,
               response,
               sizeof(response)) != 0)
    {
        printf("Request failed.\n");
        return;
    }

    if(parseGitHubRepo(response,
                       &repo) != 0)
    {
        printf("Parse failed.\n");
        return;
    }
    printGitHubRepo(&repo);
}

static void handleUser(int argc, char** argv)
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

static void handleIssues(int argc,char** argv)
{
    if(argc < 3)
    {
        printf("Usage:\n""github issues owner/repo\n");
        return;
    }
    char owner[128];
    char repo[128];
    if(sscanf(argv[2],"%127[^/]/%127s",owner,repo) != 2)
    {
        printf("Invalid format.\n");
        return;
    }
    char response[MAX_HTTP_SIZE];
    GitHubIssue issues[10];
    if(getIssues(owner,repo,response,sizeof(response)) != 0)
    {
        printf("Request failed.\n");
        return;
    }
    int count = parseGitHubIssues(response,issues,10);
    if(count < 0)
    {
        printf("Parse failed.\n");
        return;
    }
    printGitHubIssues(issues,count);
}

static void handleReleases(int argc,char** argv)
{
    if(argc < 3)
    {
        printf("Usage:\n""github releases owner/repo\n");
        return;
    }
    char owner[128];
    char repo[128];
    if(sscanf(argv[2],"%127[^/]/%127s",owner,repo) != 2)
    {
        printf("Invalid format.\n");
        return;
    }
    char response[MAX_HTTP_SIZE];
    GitHubRelease release;
    if(getLatestRelease(owner,repo,response,sizeof(response)) != 0)
    {
        printf("Request failed.\n");
        return;
    }
    if(parseGitHubRelease(response,&release) != 0)
    {
        printf("Parse failed.\n");
        return;
    }
    printGitHubRelease(&release);
}

void github_execute(int argc, char** argv)
{
    if(strcmp(argv[1], "user") == 0)
        handleUser(argc, argv);
    else if(strcmp(argv[1], "repo") == 0)
        handleRepo(argc, argv);
    else if(strcmp(argv[1], "issues") == 0)
        handleIssues(argc,argv);
    else if(strcmp(argv[1], "releases") == 0)
        handleReleases(argc,argv);
    else
        printf("Unknown GitHub command.\n");
}

Plugin githubPlugin = 
    {
        .name = "github",
        .description = "GitHub CLI",
        .execute= github_execute
    };