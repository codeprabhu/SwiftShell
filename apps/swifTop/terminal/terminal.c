#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "terminal.h"

static struct termios original;

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &original);

    struct termios raw = original;

    raw.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO,
              TCSAFLUSH,
              &raw);
}

void disableRawMode()
{
    tcsetattr(STDIN_FILENO,
              TCSAFLUSH,
              &original);
}

int keyPressed()
{
    int oldFlags =
        fcntl(STDIN_FILENO,
              F_GETFL);

    fcntl(STDIN_FILENO,
          F_SETFL,
          oldFlags | O_NONBLOCK);

    int c = getchar();

    fcntl(STDIN_FILENO,
          F_SETFL,
          oldFlags);

    if(c != EOF)
    {
        ungetc(c, stdin);
        return 1;
    }

    return 0;
}

char readKey()
{
    return getchar();
}