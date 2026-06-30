#include <stdio.h>

#include "ascii_image.h"

int main()
{
    Image img;

    if(loadImage(
        "cat.jpg",
        &img
    ) != 0)
    {
        return 1;
    }

    printf(
        "%d x %d\n",
        img.width,
        img.height
    );

    printf(
        "Channels: %d\n",
        img.channels
    );

    freeImage(&img);

    return 0;
}