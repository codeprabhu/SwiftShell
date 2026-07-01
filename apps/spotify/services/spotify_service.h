#ifndef SPOTIFY_SERVICE_H
#define SPOTIFY_SERVICE_H

#include "../models/spotify_track.h"

int getCurrentTrack(SpotifyTrack* track);
void downloadAlbumCover(const char* url);
void playPause();
void nextTrack();
void previousTrack();

#endif