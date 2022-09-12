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
                INT tc_return1=tcsetpgrp(0,pid);
                if(tc_return1==-1)
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
                pid = waitpid(-1, &status, WNOHANG | WUNTRACED);
                INT tc_return2=tcsetpgrp(0,getpgid(0));
                if(tc_return2==-1)
                {
                    perror(NULL);
                    return;
                }
                signal(SIGTTIN, SIG_DFL);
                signal(SIGTTOU, SIG_DFL);
                return;
            }
            head = head->Next;
        }
        perror("No jub with given job number exists");
        return;
    }
}