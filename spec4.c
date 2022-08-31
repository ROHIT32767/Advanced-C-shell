#include "headers.h"

void bg_func(char *string, char *string1, char *string2, char *string3)
{
}
void fg_func(char *string, char *string1, char *string2, char *string3)
{
}

void spec4_func(char *string, char *string1, char *string2, char *string3, long long int last)
{
    if (last)
    {
    }
    else
    {
        pid_t forkReturn = fork();
        if (forkReturn == -1)
        {
            perror("no child process is created");
        }
        else
        {
            INT exec_return=execvp(string[0],string);
            if(exec_return)
        }
    }
}