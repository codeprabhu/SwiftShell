#ifndef ASCII_CONVERT_H
#define ASCII_CONVERT_H

#include "ascii_image.h"

char brightnessToAscii(float brightness);

char* convertImageToAscii(Image* image);

#endif