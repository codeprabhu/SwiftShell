#ifndef ASCII_IMAGE_H
#define ASCII_IMAGE_H

typedef struct
{
    unsigned char* pixels;
    int width;
    int height;
    int channels;
} Image;

int loadImage(const char* filename,Image* image);
void freeImage(Image* image);

#endif