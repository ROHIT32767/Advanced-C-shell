#include "headers.h"
void print_ls(char *string, char *correct_path, INT type, INT num_args)
{
    char *string1 = (char *)calloc(1000, sizeof(char));
    char *path = (char *)calloc(600, sizeof(char));
    if (string[0] == '~')
    {
        strcpy(string1, correct_path);
        strcat(string1, &string[1]);
    }
    else
    {
        strcpy(string1, string);
    }
    strcpy(path, string1);
    strcat(path, "/");
    INT len = strlen(path);
    /**/
    struct dirent **name_list;
    if (type == 0) // no l & a
    {
        INT files = 0;
        // printf("type is %lld\n",type);
        // printf("string1 is %s\n",string1);
        INT num_directory_entries = scandir(string1, &name_list, NULL, alphasort);
        // printf("num_directory_entries is %lld\n",num_directory_entries);
        if (num_directory_entries == -1)
        {
            if (errno == ENOTDIR)
            {
                files = 1;
            }
            else
            {
                perror("scandir in type 0");
                exit(EXIT_FAILURE);
            }
        }
        if (num_args >= 2 && files != 1)
        {
            printf("%s:\n", string1);
        }
        if (!files)
        {
            for (INT i = 0; i < num_directory_entries; i++)
            {
                char *ptr = name_list[i]->d_name;
                char ch = ptr[0];
                if (ch != '.')
                {
                    struct stat fs;
                    strcat(path, name_list[i]->d_name);
                    INT R = stat(path, &fs);
                    if (R == -1)
                    {
                        perror("File error in file in type 2\n");
                        exit(1);
                    }
                    INT J = S_ISDIR(fs.st_mode);
                    INT G = fs.st_mode & S_IXUSR;
                    if (J)
                    {
                        printf("%s%s\033[0m\n", KBLU, name_list[i]->d_name);
                    }
                    else
                    {
                        if (S_ISREG(fs.st_mode))
                        {
                            if (G)
                            {
                                printf("%s%s\033[0m\n", KGRN, name_list[i]->d_name);
                            }
                            else
                            {
                                printf("%s%s\033[0m\n", KWHT, name_list[i]->d_name);
                            }
                        }
                        else
                        {
                            printf("%s%s\033[0m\n", KYEL, name_list[i]->d_name);
                        }
                    }
                    // printf("%s\n", name_list[i]->d_name);
                    path[len] = '\0';
                }
                free(name_list[i]);
            }
            free(name_list);
        }
        else
        {
            INT R = 0;
            struct stat fs;
            R = stat(string1, &fs);
            if (R == -1)
            {
                perror("File error in file in type 2\n");
                exit(1);
            }
            INT G = fs.st_mode & S_IXUSR;
            if (S_ISREG(fs.st_mode))
            {
                if (G)
                {
                    printf("%s%s\033[0m\n", KGRN, string1);
                }
                else
                {
                    printf("%s%s\033[0m\n", KWHT, string1);
                }
            }
            else
            {
                printf("%s%s\033[0m\n", KYEL, string1);
            }
        }
    }
    else if (type == 1) // no l but a is there
    {
        INT files = 0;
        // printf("type is %lld\n", type);
        // printf("string1 is %s\n", string1);
        INT num_directory_entries = scandir(string1, &name_list, NULL, alphasort);
        // printf("num_directory_entries is %lld\n", num_directory_entries);
        if (num_directory_entries == -1)
        {
            if (errno == ENOTDIR)
            {
                files = 1;
            }
            else
            {
                perror("scandir in type 1");
                exit(EXIT_FAILURE);
            }
        }
        if (num_args >= 2 && files != 1)
        {
            printf("%s:\n", string1);
        }
        if (!files)
        {
            for (INT i = 0; i < num_directory_entries; i++)
            {
                struct stat fs;
                strcat(path, name_list[i]->d_name);
                INT R = stat(path, &fs);
                if (R == -1)
                {
                    perror("File error in file in type 2\n");
                    exit(1);
                }
                INT J = S_ISDIR(fs.st_mode);
                INT G = fs.st_mode & S_IXUSR;
                // printf("%s\n", name_list[i]->d_name);
                if (J)
                {
                    printf("%s%s\033[0m\n", KBLU, name_list[i]->d_name);
                }
                else
                {
                    if (S_ISREG(fs.st_mode))
                    {
                        if (G)
                        {
                            printf("%s%s\033[0m\n", KGRN, name_list[i]->d_name);
                        }
                        else
                        {
                            printf("%s%s\033[0m\n", KWHT, name_list[i]->d_name);
                        }
                    }
                    else
                    {
                        printf("%s%s\033[0m\n", KYEL, name_list[i]->d_name);
                    }
                }
                // printf("%s\n", name_list[i]->d_name);
                path[len] = '\0';
                free(name_list[i]);
            }
            free(name_list);
        }
        else
        {
            INT R = 0;
            struct stat fs;
            R = stat(string1, &fs);
            if (R == -1)
            {
                perror("File error in file in type 2\n");
                exit(1);
            }
            INT G = fs.st_mode & S_IXUSR;
            if (S_ISREG(fs.st_mode))
            {
                if (G)
                {
                    printf("%s%s\033[0m\n", KGRN, string1);
                }
                else
                {
                    printf("%s%s\033[0m\n", KWHT, string1);
                }
            }
            else
            {
                printf("%s%s\033[0m\n", KYEL, string1);
            }
        }
    }
    else if (type == 2) // no a ,only l
    {
        INT files = 0;
        // printf("type is %lld\n", type);
        INT num_directory_entries = scandir(string1, &name_list, NULL, alphasort);
        if (num_directory_entries == -1)
        {
            if (errno == ENOTDIR)
            {
                files = 1;
            }
            else
            {
                perror("scandir in type 2");
                exit(EXIT_FAILURE);
            }
        }
        if (num_args >= 2 && files != 1)
        {
            printf("%s:\n", string1);
        }
        struct stat fs;
        INT R = 0;

        if (!files)
        {
            for (INT i = 0; i < num_directory_entries; i++)
            {
                char *ptr = name_list[i]->d_name;
                char ch = ptr[0];
                if ((ch != '.'))
                {
                    strcat(path, name_list[i]->d_name);
                    // printf("string 1 is %s,name_list is %s,path is %s\n", string1, name_list[i]->d_name, path);
                    R = stat(path, &fs);
                    if (R == -1)
                    {
                        perror("File error in file in type 2\n");
                        exit(1);
                    }
                    INT E;
                    INT J = S_ISDIR(fs.st_mode);
                    INT G = fs.st_mode & S_IXUSR;
                    E = S_ISDIR(fs.st_mode) ? printf("d") : printf("-");
                    E = (fs.st_mode & S_IRUSR) ? printf("r") : printf("-");
                    E = (fs.st_mode & S_IWUSR) ? printf("w") : printf("-");
                    E = (fs.st_mode & S_IXUSR) ? printf("x") : printf("-");
                    E = (fs.st_mode & S_IRGRP) ? printf("r") : printf("-");
                    E = (fs.st_mode & S_IWGRP) ? printf("w") : printf("-");
                    E = (fs.st_mode & S_IXGRP) ? printf("x") : printf("-");
                    E = (fs.st_mode & S_IROTH) ? printf("r") : printf("-");
                    E = (fs.st_mode & S_IWOTH) ? printf("w") : printf("-");
                    E = (fs.st_mode & S_IXOTH) ? printf("x") : printf("-");
                    printf("%ld ", fs.st_nlink);
                    uid_t user_id = fs.st_uid;
                    if (getpwuid(user_id) != NULL)
                    {
                        printf("%s ", getpwuid(user_id)->pw_name);
                    }
                    else
                    {
                        perror("error in getpwuid");
                        return;
                    }
                    gid_t group_id = fs.st_gid;
                    if (getgrgid(group_id) != NULL)
                    {
                        printf("%s ", getgrgid(group_id)->gr_name);
                    }
                    else
                    {
                        perror("error in getgrgid");
                        return;
                    }
                    off_t file_size = fs.st_size;
                    printf("%ld ", file_size);
                    if (J)
                    {
                        printf("%s%s\033[0m\n", KBLU, name_list[i]->d_name);
                    }
                    else
                    {
                        if (S_ISREG(fs.st_mode))
                        {
                            if (G)
                            {
                                printf("%s%s\033[0m\n", KGRN, name_list[i]->d_name);
                            }
                            else
                            {
                                printf("%s%s\033[0m\n", KWHT, name_list[i]->d_name);
                            }
                        }
                        else
                        {
                            printf("%s%s\033[0m\n", KYEL, name_list[i]->d_name);
                        }
                    }
                    free(name_list[i]);
                    path[len] = '\0';
                }
            }
            free(name_list);
        }
        else
        {
            INT R = 0;
            struct stat fs;
            R = stat(string1, &fs);
            if (R == -1)
            {
                perror("File error in file in type 2\n");
                exit(1);
            }
            INT E;
            INT G = fs.st_mode & S_IXUSR;
            E = S_ISDIR(fs.st_mode) ? printf("d") : printf("-");
            E = (fs.st_mode & S_IRUSR) ? printf("r") : printf("-");
            E = (fs.st_mode & S_IWUSR) ? printf("w") : printf("-");
            E = (fs.st_mode & S_IXUSR) ? printf("x") : printf("-");
            E = (fs.st_mode & S_IRGRP) ? printf("r") : printf("-");
            E = (fs.st_mode & S_IWGRP) ? printf("w") : printf("-");
            E = (fs.st_mode & S_IXGRP) ? printf("x") : printf("-");
            E = (fs.st_mode & S_IROTH) ? printf("r") : printf("-");
            E = (fs.st_mode & S_IWOTH) ? printf("w") : printf("-");
            E = (fs.st_mode & S_IXOTH) ? printf("x") : printf("-");
            printf("%ld ", fs.st_nlink);
            uid_t user_id = fs.st_uid;
            if (getpwuid(user_id) != NULL)
            {
                printf("%s ", getpwuid(user_id)->pw_name);
            }
            else
            {
                perror("error in getpwuid");
                return;
            }
            gid_t group_id = fs.st_gid;
            if (getgrgid(group_id) != NULL)
            {
                printf("%s ", getgrgid(group_id)->gr_name);
            }
            else
            {
                perror("error in getgrgid");
                return;
            }
            off_t file_size = fs.st_size;
            printf("%ld ", file_size);
            /*
Time
            */
            if (S_ISREG(fs.st_mode))
            {
                if (G)
                {
                    printf("%s%s\033[0m\n", KGRN, string1);
                }
                else
                {
                    printf("%s%s\033[0m\n", KWHT, string1);
                }
            }
            else
            {
                printf("%s%s\033[0m\n", KYEL, string1);
            }
        }
    }

    else if (type == 3) // both a and l
    {
        INT files = 0;
        // printf("type is %lld\n", type);
        INT num_directory_entries = scandir(string1, &name_list, NULL, alphasort);
        // printf("num_directories is %lld for %s\n", num_directory_entries, string);
        if (num_directory_entries == -1)
        {
            if (errno == ENOTDIR)
            {
                files = 1;
                // printf("%s is a file\n", string);
            }
            else
            {
                perror("scandir in type 3");
                exit(EXIT_FAILURE);
            }
        }
        if (num_args >= 2 && files != 1)
        {
            printf("%s:\n", string1);
        }

        struct stat fs;
        INT R = 0;
        if (!files)
        {
            for (INT i = 0; i < num_directory_entries; i++)
            {
                if (1)
                {
                    strcat(path, name_list[i]->d_name);
                    // printf("string 1 is %s,name_list is %s path is %s\n", string1, name_list[i]->d_name, path);
                    R = stat(path, &fs);
                    if (R == -1)
                    {
                        perror("File error in file in type 3\n");
                        exit(1);
                    }
                    INT E;
                    INT J = S_ISDIR(fs.st_mode);
                    INT G = fs.st_mode & S_IXUSR;
                    E = S_ISDIR(fs.st_mode) ? printf("d") : printf("-");
                    E = (fs.st_mode & S_IRUSR) ? printf("r") : printf("-");
                    E = (fs.st_mode & S_IWUSR) ? printf("w") : printf("-");
                    E = (fs.st_mode & S_IXUSR) ? printf("x") : printf("-");
                    E = (fs.st_mode & S_IRGRP) ? printf("r") : printf("-");
                    E = (fs.st_mode & S_IWGRP) ? printf("w") : printf("-");
                    E = (fs.st_mode & S_IXGRP) ? printf("x") : printf("-");
                    E = (fs.st_mode & S_IROTH) ? printf("r") : printf("-");
                    E = (fs.st_mode & S_IWOTH) ? printf("w") : printf("-");
                    E = (fs.st_mode & S_IXOTH) ? printf("x") : printf("-");
                    printf("%ld ", fs.st_nlink);
                    uid_t user_id = fs.st_uid;
                    if (getpwuid(user_id) != NULL)
                    {
                        printf("%s ", getpwuid(user_id)->pw_name);
                    }
                    else
                    {
                        perror("error in getpwuid");
                        return;
                    }
                    gid_t group_id = fs.st_gid;
                    if (getgrgid(group_id) != NULL)
                    {
                        printf("%s ", getgrgid(group_id)->gr_name);
                    }
                    else
                    {
                        perror("error in getgrgid");
                        return;
                    }
                    off_t file_size = fs.st_size;
                    printf("%ld ", file_size);
                    if (J)
                    {
                        printf("%s%s\033[0m\n", KBLU, name_list[i]->d_name);
                    }
                    else
                    {
                        if (S_ISREG(fs.st_mode))
                        {
                            if (G)
                            {
                                printf("%s%s\033[0m\n", KGRN, name_list[i]->d_name);
                            }
                            else
                            {
                                printf("%s%s\033[0m\n", KWHT, name_list[i]->d_name);
                            }
                        }
                        else
                        {
                            printf("%s%s\033[0m\n", KYEL, name_list[i]->d_name);
                        }
                    }

                    free(name_list[i]);
                    path[len] = '\0';
                }
                else
                {
                    perror("Error in print_ls function");
                    return;
                }
                // free(string1);
            }
            free(name_list);
        }
        else
        {
            INT R = 0;
            struct stat fs;
            R = stat(string1, &fs);
            if (R == -1)
            {
                perror("File error in file in type 2\n");
                exit(1);
            }
            INT E;
            INT G = fs.st_mode & S_IXUSR;
            E = S_ISDIR(fs.st_mode) ? printf("d") : printf("-");
            E = (fs.st_mode & S_IRUSR) ? printf("r") : printf("-");
            E = (fs.st_mode & S_IWUSR) ? printf("w") : printf("-");
            E = (fs.st_mode & S_IXUSR) ? printf("x") : printf("-");
            E = (fs.st_mode & S_IRGRP) ? printf("r") : printf("-");
            E = (fs.st_mode & S_IWGRP) ? printf("w") : printf("-");
            E = (fs.st_mode & S_IXGRP) ? printf("x") : printf("-");
            E = (fs.st_mode & S_IROTH) ? printf("r") : printf("-");
            E = (fs.st_mode & S_IWOTH) ? printf("w") : printf("-");
            E = (fs.st_mode & S_IXOTH) ? printf("x") : printf("-");
            printf("%ld ", fs.st_nlink);
            uid_t user_id = fs.st_uid;
            if (getpwuid(user_id) != NULL)
            {
                printf("%s ", getpwuid(user_id)->pw_name);
            }
            else
            {
                perror("error in getpwuid");
                return;
            }
            gid_t group_id = fs.st_gid;
            if (getgrgid(group_id) != NULL)
            {
                printf("%s ", getgrgid(group_id)->gr_name);
            }
            else
            {
                perror("error in getgrgid");
                return;
            }
            off_t file_size = fs.st_size;
            printf("%ld ", file_size);
            if (S_ISREG(fs.st_mode))
            {
                if (G)
                {
                    printf("%s%s\033[0m\n", KGRN, string1);
                }
                else
                {
                    printf("%s%s\033[0m\n", KWHT, string1);
                }
            }
            else
            {
                printf("%s%s\033[0m\n", KYEL, string1);
            }
        }
    }
}

