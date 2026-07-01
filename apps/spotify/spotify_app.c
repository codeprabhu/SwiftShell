#include <unistd.h>
#include <string.h>
#include "terminal/terminal.h"
#include "spotify_app.h"
#include "../include/app.h"
#include "dashboard/dashboard.h"
#include "services/spotify_service.h"
#include "terminal/terminal.h"
#include <stdio.h>

void startSpotify()
{
    SpotifyTrack track;
    char lastSong[256] = "";
    enableRawMode();
    int running = 1;
    while(running)
    {

        getCurrentTrack(&track);
        if(strcmp(lastSong, track.title) != 0)
        {
            strcpy(lastSong, track.title);
            downloadAlbumCover(track.artUrl);
        }
        renderedDashboard(&track);
        if(keyPressed())
        {
            char key = readKey();
            switch(key)
            {
                case 'q':
                case 'Q':
                    running = 0;
                    break;

                case 'p':
                case 'P':
                    playPause();
                    break;

                case 'n':
                case 'N':
                    nextTrack();
                    break;

                case 'b':
                case 'B':
                    previousTrack();
                    break;
            }
        }
        usleep(100000);
    }
    disableRawMode();
}

App spotifyApp = {
    .name = "spotify",
    .description = "Interactive Spotify client",
    .run = startSpotify
};