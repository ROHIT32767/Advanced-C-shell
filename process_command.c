#include "headers.h"
INT str_tok_whitespaces(char *tokens[], char *input)
{
    // char *semicolon = (char *)calloc(1, sizeof(char));
    // semicolon[0] = ' ';
    long long int Token_count = 0;
    tokens[Token_count] = strtok(input, " \t");
    while (tokens[Token_count] != NULL)
    {
        Token_count++;
        tokens[Token_count] = strtok(NULL, " \t");
    }
    return Token_count;
}
void process_command(char *string, char *relative, char *correct, char *previous,INT len)
{
    char *token[1000];
    INT num_tokens = str_tok_whitespaces(token, string);
    if ((token[0] != NULL)||(len==0))
    {
        if (strcmp(token[0], "cd") == 0)
        {

            if (&token[1] != NULL)
            {

                cd_func(&token[1], num_tokens - 1, relative, correct, previous);
                // strcpy(previous,relative);
                // printf("previous directory is %s\n",previous);
                INT len = strlen(previous);
                previous[len] = '\0';
                // printf("Hello\n");
            }
            else
            {
                perror("syntax error");
            }
        }
        else if (strcmp(token[0], "pwd") == 0)
        {
            pwd_func(num_tokens - 1);
        }
        else if (strcmp(token[0], "echo") == 0)
        {
            echo_func(&token[1], num_tokens - 1);
        }
        else if (strcmp(token[0], "ls") == 0)
        {
            // not implemented completely
            ls_func(&token[1], correct, num_tokens - 1);
        }
        else
        {
            printf("-1\n");
        }
    }
    else
    {
        perror("syntax error");
    }
}
/*
  // for(INT i=0;i<num_tokens;i++)
    // {
    //     printf("%s\n",token[i]);
    // }

*/