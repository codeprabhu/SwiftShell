#ifndef APP_H
#define APP_H

typedef struct
{
    char* name;
    char* description;
    void (*run)();
}App;

#endif