#include "headers.h"

INT print_ls(char *string, char *correct_path, INT type, INT num_args)
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
    struct dirent **name_list;
    if (type == 0) // no l & a
    {
        INT num_directory_entries = scandir(string1, &name_list, NULL, alphasort);
        if (num_directory_entries == -1)
        {
            perror("scandir in type 0");
            exit(EXIT_FAILURE);
        }
        if (num_args >= 2)
        {
            printf("%s:\n", string1);
        }
        for (INT i = 0; i < num_directory_entries; i++)
        {
            if ((strcmp(name_list[i]->d_name, ".") != 0) && ((strcmp(name_list[i]->d_name, "..") != 0)))
            {
                printf("%s\n", name_list[i]->d_name);
            }
            free(name_list[i]->d_name);
        }
        free(name_list);
    }
    else if (type == 1) // no l but a is there
    {
        INT num_directory_entries = scandir(string1, &name_list, NULL, alphasort);
        if (num_directory_entries == -1)
        {
            perror("scandir in type 0");
            exit(EXIT_FAILURE);
        }
        if (num_args >= 2)
        {
            printf("%s:\n", string1);
        }
        for (INT i = 0; i < num_directory_entries; i++)
        {
            printf("%s\n", name_list[i]->d_name);
            free(name_list[i]->d_name);
        }
        free(name_list);
    }
    else if (type == 2) // no a ,only l
    {
        INT num_directory_entries = scandir(string1, &name_list, NULL, alphasort);
        if (num_directory_entries == -1)
        {
            perror("scandir in type 0");
            exit(EXIT_FAILURE);
        }
        if (num_args >= 2)
        {
            printf("%s:\n", string1);
        }
        struct stat fs;
        INT R;
        
        for (INT i = 0; i < num_directory_entries; i++)
        {
            R = stat(string1, &fs);
            
            printf("%s\n", name_list[i]->d_name);
            free(name_list[i]->d_name);
        }
        free(name_list);
    }
    else if (type == 3)
    {
        INT num_directory_entries = scandir(string1, &name_list, NULL, alphasort);
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
                    print_ls(string[i], correct_path, 3, num_commands);
                }
            }
        }
        else
        {
            for (INT i = 0; i < num_tokens; i++)
            {
                if (string[i][0] != '-')
                {
                    print_ls(string[i], correct_path, 2, num_commands);
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
                    print_ls(string[i], correct_path, 1, num_commands);
                }
            }
        }
        else
        {
            for (INT i = 0; i < num_tokens; i++)
            {
                if (string[i][0] != '-')
                {
                    print_ls(string[i], correct_path, 0, num_commands);
                }
            }
        }
    }
}