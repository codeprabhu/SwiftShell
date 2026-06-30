#ifndef ASCII_RESIZE_H
#define ASCII_RESIZE_H

#include "ascii_image.h"

Image resizeImage(Image* image,int newWidth);
void freeResizedImage(Image* image);

#endif
