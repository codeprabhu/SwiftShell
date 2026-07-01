#ifndef SPOTIFY_TRACK_H
#define SPOTIFY_TRACK_H

typedef struct
{
    char title[256];
    char artist[256];
    char album[256];
    char status[32];
    int length;
    int position;
    char artUrl[1024];
} SpotifyTrack;

#endif