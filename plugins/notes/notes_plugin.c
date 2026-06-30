#include <stdio.h>
#include <string.h>

#include "notes_plugin.h"
void addNote(int argc, char** argv)
{
    FILE* file = fopen("data/notes.txt", "a");

    if(file == NULL)
    {
        printf("Failed to open notes file\n");
        return;
    }
    for(int i = 2; i < argc; i++)
        fprintf(file, "%s ", argv[i]);

    fprintf(file, "\n");
    fclose(file);
    printf("Note added successfully\n");
}
void clearNotes()
{
    FILE* file = fopen("data/notes.txt", "w");
    if(file == NULL)
    {
        printf("Failed to clear notes\n");
        return;
    }

    fclose(file);
    printf("All Notes cleared\n");
}
void listNotes()
{
    FILE* file = fopen("data/notes.txt", "r");
    if(file == NULL)
    {
        printf("No notes Found\n");
        return;
    }
    char buffer[1024];
    int noteNumber = 1;
    while(fgets(buffer, sizeof(buffer), file))
        printf("%d. %s", noteNumber++, buffer);

    fclose(file);
}
void notes_execute(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage:\n notes add <text>\n notes list\n notes clear\n");
        return;
    }
    if(strcmp(argv[1], "add") == 0)
        addNote(argc,argv);
    else if(strcmp(argv[1], "list") == 0)
        listNotes();
    else if(strcmp(argv[1], "clear") == 0)
        clearNotes();
    else 
        printf("Note Command %s Unknown\n", argv[1]);
}

Plugin notesPlugin = {
    .name = "notes",
    .description = "Note Manager",
    .execute = notes_execute
};