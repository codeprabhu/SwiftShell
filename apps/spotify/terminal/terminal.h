#ifndef TERMINAL_H
#define TERMINAL_H

void enableRawMode();
void disableRawMode();

int keyPressed();
char readKey();

#endif