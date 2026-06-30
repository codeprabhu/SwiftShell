#include <stdlib.h>

#include "ascii_convert.h"

static const char* RAMP =
"$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,^`'. ";

char brightnessToAscii(float brightness)
{
    int length = 0;
    while(RAMP[length] != '\0')
        length++;
    int index = brightness * (length - 1);
    if(index < 0)
        index = 0;
    if(index >= length)
        index = length - 1;
    return RAMP[index];
}

char* convertImageToAscii(Image* image)
{
    int total = image->width *image->height;
    char* ascii = malloc(total + 1);

    if(ascii == NULL)
        return NULL;
    for(int i = 0; i < total; i++)
    {
        int pixel = i * 3;
        unsigned char r = image->pixels[pixel];
        unsigned char g = image->pixels[pixel + 1];
        unsigned char b = image->pixels[pixel + 2];
        float brightness =
            (
                0.299f * r +
                0.587f * g +
                0.114f * b
            ) / 255.0f;

        ascii[i] = brightnessToAscii(1.0f - brightness);
    }
    ascii[total] = '\0';
    return ascii;
}