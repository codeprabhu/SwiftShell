#define _DEFAULT_SOURCE
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "explorer_app.h"

#include "dashboard/dashboard.h"
#include "services/file_service.h"

#include "../spotify/terminal/terminal.h"

#define MAX_FILES 1024

void startExplorer()
{
    enableRawMode();

    char currentPath[PATH_MAX];

    getcwd(
        currentPath,
        sizeof(currentPath)
    );

    FileEntry entries[MAX_FILES];

    int selected = 0;

    int running = 1;

    while(running)
    {
        int count =
            loadDirectory(
                currentPath,
                entries,
                MAX_FILES
            );

        renderFileDashboard(
            currentPath,
            entries,
            count,
            selected
        );

        if(keyPressed())
        {
            char key = readKey();

            switch(key)
            {
                case 'q':
                case 'Q':
                    running = 0;
                    break;

                case 'w':
                case 'W':
                    if(selected > 0)
                        selected--;
                    break;

                case 's':
                case 'S':
                    if(selected < count - 1)
                        selected++;
                    break;

                case '\n':
                case 13:
                {
                    if(entries[selected].isDirectory)
                    {
                        char newPath[PATH_MAX];
                        snprintf(
                            newPath,sizeof(newPath),"%s/%s",
                            currentPath,entries[selected].name);
                        strcpy(currentPath, newPath);
                        selected = 0;
                    }

                    break;
                }

                case 127:
                case 8:
                {
                    char *lastSlash = strrchr(currentPath, '/');

                    if(lastSlash != NULL &&
                    lastSlash != currentPath)
                        *lastSlash = '\0';

                    selected = 0;
                    break;
                }
            }
        }

        usleep(100000);
    }

    disableRawMode();
}

App explorerApp =
{
    .name = "explorer",
    .description = "Terminal file explorer",
    .run = startExplorer
};