#include <stdio.h>

#include "ascii_formatter.h"

void printAsciiImage(Image* image,char* ascii)
{
    int index = 0;
    for(int y = 0; y < image->height; y++)
    {
        for(int x = 0; x < image->width; x++)
        {
            int pixel = index * 3;
            unsigned char r = image->pixels[pixel];
            unsigned char g = image->pixels[pixel + 1];
            unsigned char b = image->pixels[pixel + 2];

            printf("\033[38;2;%d;%d;%dm%c",r,g,b,ascii[index]);
            index++;
        }
        printf("\033[0m\n");
    }
    printf("\033[0m");
}