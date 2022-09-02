#include "headers.h"
extern List *LIST;
void interrupt_handler()
{
    int status;
    INT pid = waitpid(-1, &status, WNOHANG | WUNTRACED);
    if (pid>0)
    {
        if (WIFEXITED(status))
        {
            INT exit_status = WEXITSTATUS(status);
            if (!exit_status)
            {
                char *string = (char *)malloc(600 * sizeof(char));
                string = find_string(LIST, pid);
                printf("%s with  pid %lld exited normally\n", string, pid);
                DELETE(LIST,find(LIST, pid, string));
                free(string);
            }
            else
            {
                char *string = (char *)malloc(600 * sizeof(char));
                string = find_string(LIST, pid);
                printf("%s with  pid %lld exited abnormally\n", string, pid);
                DELETE(LIST,find(LIST, pid, string));
                free(string);
            }
        }
    }
}