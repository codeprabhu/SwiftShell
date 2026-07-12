#include <stdio.h>

#include "dashboard.h"

void renderMusicDashboard(
    const char* filename,
    const char* status
)
{
    printf("\033[2J");
    printf("\033[H");

    printf("=====================================\n");
    printf("          SwiftMusic\n");
    printf("=====================================\n\n");

    printf("Song    : %s\n", filename);
    printf("Status  : %s\n\n", status);

    printf("[P] Pause\n");
    printf("[R] Resume\n");
    printf("[Q] Quit\n");

    printf("\n=====================================\n");

    fflush(stdout);
}