#ifndef PARSER_H
#define PARSER_H

typedef struct ParsedCommand
{
    int argc;
    char ** argv;
}ParsedCommand;

ParsedCommand parseInput(char* input);
void freeParsedCommand(ParsedCommand* cmd);

#endif