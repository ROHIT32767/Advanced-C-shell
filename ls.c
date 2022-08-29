#include "headers.h"

INT print_ls(char *string, char *correct_path, INT type)
{
    char *string1 = (char *)calloc(1000, sizeof(char));
    if (string[0] == '~')
    {
        strcpy(string1, correct_path);
        strcat(string1, &string[1]);
    }
    else
    {
        strcpy(string1, string);
    }
    /**/
    struct dirent** name_list;
    if (type == 0)
    {
        INT num_directory_entries = scandir(string1,&name_list,NULL,alphasort);
        for(INT i=0;i<num_directory_entries;i++)
        {
            
        }

    }
    else if (type == 1)
    {
        INT num_directory_entries = scandir(string1,&name_list,NULL,alphasort);
    }
    else if (type == 2)
    {
        INT num_directory_entries = scandir(string1,&name_list,NULL,alphasort);
    }
    else if (type == 3)
    {
        INT num_directory_entries = scandir(string1,&name_list,NULL,alphasort);
    }
    else
    {
        perror("Error in print_ls function");
        return 0;
    }
    free(string1);
}

void ls_func(char *string[], char *correct_path, long long int num_tokens)
{
    INT extra_info = 0;
    INT hidden = 0;
    INT num_commands = 0;
    for (INT i = 0; i < num_tokens; i++)
    {
        if (string[i][0] == '-')
        {

            if (strcmp(string[i], "-l") == 0)
            {
                extra_info = 1;
            }
            else if ((strcmp(string[i], "-a") == 0))
            {
                hidden = 1;
            }
            else if ((strcmp(string[i], "-la") == 0))
            {
                extra_info = 1;
                hidden = 1;
            }
            else if ((strcmp(string[i], "-al") == 0))
            {
                extra_info = 1;
                hidden = 1;
            }
            else
            {
                perror("Incorrect argument supplied to command ls");
                return;
            }
        }
        else
        {
            num_commands++;
        }
    }
    /*
    extra_info and hidden=3;
    extra_info=2;
    hidden=1;
    nothing=0;
    */
    if (extra_info)
    {
        if (hidden)
        {
            for (INT i = 0; i < num_tokens; i++)
            {
                if (string[i][0] != '-')
                {
                    print_ls(string[i], 3);
                }
            }
        }
        else
        {
            for (INT i = 0; i < num_tokens; i++)
            {
                if (string[i][0] != '-')
                {
                    print_ls(string[i], 2);
                }
            }
        }
    }
    else
    {
        if (hidden)
        {
            for (INT i = 0; i < num_tokens; i++)
            {
                if (string[i][0] != '-')
                {
                    print_ls(string[i], 1);
                }
            }
        }
        else
        {
            for (INT i = 0; i < num_tokens; i++)
            {
                if (string[i][0] != '-')
                {
                    print_ls(string[i], 0);
                }
            }
        }
    }
}