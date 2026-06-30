#ifndef GITHUB_FORMATTER_H
#define GITHUB_FORMATTER_H

#include "models/github_user.h"
#include "models/github_repo.h"
#include "models/github_issues.h"
#include "models/github_release.h"

void printGitHubUser(GitHubUser* user);
void printGitHubRepo(GitHubRepo* repo);
void printGitHubIssues(GitHubIssue issues[],int count);
void printGitHubRelease(GitHubRelease* release);\

#endif