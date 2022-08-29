#include "headers.h"
void str_tok_and(char *string, char *relative, char *correct, char *previous)
{
    char *tokens[1000];
    INT token_count = 0;
    tokens[token_count] = strtok(string,"&");
    // printf("%s\n",tokens[0]);
    while (tokens[token_count] != NULL)
    {
        token_count++;
        tokens[token_count] = strtok(NULL,"&");
    }
    for (INT i = 0; i < token_count; i++)
    {
        // printf("%s\n",tokens[i]);
        process_command(tokens[i], relative, correct, previous);
    }
}