#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <sys/ioctl.h>

#include "dvd_plugin.h"
#include "dashboard/dashboard.h"

#include "../apps/spotify/terminal/terminal.h"

#define DVD_WIDTH 24
#define DVD_HEIGHT 6

static void dvd_execute(int argc, char** argv)
{
    enableRawMode();
    srand(time(NULL));
    struct winsize ws;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&ws);
    int width = ws.ws_col;
    int height = ws.ws_row;
    int x = width / 2;
    int y = height / 2;
    int dx = 1;
    int dy = 1;
    int color = 31;
    int cornerHits = 0;
    int running = 1;
    while(running)
    {
        renderDVD(x,y,color,cornerHits);
        x += dx;
        y += dy;
        int bouncedX = 0;
        int bouncedY = 0;
        if(x <= 1 ||x >= width - DVD_WIDTH)
        {
            dx *= -1;
            bouncedX = 1;
        }
        if(y <= 3 ||y >= height - DVD_HEIGHT)
        {
            dy *= -1;
            bouncedY = 1;
        }
        if(
            bouncedX || bouncedY
        )
            color = 31 + rand() % 6;

        if(bouncedX && bouncedY)
        {
            cornerHits++;
            printf("\a");
        }

        if(keyPressed())
        {
            char key = readKey();

            if(
                key == 'q' ||
                key == 'Q'
            )
            {
                running = 0;
            }
        }

        usleep(50000);
    }
    disableRawMode();
    printf("\033[2J");
    printf("\033[H");
}

Plugin dvdPlugin =
{
    .name = "dvd",
    .description = "Bouncing DVD logo",
    .execute = dvd_execute
};