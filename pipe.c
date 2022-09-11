#include "headers.h"
INT str_tok_pipe(char *tokens[], char *input)
{
    long long int Token_count = 0;
    tokens[Token_count] = strtok(input, "|");
    while (tokens[Token_count] != NULL)
    {
        Token_count++;
        tokens[Token_count] = strtok(NULL, "|");
    }
    return Token_count;
}
void pipe_to_process_command(char *string, char *relative, char *correct, char *previous, INT len, INT last, List *LIST)
{
    char *p;
    p = strstr(string, "|");
    if (p)
    {
        char *token[1000];
        INT num_tokens = str_tok_pipe(token, string);
        //   printf("num_tokens is %lld\n",num_tokens);
        if ((token[0] != NULL) || (len == 0))
        {
            if (num_tokens > 0)
            {
                int pipe_fd[num_tokens - 1][2];
                INT pipe_std_out = dup(1);
                if (pipe(pipe_fd[0]) == -1)
                {
                    perror("pipe");
                    return;
                }
                dup2(pipe_fd[0][1], 1);
                close(pipe_fd[0][1]);
                process_command(token[0], relative, correct, previous, len, last, LIST);
                dup2(pipe_std_out, 1);
                close(pipe_std_out);
                for (INT i = 1; i < num_tokens - 1; i++)
                {

                    INT pipe_std_in = dup(0);
                    INT new_out = dup(1);
                    if (pipe(pipe_fd[i]) == -1)
                    {
                        perror("pipe");
                        return;
                    }
                    dup2(pipe_fd[i - 1][0], 0);
                    close(pipe_fd[i - 1][0]);
                    dup2(pipe_fd[i][1], 1);
                    close(pipe_fd[i][1]);
                    process_command(token[i], relative, correct, previous, len, last, LIST);
                    dup2(pipe_std_in, 0);
                    close(pipe_std_in);
                    dup2(new_out, 1);
                    close(new_out);
                }
                INT new_in=dup(0);
                dup2(pipe_fd[num_tokens - 2][0], 0);
                close(pipe_fd[num_tokens - 2][0]);
                process_command(token[num_tokens - 1], relative, correct, previous, len, last, LIST);
                dup2(new_in, 0);
                close(new_in);
            }
        }
    }
    else
    {
        process_command(string, relative, correct, previous, len, last, LIST);
    }
}