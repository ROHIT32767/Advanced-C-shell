#include "headers.h"
void echo_func(char *string[], INT num)
{
    if (num > 0)
    {
        for (INT i = 0; i < num - 1; i++)
        {
            printf("%s ", string[i]);
        }
        printf("%s\n", string[num - 1]);
    }
    else if(num==0)
    {
        printf("\n");
    }
    else
    {
        perror("Incorrect number of arguments supplied to command pwd");
        exit(1);
    }
}