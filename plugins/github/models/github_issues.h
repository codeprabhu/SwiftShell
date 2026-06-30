#ifndef GITHUB_ISSUES_H
#define GITHUB_ISSUES_H

typedef struct
{
    int number;
    char title[256];
    char state[32];

} GitHubIssue;

#endif