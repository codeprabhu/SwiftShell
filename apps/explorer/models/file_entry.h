#ifndef FILE_ENTRY_H
#define FILE_ENTRY_H

#define MAX_NAME 256

typedef struct
{
    char name[MAX_NAME];
    int isDirectory;
} FileEntry;

#endif