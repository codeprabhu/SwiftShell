#include <stdio.h>
#include <string.h>
#include "dashboard.h"
#include "../plugins/ascii/ascii_service.h"

void clearedScreen()
{
    printf("\033[2J");
    printf("\033[H");
}

void formatTime(int seconds,char* buffer)
{
    sprintf(buffer,"%02d:%02d",seconds / 60,seconds % 60);
}

void drawProgressBar(int position,int length)
{
    const int width = 30;
    int filled = 0;
    if(length > 0)
        filled = position * width / length;
    printf("[");
    for(int i = 0; i < width; i++)
    {
        if(i < filled)
            printf("█");
        else
            printf("░");
    }
    printf("]");
}

void renderedDashboard(SpotifyTrack* track)
{
    clearedScreen();

    printf("=============================================================\n");
    printf("                      🎵 Swiftify 🎵\n");
    printf("=============================================================\n\n");

    int coverWidth = getTerminalWidth() / 3;

    if(coverWidth > 40)
        coverWidth = 40;
    if(coverWidth < 20)
        coverWidth = 20;
    asciiImage("/tmp/swiftshell_cover.jpg",60);

    printf("\n");
    printf("♪ %s\n\n", track->title);
    printf("Artist : %s\n", track->artist);
    printf("Album  : %s\n\n", track->album);

    if(strcmp(track->status, "Playing") == 0)
        printf("▶ Playing\n\n");
    else if(strcmp(track->status, "Paused") == 0)
        printf("⏸ Paused\n\n");
    else
        printf("■ Stopped\n\n");

    char current[16];
    char total[16];

    formatTime(track->position, current);
    formatTime(track->length, total);

    drawProgressBar(track->position,track->length);

    printf("\n");
    printf("%s / %s\n", current, total);
    printf("\n");
    printf("=============================================================\n");
    printf(" [P]      Play / Pause\n");
    printf(" [B]      Back\n");
    printf(" [N]      Next\n");
    printf(" [Q]      Quit\n");
    printf("=============================================================\n");
}