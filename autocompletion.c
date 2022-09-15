#include "headers.h"
int compare2(const void *arg1, const void *arg2)
{
    return (strcmp((*((struct dirent **)arg1))->d_name, (*((struct dirent **)arg2))->d_name));
}
/*
-2 for perrors

*/
long long int autocomplete(char *dir, char *input_find, char *correct_path)
{
    struct dirent **name_list;
    INT num_directory_entries = scandir(dir, &name_list, NULL, alphasort);
    if (num_directory_entries == -1)
    {
        if (errno == ENOTDIR)
        {
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
        perror("NUmber of directory entries is 0 in autocompletion");
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
    for (INT i = 0; i < num_directory_entries; i++)
    {
        if (strncmp(input_find, name_list[i]->d_name, find_len) == 0)
        {
            strcpy(found_strings[found_strings_index], name_list[i]->d_name);
            // found_strings[found_strings_index][strlen(name_list[i]->d_name)]='\0';
            found_strings_index++;
        }
    }
    qsort(found_strings,found_strings_index,sizeof(found_strings[0],strcmp));
}