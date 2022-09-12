#include "headers.h"
void FG(char *string[], long long int num_tokens, List *LIST)
{
    if (num_tokens == 1)
    {
        char *ptr1;
        INT job_number = strtol(string[0], &ptr1, 10);
        struct node *head = LIST->root;
        while (head != NULL)
        {
            if (head->idx == job_number)
            {
                INT pid = head->Element;
                INT calling_group_id = getpgid(0);
                setpgid(pid, calling_group_id);
                signal(SIGTTOU, SIG_IGN);
                signal(SIGTTIN, SIG_IGN);
                INT tc_return1 = tcsetpgrp(0, pid);
                if (tc_return1 == -1)
                {
                    perror(NULL);
                    return;
                }
                INT return_kill = kill(pid, SIGCONT);
                if (return_kill == -1)
                {
                    perror(NULL);
                    return;
                }
                int status;
                waitpid(pid, &status, WUNTRACED|WSTOPPED);
                INT tc_return2 = tcsetpgrp(0, getpgid(0));
                if (tc_return2 == -1)
                {
                    perror(NULL);
                    return;
                }
                signal(SIGTTIN, SIG_DFL);
                signal(SIGTTOU, SIG_DFL);
                char *string2 = (char *)malloc(600 * sizeof(char));
                string2 = find_string(LIST, head->Element);
                DELETE(LIST, find(LIST, head->Element, string2));
                free(string2);
                return;
            }
            head = head->Next;
        }
        perror("No jub with given job number exists");
        return;
    }
}