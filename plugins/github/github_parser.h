#ifndef GITHUB_PARSER_H
#define GITHUB_PARSER_H

#include "models/github_user.h"
#include "models/github_repo.h"
#include "models/github_issues.h"
#include "models/github_release.h"

int parseGitHubUser(
    const char* json,
    GitHubUser* user
);

int parseGitHubRepo(
    const char* json,
    GitHubRepo* repo
);

int parseGitHubIssues(
    const char* json,
    GitHubIssue issues[],
    int maxIssues
);

int parseGitHubRelease(
    const char* json,
    GitHubRelease* release
);

#endif