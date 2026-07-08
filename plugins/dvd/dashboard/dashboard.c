#include <stdio.h>

#include "dashboard.h"

static const char* DVD_LOGO[] =
{
    "██████╗ ██╗   ██╗██████╗ ",
    "██╔══██╗██║   ██║██╔══██╗",
    "██║  ██║██║   ██║██║  ██║",
    "██║  ██║╚██╗ ██╔╝██║  ██║",
    "██████╔╝ ╚████╔╝ ██████╔╝",
    "╚═════╝   ╚═══╝  ╚═════╝ "
};

#define DVD_HEIGHT 6

void renderDVD(
    int x,
    int y,
    int color,
    int cornerHits
)
{
    printf("\033[2J");
    printf("\033[H");

    for(int i = 0; i < DVD_HEIGHT; i++)
    {
        printf(
            "\033[%d;%dH\033[%dm%s\033[0m",
            y + i,
            x,
            color,
            DVD_LOGO[i]
        );
    }

    printf(
        "\033[1;1H"
        "Corner Hits: %d",
        cornerHits
    );

    printf(
        "\033[2;1H"
        "Press Q to quit"
    );

    fflush(stdout);
}