#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../animals/animals.h"
#include "swiftsays_service.h"

const char* randomGreeting()
{
    static const char* greetings[] =
    {
        "Ready to build something awesome?",
        "Did you commit today?",
        "Talk is cheap. Show me the code.",
        "Coffee first. Debug later.",
        "One more plugin won't hurt...",
        "Segmentation faults build character.",
        "SwiftShell at your service!",
        "May your pointers never be NULL.",
        "Keep calm and code on.",
        "Hello from Swifty!"
    };
    srand(time(NULL));
    return greetings[rand() % 10];
}

const char* getAnimal(const char* name)
{
    if(name == NULL)
        return SWIFTY;
    if(strcmp(name,"cow") == 0)
        return COW;
    if(strcmp(name,"cat") == 0)
        return CAT;
    if(strcmp(name,"penguin") == 0)
        return PENGUIN;
    if(strcmp(name,"robot") == 0)
        return ROBOT;
    if(strcmp(name,"dragon") == 0)
        return DRAGON;
    return SWIFTY;
}