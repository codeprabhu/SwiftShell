#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../include/executor.h"

void executeExternal(ParsedCommand* cmd)
{
    pid_t pid = fork();

    if(pid == 0)
    {
        execvp(cmd->argv[0], cmd->argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else if(pid>0)
        wait(NULL);
    else
        perror("fork");
}