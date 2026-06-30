#include <stdio.h>

#include "ascii_plugin.h"
#include "ascii_service.h"

static void ascii_execute(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage:\n""ascii <image>\n");
        return;
    }

    if(asciiImage(argv[1]) != 0)
        printf("Failed to generate ASCII art.\n");
}

Plugin asciiPlugin =
{
    .name = "ascii",
    .description = "Image to ASCII Art",
    .execute = ascii_execute
};