void ls_func(char *string[], char *correct_path, long long int num_tokens)
{
    INT extra_info = 0;
    INT hidden = 0;
    INT num_commands = 0;
    INT total_commands = 0;
    for (INT i = 0; i < num_tokens; i++)
    {
        if (string[i][0] == '-')
        {
            total_commands++;

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
            total_commands++;
        }
    }
    if (extra_info)
    {
        if (hidden)
        {
            if (num_commands == 0)
            {
                print_ls(".", correct_path, 3, 0);
            }
            else
            {
                for (INT i = 0; i < num_tokens; i++)
                {
                    if (string[i][0] != '-')
                    {
                        print_ls(string[i], correct_path, 3, num_commands);
                    }
                }
            }
        }
        else
        {
            if (num_commands == 0)
            {
                print_ls(".", correct_path, 2, 0);
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
    }
    else
    {
        if (hidden)
        {
            if (num_commands == 0)
            {
                print_ls(".", correct_path, 1, 0);
            }
            else
            {
                for (INT i = 0; i < num_tokens; i++)
                {
                    if (string[i][0] != '-')
                    {
                        print_ls(string[i], correct_path, 1, num_commands);
                    }
                }
            }
        }
        else
        {
            if (num_commands == 0)
            {
                print_ls(".", correct_path, 0, 0);
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
}
