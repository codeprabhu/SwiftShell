#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include "ascii_image.h"

int loadImage(const char* filename,Image* image)
{
    image->pixels =
        stbi_load(
            filename,
            &image->width,
            &image->height,
            &image->channels,
            3
        );
    image->channels = 3;
    if(image->pixels == NULL)
    {
        printf("Failed to load image. %s\n", stbi_failure_reason());
        return -1;
    }
    return 0;
}

void freeImage(Image* image)
{
    if(image->pixels)
    {
        stbi_image_free(image->pixels);
        image->pixels = NULL;
    }
}