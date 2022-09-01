#include "headers.h"
extern INT num_bg_processes;
extern time_t start_seconds;
void bg_func(char *string[], char *string1, char *string2, char *string3, List *LIST)
{
    INT forkReturn = fork();
    if (forkReturn == -1)
    {
        perror("no child process is created");
    }
    else
    {

        if (forkReturn == 0)
        {
            INT exec_return = execvp(string[0], string);
            if (exec_return == -1)
            {
                perror("exec functions returns to the calling process image, an error has occurred");
                return;
            }
        }
        else
        {
          // printf("string is %s\n", string[0]);
            insert(LIST, forkReturn, string[0]);
         //  print(LIST);
          // printf("\n");
            printf("[%d] %lld\n", find(LIST, forkReturn, string[0]) + 1, forkReturn);
            signal(SIGCHLD, interrupt_handler);
        }
    }
}
void fg_func(char *string[], char *string1, char *string2, char *string3)
{
    pid_t forkReturn = fork();
    if (forkReturn == -1) 
    {
        perror("no child process is created");
    }
    else
    {
        if (forkReturn == 0)
        {
            INT exec_return = execvp(string[0], string);
            if (exec_return == -1)
            {
                perror("exec functions returns to the calling process image, an error has occurred");
                return;
            }
        }
        else
        {
            int status;
            pid_t wpid;
            wpid = waitpid(forkReturn, &status, WSTOPPED);
        }
    }
}

void spec4_func(char *string[], char *relative, char *correct, char *previous, long long int last, List *LIST)
{
    if (last)
    {
        fg_func(string, relative, correct, previous);
    }
    else
    {
        bg_func(string, relative, correct, previous, LIST);
    }
}