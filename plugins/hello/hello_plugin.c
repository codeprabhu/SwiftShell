#include <stdio.h>
#include "hello_plugin.h"
#include "../include/plugin.h"

void hello_execute(int argc, char** argv)
{
    if(argc == 1)
    {
        printf("Hello from SwiftShell\n");
        return;
    }
    printf("Hello ");
    for(int i = 1; i < argc; i++)
        printf("%s ", argv[i]);
    printf("\n");
}

Plugin helloPlugin = {
    .name = "hello",
    .description = "Test Plugin",
    .execute = hello_execute
};
