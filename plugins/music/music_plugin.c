#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#include "music_plugin.h"
#include "dashboard/dashboard.h"
#include "../apps/spotify/terminal/terminal.h"

static void music_execute(
    int argc,
    char* argv[]
)
{
    if(argc < 2)
    {
        printf("Usage: music <file>\n");
        return;
    }

    pid_t pid = fork();

    if(pid == 0)
    {
        execlp(
            "mpv",
            "mpv",
            "--no-video",
            "--really-quiet",
            "--no-terminal",
            argv[1],
            NULL
        );

        exit(1);
    }

    int running = 1;
    while(running)
    {
        renderMusicDashboard(argv[1], "Playing");

        char c = getchar();

        switch(c)
        {
            case 'q':
            case 'Q':
                kill(pid,SIGTERM);
                running = 0;
                break;

            case 'p':
            case 'P':
                kill(pid,SIGSTOP);
                break;

            case 'r':
            case 'R':
                kill(pid,SIGCONT);
                break;
        }
    }
}

Plugin musicPlugin =
{
    .name = "music",
    .description = "Audio player",
    .execute = music_execute
};