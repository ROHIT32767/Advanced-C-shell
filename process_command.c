#include "headers.h"
INT str_tok_whitespaces(char *tokens[], char *input)
{
    char *semicolon = (char *)calloc(1, sizeof(char));
    semicolon[0] = ' ';
    long long int Token_count = 0;
    tokens[Token_count] = strtok(input,semicolon);
    while (tokens[Token_count] != NULL)
    {
        Token_count++;
        tokens[Token_count] = strtok(NULL,semicolon);
    }
    return Token_count;
}
void process_command(char *string, char *relative, char *correct,char* previous)
{
    char *token[1000];
    INT num_tokens = str_tok_whitespaces(token, string);
    // for(INT i=0;i<num_tokens;i++)
    // {
    //     printf("%s\n",token[i]);
    // }
    if (strcmp(token[0], "cd") == 0)
    {
        cd_func(&token[1], num_tokens-1, relative, correct,previous);
        // strcpy(previous,relative);
        printf("previous directory is %s\n",previous);
        INT len=strlen(previous);
        previous[len]='\0';
       // printf("Hello\n");
    }
    else
    {
        printf("-1\n");
    }
}