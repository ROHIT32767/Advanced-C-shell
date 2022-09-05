// #include "headers.h"
// INT discovery_input = 0; // for discovery folder
// char *current_directory;
// INT tilder = 0;
// INT find_folder = 0;
// char *find_folder_path;
// void dfs(char *dir_path, char *find_path, int directory, int file, int len)
// {
//     struct dirent *dirnt;
//     DIR *dr = opendir(dir_path);
//     printf("%s\n", dir_path);
//     if (dr == NULL)
//     {
//         perror("couldnt open current directory");
//     }
//     if (discovery_input)
//     {
//         if (tilder)
//         {
//             INT X = strlen(current_directory);
//             printf("~%s\n", &dir_path[X]);
//             discovery_input=0;
//         }
//         else
//         {
//             printf("%s\n", dir_path);
//             discovery_input=0;
//         }
//     }
//    // printf("%s\n", dir_path);
//     while ((dirnt = readdir(dr)) != NULL)
//     {
//         struct stat fs;
//         char *string4 = (char *)calloc(600, sizeof(char));
//         strcat(string4, dir_path);
//         strcat(string4, "/");
//         strcat(string4, dirnt->d_name);
//         INT R = stat(string4, &fs);
//         if (R == -1)
//         {
//             perror("File error in file in type DFS\n");
//             exit(1);
//         }
//         INT J = S_ISDIR(fs.st_mode);
//         if (J)
//         {
//             if (!find_folder)
//             {
//                 if (find_path == NULL)
//                 {
//                     if (directory)
//                     {
//                         char *string2 = (char *)calloc(600, sizeof(char));
//                         strcat(string2, dir_path);
//                         strcat(string2, "/");
//                         strcat(string2, dirnt->d_name);
//                         printf("%s\n", string2);
//                         free(string2);
//                     }
//                 }
//             }
//             else
//             {
//                 if (directory)
//                 {
//                     if (strcmp(dirnt->d_name, find_path) == 0)
//                     {
//                         char *string2 = (char *)calloc(600, sizeof(char));
//                         string2[0] = '.';
//                         string2[1] = '\0';
//                         strcat(string2, "/");
//                         strcat(string2, dirnt->d_name);
//                         printf("%s\n", string2);
//                         free(string2);
//                     }
//                 }
//             }

//             if ((strcmp(dirnt->d_name, ".") != 0) && (strcmp(dirnt->d_name, "..") != 0))
//             {
//                 int len = strlen(dir_path);
//                 strcat(dir_path, "/");
//                 strcat(dir_path, dirnt->d_name);
//                 dfs(dir_path, find_path, directory, file, strlen(dir_path));
//                 dir_path[len] = '\0';
//             }
//         }
//         else
//         {

//             if (S_ISREG(fs.st_mode))
//             {
//                 if (find_path != NULL)
//                 {
//                     if (file)
//                     {
//                         if (strcmp(dirnt->d_name, find_path) == 0)
//                         {
//                             char *string1 = (char *)calloc(600, sizeof(char));
//                             strcat(string1, dir_path);
//                             strcat(string1, "/");
//                             strcat(string1, dirnt->d_name);
//                             printf("%s\n", string1);
//                             free(string1);
//                         }
//                     }
//                 }
//                 else if (file)
//                 {
//                     char *string1 = (char *)calloc(600, sizeof(char));
//                     strcat(string1, dir_path);
//                     strcat(string1, "/");
//                     strcat(string1, dirnt->d_name);
//                     printf("%s\n", string1);
//                     free(string1);
//                 }
//             }
//         }
//         free(string4);
//     }
// }
// void discover_func(char *string[], char *correct_path, long long int num_tokens)
// {
//     INT directory = 0;
//     INT file = 0;
//     INT num_commands = 0;
//     INT total_commands = 0;
//     current_directory = (char *)calloc(800, sizeof(char));
//     strcpy(current_directory, correct_path);
//     current_directory[strlen(correct_path)] = '\0';
//     if (num_tokens >= 4)
//     {
//         perror("Too many arguments to command discover");
//         return;
//     }
//     for (INT i = 0; i < num_tokens; i++)
//     {
//         if (string[i][0] == '-')
//         {
//             total_commands++;

