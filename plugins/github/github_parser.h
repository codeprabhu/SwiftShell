#ifndef GITHUB_PARSER_H
#define GITHUB_PARSER_H

#include "models/github_user.h"

int parseGitHubUser(
    const char* json,
    GitHubUser* user
);

#endif