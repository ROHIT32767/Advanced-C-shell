#include "headers.h"
INT str_tok_whitespaces(char *tokens[], char *input)
{
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
    INT redirect_type = 0;
    if ((token[0] != NULL) || (len == 0))
    {
        char *io_type[2]; // storing string of io
        INT io_index[2];  // storing index
        io_index[0] = -1;
        io_index[1] = -1;
        INT type_io[2]; // storing type of io as number
        type_io[0] = -1;
        type_io[1] = -1;
        INT num_io_type = 0;
        INT io_flag = 0;
        // < for 0
        // > for 1
        // >> for 2
        for (INT i = 0; i < 2; i++)
        {
            io_type[i] = (char *)calloc(3, sizeof(char));
        }
        for (INT i = 0; i < num_tokens; i++)
        {
            if (strcmp(token[i], "<") == 0)
            {
                if (num_io_type > 1)
                {
                    perror("Too many i/o redirection arguments in one token of command");
                    return;
                }
                io_flag = 1;
                io_type[num_io_type][0] = '<';
                io_type[num_io_type][1] = '\0';
                io_index[num_io_type] = i;
                type_io[num_io_type] = 0;
                num_io_type++;
            }
            else if (strcmp(token[i], ">") == 0)
            {
                if (num_io_type > 1)
                {
                    perror("Too many i/o redirection arguments in one token of command");
                    return;
                }
                if (i != num_tokens - 1)
                {
                    if (strcmp(token[i + 1], ">") == 0)
                    {
                        io_flag = 1;
                        io_type[num_io_type][0] = '>';
                        io_type[num_io_type][1] = '>';
                        io_type[num_io_type][2] = '\0';
                        io_index[num_io_type] = i;
                        type_io[num_io_type] = 2;
                        num_io_type++;
                    }
                    else
                    {
                        io_flag = 1;
                        io_type[num_io_type][0] = '>';
                        io_type[num_io_type][1] = '\0';
                        io_index[num_io_type] = i;
                        type_io[num_io_type] = 1;
                        num_io_type++;
                    }
                }
                else
                {
                    io_flag = 1;
                    io_type[num_io_type][0] = '>';
                    io_type[num_io_type][1] = '\0';
                    io_index[num_io_type] = i;
                    type_io[num_io_type] = 1;
                    num_io_type++;
                }
            }
        }
        if (io_flag)
        {
            io_redirect(&token[0],num_tokens,&io_type[0],type_io,io_index);
        }

        // builtin commands
        if (strcmp(token[0], "cd") == 0)
        {
            if (&token[1] != NULL)
            {
                cd_func(&token[1], num_tokens - 1, relative, correct, previous);
                INT len = strlen(previous);
                previous[len] = '\0';
            }
            else
            {
                perror("syntax error");
                return;
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
                return;
            }
        }
        else if (strcmp(token[0], "discover") == 0)
        {

            discover_func(&token[1], correct, num_tokens - 1);
        }
        else if (strcmp(token[0], "pinfo") == 0)
        {
            if (num_tokens <= 2)
            {
                pinfo(&token[1], num_tokens - 1, correct);
            }
            else
            {
                perror("Too many arguments for command pinfo");
                return;
            }
        }
        else
        {
            if ((strlen(token[0]) != 0))
            {
                spec4_func(&token[0], correct, last, LIST, num_tokens);
            }
            else
            {
                perror("syntax error");
                return;
            }
        }
    }
}
