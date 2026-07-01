#include <stdlib.h>

#include "ascii_resize.h"
#define ASPECT_RATIO 0.5f
Image resizeImage(Image* image,int newWidth)
{
    Image resized;
    float scale = (float)newWidth / image->width;
    resized.width = newWidth;
    resized.height = image->height * scale * ASPECT_RATIO;
    resized.channels = 3;
    resized.pixels =malloc(resized.width * resized.height *3);

    for(int y = 0; y < resized.height; y++)
    {
        for(int x = 0; x < resized.width; x++)
        {
            int srcX = x / scale;
            int srcY = y / (scale * ASPECT_RATIO);
            if(srcX >= image->width)
                srcX = image->width - 1;
            if(srcY >= image->height)
                srcY = image->height - 1;
            int src = (srcY * image->width + srcX) * 3;
            int dst = (y * resized.width + x) * 3;
            resized.pixels[dst] = image->pixels[src];
            resized.pixels[dst + 1] = image->pixels[src + 1];
            resized.pixels[dst + 2] = image->pixels[src + 2];
        }
    }
    return resized;
}

void freeResizedImage(Image* image)
{
    free(image->pixels);
}
    