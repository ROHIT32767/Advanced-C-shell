#include "headers.h"
extern char *user_name;
extern char *system_name;
extern char *relative_path;
int compare2(const void *arg1, const void *arg2)
{
    return (strcmp((*((struct dirent **)arg1))->d_name, (*((struct dirent **)arg2))->d_name));
}
int sortstring(const void *str1, const void *str2)
{
    char *const *pp1 = str1;
    char *const *pp2 = str2;
    return strcmp(*pp1, *pp2);
}
/*
-2 for perrors

*/
long long int autocomplete(char *dir, char *input_find, char *input, INT slash_index, INT end_index)
{

    char *print_string = (char *)calloc(1000, sizeof(char));
    print_string[0] = '\0';
    struct dirent **name_list;
    INT num_directory_entries = scandir(dir, &name_list, NULL, alphasort);
    //  printf("num_directory entries is %lld\n",num_directory_entries);
    if (num_directory_entries == -1)
    {
        if (errno == ENOTDIR)
        {
            printf("\n");
            perror("Directory not found in autocomplete : ");
            return -2;
        }
        else
        {
            perror(NULL);
            return -2;
        }
    }
    if (num_directory_entries == 0)
    {
        printf("\n");
        perror("Number of directory entries is 0 in autocompletion");
        return -2;
    }
    qsort(name_list, num_directory_entries, sizeof(name_list[0]), compare2);
    INT find_len = strlen(input_find);
    char *found_strings[num_directory_entries + 1];
    for (INT i = 0; i < num_directory_entries + 1; i++)
    {
        found_strings[i] = (char *)calloc(600, sizeof(char));
    }
    INT found_strings_index = 0;
    INT dir_index = -1;
    for (INT i = 0; i < num_directory_entries; i++)
    {
        if (strlen(input_find) == 0 && (strcmp(name_list[i]->d_name, ".") != 0) && (strcmp(name_list[i]->d_name, "..") != 0))
        {
            strcpy(found_strings[found_strings_index], name_list[i]->d_name);
            found_strings_index++;
            dir_index = i;
        }
        else if (strncmp(input_find, name_list[i]->d_name, find_len) == 0 && (strcmp(name_list[i]->d_name, ".") != 0) && (strcmp(name_list[i]->d_name, "..") != 0))
        {
            strcpy(found_strings[found_strings_index], name_list[i]->d_name);
            found_strings_index++;
            dir_index = i;
        }
    }
    //  printf("found_strings_index is %lld\n",found_strings_index);
    if (found_strings_index == 0)
    {
        return;
    }
    else if (found_strings_index == 1)
    {
        char *string = (char *)calloc(1000, sizeof(char));
        strcpy(string, &dir[0]);
        if (strcmp(&dir[0], ".") == 0)
        {
            strcat(string, "/");
        }
        strcat(string, &(name_list[dir_index]->d_name)[0]);
        struct stat fs;
        INT R = lstat(string, &fs);
        if (R == -1)
        {
            printf("string is %s\n", string);
            perror("Invalid path to lstat in autocompletion");
            return -2;
        }
        INT J = S_ISDIR(fs.st_mode);
        INT F = S_ISREG(fs.st_mode);
        if (J)
        {
            strcat(print_string, &(name_list[dir_index]->d_name)[0]);
            INT print_length = strlen(print_string);
            print_string[print_length] = '/';
            print_string[print_length + 1] = '\0';
            input[slash_index + 1] = '\0';
            strcat(input, print_string);
            printf("%s", &input[end_index + 1]);
            INT display_size = 1000;
            char *display = (char *)calloc(display_size, sizeof(char));
            sprintf(display, "\r%s<%s@%s:%s>\033[0m", KMAG, user_name, system_name, relative_path);
            write(1, display, strlen(display));
            printf("%s", input);
        }
        else if (F)
        {
            strcat(print_string, &(name_list[dir_index]->d_name)[0]);
            INT print_length = strlen(print_string);
            print_string[print_length] = ' ';
            print_string[print_length + 1] = '\0';
            input[slash_index + 1] = '\0';
            strcat(input, print_string);
            INT display_size = 1000;
            char *display = (char *)calloc(display_size, sizeof(char));
            sprintf(display, "\r%s<%s@%s:%s>\033[0m", KMAG, user_name, system_name, relative_path);
            write(1, display, strlen(display));
            printf("%s", input);

            // printf("%s", &input[end_index + 1]);
        }
    }
    else
    {
        qsort(found_strings, found_strings_index, sizeof(found_strings[0]), sortstring);
        INT same_prefix;
        printf("\n");
        for (INT i = 0; i < found_strings_index; i++)
        {
            char *string = (char *)calloc(1000, sizeof(char));
            strcpy(string, &dir[0]);
            if (strcmp(&dir[0], ".") == 0)
            {
                strcat(string, "/");
            }
            strcat(string, found_strings[i]);
            struct stat fs;
            INT R = lstat(string, &fs);
            if (R == -1)
            {
                printf("dir is %s and string is %s\n", &dir[0], string);
                perror("Invalid directory in lstat in autocompletion");
                return -2;
            }
            INT J = S_ISDIR(fs.st_mode);
            INT F = S_ISREG(fs.st_mode);
            if (J)
            {
                printf("%s/\n", found_strings[i]);
            }
            else if (F)
            {
                printf("%s\n", found_strings[i]);
            }
        }
        INT len1 = strlen(found_strings[0]);
        INT len2 = strlen(found_strings[found_strings_index - 1]);
        INT min_len = len1 < len2 ? len1 : len2;
        for (INT i = 0; i < min_len; i++)
        {
            if (found_strings[0][i] == found_strings[found_strings_index - 1][i])
            {
                print_string[i] = found_strings[0][i];
                print_string[i + 1] = '\0';
            }
            else
            {
                break;
            }
        }
        INT display_size = 1000;
        char *display = (char *)calloc(display_size, sizeof(char));
        sprintf(display, "%s<%s@%s:%s>\033[0m", KMAG, user_name, system_name, relative_path);
        write(1, display, strlen(display));
        input[slash_index + 1] = '\0';
        strcat(input, print_string);
        INT input_length = strlen(input);
        input[input_length] = '\0';
        printf("%s", input);
        free(print_string);
    }
    return 0;
}