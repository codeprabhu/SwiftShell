#include <unistd.h>
#include <time.h>

#include "calendar_app.h"
#include "../spotify/terminal/terminal.h"
#include "dashboard/dashboard.h"

void startCalendar()
{
    enableRawMode();

    time_t now = time(NULL);

    struct tm current = *localtime(&now);

    int running = 1;

    while(running)
    {
        renderCalendar(&current);

        if(keyPressed())
        {
            char key = readKey();

            switch(key)
            {
                case 'q':
                case 'Q':
                    running = 0;
                    break;

                case 'n':
                case 'N':
                    current.tm_mon++;
                    mktime(&current);
                    break;

                case 'p':
                case 'P':
                    current.tm_mon--;
                    mktime(&current);
                    break;
            }
        }

        usleep(100000);
    }

    disableRawMode();
}

App calendarApp =
{
    .name = "calendar",
    .description = "Interactive calendar",
    .run = startCalendar
};