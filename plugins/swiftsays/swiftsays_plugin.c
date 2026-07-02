#include <stdio.h>
#include <string.h>

#include "swiftsays_plugin.h"
#include "services/swiftsays_service.h"
#include "formatter/formatter.h"

static void swiftsays_execute(int argc, char* argv[])
{
    const char* animal = NULL;
    const char* message = NULL;
    static char buffer[1024];
    buffer[0] = '\0';
    int start = 1;
    if(argc > 1 && strncmp(argv[1], "--", 2) == 0)
    {
        animal = argv[1] + 2;
        start = 2;
    }
    for(int i = start; i < argc; i++)
    {
        strcat(buffer, argv[i]);
        if(i != argc - 1)
            strcat(buffer, " ");
    }
    if(strlen(buffer) == 0)
        message = randomGreeting();
    else
        message = buffer;
    printSwiftsays(message,getAnimal(animal));
}

Plugin swiftsaysPlugin =
{
    .name = "swiftsays",
    .description = "SwiftShell mascot says things.",
    .execute = swiftsays_execute
};