#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spotify_service.h"

static void trimNewline(char* str)
{
    size_t len = strlen(str);
    if(len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void downloadAlbumCover(const char* url)
{
    char command[2048];

    snprintf(command, sizeof(command),
        "curl -L -s \"%s\" -o /tmp/swiftshell_cover.jpg", url);
    system("ls -l /tmp/swiftshell_cover.jpg");
    system(command);
}

static int runCommand(const char* command, char* output, size_t size)
{
    FILE* fp = popen(command, "r");
    if(fp == NULL)
        return -1;
    output[0] = '\0';
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), fp))
    {
        if(strlen(output) + strlen(buffer) + 1 >= size)
            break;
        strcat(output, buffer);
    }
    pclose(fp);
    return 0;
}

int getCurrentTrack(SpotifyTrack* track)
{
    char output[2048];
    if(runCommand(
        "sh -c 'playerctl metadata --format \"{{title}}\n{{artist}}\n{{album}}\n{{mpris:length}}\n{{mpris:artUrl}}\"; playerctl status; playerctl position'",
        output, sizeof(output)) != 0)
        return -1;
    if(strlen(output) == 0)
        return -1;
    
    char* line = strtok(output, "\n");
    if(line == NULL) return -1;
    strcpy(track->title, line);

    line = strtok(NULL, "\n");
    if(line == NULL) return -1;
    strcpy(track->artist, line);

    line = strtok(NULL, "\n");
    if(line == NULL) return -1;
    strcpy(track->album, line);

    line = strtok(NULL, "\n");
    if(line == NULL) return -1;
    track->length = atoi(line) / 1000000;

    line = strtok(NULL, "\n");
    if(line == NULL) return -1;
    strcpy(track->artUrl, line);

    line = strtok(NULL, "\n");
    if(line == NULL) return -1;
    strcpy(track->status, line);
    
    line = strtok(NULL, "\n");
    if(line == NULL)
        return -1;
    track->position = (int)atof(line);

    trimNewline(track->title);
    trimNewline(track->artist);
    trimNewline(track->album);
    trimNewline(track->status);
    trimNewline(track->artUrl);
    return 0;
}

void playPause()
{
    system("playerctl play-pause");
}

void nextTrack()
{
    system("playerctl next");
}

void previousTrack()
{
    system("playerctl previous");
}