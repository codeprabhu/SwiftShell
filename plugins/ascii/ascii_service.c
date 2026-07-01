#include <stdlib.h>
#include "ascii_resize.h"
#include "ascii_service.h"
#include "ascii_image.h"
#include "ascii_convert.h"
#include "ascii_formatter.h"
#include <sys/ioctl.h>
#include <unistd.h>

int getTerminalWidth()
{
    struct winsize ws;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&ws);
    return ws.ws_col;
}
int asciiImage(const char* filename, int width)
{
    Image image;
    if(loadImage(filename, &image) != 0)
        return -1;
    if(width <= 0)
        width = getTerminalWidth() - 4;
    Image resized = {0};
    resized = resizeImage(&image,width);
    char* ascii = convertImageToAscii(&resized);
    if(ascii == NULL)
    {
        freeResizedImage(&resized);
        freeImage(&image);
        return -1;
    }
    printAsciiImage(&resized,ascii);
    free(ascii);
    freeResizedImage(&resized);
    freeImage(&image);
    return 0;
}