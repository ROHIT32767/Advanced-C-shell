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
        INT dir_ret = chdir(string[0]);
        // printf("directory returns %s\n", string[0]);
        // printf("relative is %s\n",relative);
        // printf("correct is %s\n",correct);
        if (dir_ret == -1)
        {
            perror("Incorrect directory path supplied to command cd");
        }
        else
        {
            char *dir_absolute;
            dir_absolute = getcwd(NULL, 300);
          //  printf("dir_absolute is %s\n",dir_absolute);
            char *p = strstr(dir_absolute, correct);
            if (p)
            {
                INT len1 = strlen(dir_absolute);
                INT len2 = strlen(correct);
                char *curr_dir1 = (char *)calloc(len1 - len2 + 2, sizeof(char));
                curr_dir1[0] = '-';
                INT i = 1;
                for (i = 1; i <= len1 - len2; i++)
                {
                    curr_dir1[i] = dir_absolute[len2 + i - 1];
                }
                curr_dir1[i] = '\0';
                strcpy(relative, curr_dir1);
               //  printf("%s\n",curr_dir1);
               
            }
            else
            {
                strcpy(relative, dir_absolute);
            }
        }
    }
}