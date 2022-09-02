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
void process_command(char *string, char *relative, char *correct, char *previous, INT len, INT last, List *LIST)
{
    char *token[1000];
    INT num_tokens = str_tok_whitespaces(token, string);
    if ((token[0] != NULL) || (len == 0))
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
        else if (strcmp(token[0], "history") == 0)
        {
            if (num_tokens == 1)
            {
                print_history();
            }
            else
            {
                perror("Too many arguments for history");
            }
        }
        else
        {
            if ((strlen(token[0]) != 0))
            {
                spec4_func(&token[0], relative, correct, previous, last, LIST);
            }
            else
            {
                perror("syntax error");
            }
        }
    }

    else
    {
        // perror("syntax error");
    }
}
/*
  // for(INT i=0;i<num_tokens;i++)
    // {
    //     printf("%s\n",token[i]);
    // }

if ((strlen(token[0]) != 0))
        {
            printf("last value is %lld ",last);
            for(INT i=0;i<num_tokens;i++)
            {
                printf("%s ",token[i]);
            }
            printf("\n");
            //spec4_func(&token[0], relative, correct, previous, last);
        }
        else
        {
            perror("syntax error");
        }
*/