#include "headers.h"

void cd_func(char *string[], INT num, char *relative, char *correct)
{
    if (num > 1 || num == 0)
    {
        perror("Incorrect number of arguments supplied for command cd");
        exit(1);
    }
    else
    {
        INT dir_ret = chdir(string[1]);
        if (dir_ret == -1)
        {
            perror("Incorrect directory path supplied to command cd");
        }
        else
        {
            char *dir_absolute = (char *)calloc(300, sizeof(char));
            getcwd(dir_absolute, 300);
            char *p = strstr(dir_absolute, correct);
            if (p)
            {
                INT len1 = strlen(dir_absolute);
                INT len2 = strlen(correct);
                char *curr_dir1 = (char *)calloc(len1 - len2 + 1, sizeof(char));
                curr_dir1[0] = '-';
                INT i = 1;
                for (i = 1; i <= len1 - len2; i++)
                {
                    correct[i] = dir_absolute[len2 + i - 1];
                }
                curr_dir1[i] = '\0';
                strcpy(relative,curr_dir1);
            }
            else
            {
                strcpy(relative,dir_absolute);
            }
        }
    }
}