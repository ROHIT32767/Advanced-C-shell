#include "headers.h"
extern List *LIST;
void interrupt_handler()
{
    int status;
    INT pid = waitpid(-1, &status, WNOHANG | WUNTRACED);
    if (WIFEXITED(status))
    {
        INT exit_status = WEXITSTATUS(status);
        if (!exit_status)
        {
            char *string = (char *)malloc(600 * sizeof(char));
            string = find_string(LIST, pid);
            printf("%s exited with  pid %lld exited normally\n", string, pid);
            free(string);
        }
        else
        {
            char *string = (char *)malloc(600 * sizeof(char));
            string = find_string(LIST, pid);
            printf("%s exited with  pid %lld exited abnormally\n", string, pid);
            free(string);
        }
    }
}