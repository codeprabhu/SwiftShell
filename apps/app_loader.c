#include "../include/app_manager.h"
#include "swifTop/swifTop_app.h"
#include "spotify/spotify_app.h"

void loadApps()
{
    registerApp(&swifTopApp);
    registerApp(&spotifyApp); 
}