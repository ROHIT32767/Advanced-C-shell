#include "headers.h"
void BG(char *string[], long long int num_tokens, List *LIST)
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
                INT return_kill = kill(pid, SIGCONT);
                if (return_kill == -1)
                {
                    perror(NULL);
                    return;
                }
                return;
            }
            head = head->Next;
        }
        perror("No jub with given job number exists");
        return;
    }
    return;
}