#include <stdio.h>
#include <string.h>

#include "formatter.h"

void printSwiftsays(const char* message,const char* animal)
{
    int len = strlen(message);
    printf(" ");
    for(int i = 0; i < len + 2; i++)
        printf("_");
    printf("\n");
    printf("< %s >\n",message);
    printf(" ");
    for(int i = 0; i < len + 2; i++)
        printf("-");
    printf("\n");
    printf("%s\n",animal);
}