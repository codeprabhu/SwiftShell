#include <stdio.h>

#include "dashboard.h"

static void clearScreen()
{
    printf("\033[2J");
    printf("\033[H");
}

void renderFileDashboard(
    const char *path,
    FileEntry entries[],
    int count,
    int selected
)
{
    clearScreen();

    printf(
        "=========================================\n"
    );

    printf(
        "           Swift Explorer\n"
    );

    printf(
        "=========================================\n\n"
    );

    printf(
        "Path: %s\n\n",
        path
    );

    for(int i = 0; i < count; i++)
    {
        if(i == selected)
            printf("> ");
        else
            printf("  ");

        if(entries[i].isDirectory)
            printf("[DIR] ");
        else
            printf("      ");

        printf(
            "%s\n",
            entries[i].name
        );
    }

    printf("\n");

    printf(
        "W/S Navigate\n"
    );

    printf(
        "Enter Open Directory\n"
    );

    printf(
        "Backspace Parent Directory\n"
    );

    printf(
        "Q Quit\n"
    );
}