//             if (strcmp(string[i], "-d") == 0)
//             {
//                 directory = 1;
//             }
//             else if ((strcmp(string[i], "-f") == 0))
//             {
//                 file = 1;
//             }
//             else
//             {
//                 perror("Incorrect argument supplied to command ls");
//                 return;
//             }
//         }
//         else
//         {
//             num_commands++;
//             total_commands++;
//         }
//     }
//     INT file_input = 0;
//     char *given_file = (char *)calloc(600, sizeof(char));
//     given_file[0] = '\0';
//     for (INT i = 0; i < num_tokens; i++)
//     {
//         if (string[i][0] == '"')
//         {
//             INT length5 = strlen(string[i]);
//             strcat(given_file, &string[i][1]);
//             given_file[length5 - 2] = '\0';
//             file_input = 1;
//             find_folder = 1;
//             break;
//         }
//     }
//     if (file_input)
//     {
//         if (num_tokens == 1) // discover file
//         {
//             char *string3 = (char *)calloc(800, sizeof(char));
//             string3[0] = '.';
//             string3[1] = '\0';
//             INT len = strlen(string3);
//             dfs(string3, given_file, 0, 1, len);
//             free(string3);
//         }
//         else if (num_tokens == 2)
//         {
//             if (file) // discover -f file
//             {
//                 char *string3 = (char *)calloc(800, sizeof(char));
//                 string3[0] = '.';
//                 string3[1] = '\0';
//                 INT len = strlen(string3);
//                 dfs(string3, given_file, 0, 1, len);
//                 free(string3);
//             }
//             else
//             {
//                 if (!directory) // discover folder file
//                 {
//                     char *s1 = (char *)calloc(600, sizeof(char));
//                     s1[0] = '\0';
//                     if (string[0][0] == '~')
//                     {
//                         strcat(s1, correct_path);
//                         strcat(s1, &string[0][1]);
//                     }
//                     else
//                     {
//                         strcpy(s1, string[0]);
//                     }
//                     char *s2 = (char *)calloc(600, sizeof(char));
//                     s2[0] = '\0';
//                     if (given_file[0] == '~')
//                     {
//                         strcat(s2, correct_path);
//                         strcat(s2, &given_file[1]);
//                     }
//                     else
//                     {
//                         strcpy(s2, &given_file[0]);
//                     }
//                     INT len = strlen(s1);
//                     dfs(s1, s2, 0,1, len);
//                     free(s1);
//                     free(s2);
//                 }
//                 else
//                 {
//                     char *string3 = (char *)calloc(800, sizeof(char));
//                     string3[0] = '.';
//                     string3[1] = '\0';
//                     INT len = strlen(string3);
//                     find_folder = 1;
//                     dfs(string3, given_file, 1, 0, 1);
//                     find_folder = 0;
//                 }
//             }
//         }
//         else if (num_tokens == 3) // discover folder -f a.txt
//         {
//             if (file && (!directory))
//             {
//                 char *s1 = (char *)calloc(600, sizeof(char));
//                 s1[0] = '\0';
//                 if (string[0][0] == '~')
//                 {
//                     tilder = 1;
//                     strcat(s1, correct_path);
//                     strcat(s1, &string[0][1]);
//                     char *s2 = (char *)calloc(600, sizeof(char));
//                     s2[0] = '\0';
//                     if (given_file[0] == '~')
//                     {
//                         strcat(s2, correct_path);
//                         strcat(s2, &given_file[1]);
//                     }
//                     else
//                     {
//                         strcpy(s2, &given_file[0]);
//                     }
//                     INT len = strlen(s1);
//                     dfs(s1, s2, 0, 0, len);
//                     free(s1);
//                     free(s2);
//                     tilder = 0;
//                 }
//                 else
//                 {
//                     strcpy(s1, string[0]);
//                     char *s2 = (char *)calloc(600, sizeof(char));
//                     s2[0] = '\0';
//                     if (given_file[0] == '~')
//                     {
//                         strcat(s2, correct_path);
//                         strcat(s2, &given_file[1]);
//                     }
//                     else
//                     {
//                         strcpy(s2, &given_file[0]);
//                     }
//                     INT len = strlen(s1);
//                     dfs(s1, s2, 0, 0, len);
//                     free(s1);
//                     free(s2);
//                 }
//             }
//             else
//             {
//                 perror("discover <directory> -d file / discover -f -d file is not allowed");
//                 return;
//             }
//         }
//     }
//     else
//     {
//         if ((num_tokens == 0) || (((num_tokens == 2) && (file) && (directory)))) // discovery ,discovery -f -d
//         {
//             // printf("num_tokens is %lld\n", num_tokens);
//             char *string3 = (char *)calloc(800, sizeof(char));
//             string3[0] = '.';
//             string3[1] = '\0';
//             discovery_input = 1;
//             INT len = strlen(string3);
//             dfs(string3, NULL, 1, 1, len);
//             discovery_input = 0;
//             free(string3);
//         }
//         else if (num_tokens == 1) // discovery -f,discovery -d,discovery folder
//         {
//             char *string3 = (char *)calloc(800, sizeof(char));
//             string3[0] = '.';
//             string3[1] = '\0';
//             INT len = strlen(string3);
//             if (directory)
//             {
//                 dfs(string3, NULL, 1, 0, len);
//             }
//             else if (file)
//             {
//                 dfs(string3, NULL, 0, 1, len);
//             }
//             else
//             {
//                 discovery_input = 1;
//                 dfs(string[0],NULL, 1, 1, len);
//                 discovery_input = 0;
//             }
//         }
//         else if (num_tokens == 2) // discover folder -f ,discover folder -d
//         {
//             if (file)
//             {
//                 if (string[0][0] == '~')
//                 {
//                     char *s = (char *)calloc(600, sizeof(char));
//                     s[0] = '\0';
//                     tilder = 1;
//                     strcat(s, correct_path);
//                     strcat(s, "/");
//                     strcat(s, &string[0][1]);
//                     dfs(s, NULL, 0, 1, strlen(s));
//                     tilder = 0;
//                     free(s);
//                 }
//                 else
//                 {
//                     dfs(string[0], NULL, 0, 1, strlen(string[0]));
//                 }
//             }
//             else if (directory)
//             {
//                 char *string3 = (char *)calloc(800, sizeof(char));
//                 string3[0] = '.';
//                 string3[1] = '\0';
//                 INT len = strlen(string3);
//                 find_folder = 1;
//                 find_folder_path = (char *)calloc(600, sizeof(char));
//                 strcpy(find_folder_path, &string[0][0]);
//                 find_folder_path[(strlen(find_folder_path))] = '\0';
//                 dfs(string3, NULL, 1, 0, 1);
//                 free(find_folder_path);
//                 find_folder = 0;
//             }
//         }
//         else if (num_tokens == 3) // discover folder -d -f
//         {
//             char *s1 = (char *)calloc(600, sizeof(char));
//             s1[0] = '\0';
//             if (string[0][0] == '~')
//             {
//                 tilder = 1;
//                 strcat(s1, correct_path);
//                 strcat(s1, &string[0][1]);
//                 INT len = strlen(s1);
//                 dfs(s1, NULL, 1, 1, len);
//                 free(s1);
//             }
//             else
//             {
//                 strcpy(s1, string[0]);
//                 INT len = strlen(s1);
//                 dfs(s1, NULL, 1, 1, len);
//                 free(s1);
//             }
//         }
//     }
// }





/*
// else
            // {
            //     char *s1 = (char *)calloc(600, sizeof(char));
            //     s1[0] = '\0';
            //     if (string[0][0] == '~')
            //     {

            //         strcat(s1, correct_path);
            //         strcat(s1, &string[0][1]);
            //     }
            //     else
            //     {
            //         strcpy(s1, string[0]);
            //     }
            //     char *s2 = (char *)calloc(600, sizeof(char));
            //     s2[0] = '\0';, len);
            //     free(s1);
            //     free(s2);
            // }

// if (string[0][0] == '~')
                // {
                //     char *s = (char *)calloc(600, sizeof(char));
                //     s[0] = '\0';
                //     strcat(s, correct_path);
                //     strcat(s, &string[0][1]);
                //     tilder = 1;
                //     dfs(s, NULL, 0, 1, strlen(s));
                //     tilder = 0;
                //     free(s);
                // }
                // else
                // {
*/