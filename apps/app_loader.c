#include "../include/app_manager.h"
#include "swifTop/swifTop_app.h"
#include "spotify/spotify_app.h"
#include "clock/clock_app.h"
#include "calendar/calendar_app.h"
#include "explorer/explorer_app.h"

void loadApps()
{
    registerApp(&swifTopApp);
    registerApp(&spotifyApp); 
    registerApp(&clockApp);
    registerApp(&calendarApp);
    registerApp(&explorerApp);
}