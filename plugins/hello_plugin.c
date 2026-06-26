#include <stdio.h>
#include "hello_plugin.h"
#include "../include/plugin.h"

void hello_execute(int argc, char** argv)
{
    printf("Hello from SwiftShell Plugin Sysetm\n");
}

Plugin helloPlugin = {
    .name = "hello",
    .description = "Test Plugin",
    .execute = hello_execute
};
