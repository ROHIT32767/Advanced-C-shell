#include "headers.h"
INT num_bg_processes;
time_t start_seconds;
typedef long long int INT;
List *LIST;
char* correct_path;
char *previous_path;
char *relative_path;
char *absolute_path;
char* user_name;
char* system_name;

int main(int argc, char *argv[])
{
    absolute_path = (char *)calloc(300, sizeof(char));
    relative_path = (char *)calloc(300, sizeof(char));
    previous_path = (char *)calloc(300, sizeof(char));
    correct_path = (char *)calloc(300, sizeof(char));
    user_name = (char *)calloc(200, sizeof(char));
    system_name = (char *)calloc(200, sizeof(char));
    char *Time = (char *)calloc(300, sizeof(char));
    Time[0] = '\0';
    LIST = (List *)malloc(sizeof(List));
    LIST->root = NULL;
    LIST->tail = NULL;
    previous_path[0] = '#';
    previous_path[1] = '\0';
    getcwd(absolute_path, 300);
    getcwd(correct_path, 300);
    user_name = getlogin();
    gethostname(system_name, 200);
    relative_path[0] = '~';
    relative_path[1] = '\0';
    char *input = (char *)calloc(1000, sizeof(char));
    char *ptr = input;
    num_bg_processes = 0;
    while (1)
    {
        size_t size = 100;
        // char *semicolon = (char *)calloc(1, sizeof(char));
        // semicolon[0] = ';';
        prompt(Time);
        char *tokens[1000];
        INT Y = getline(&ptr, &size, stdin);
        time(&start_seconds);
        input[Y - 1] = '\0';
        //  printf("input is %s\n",input);
        INT token_count = 0;
        char *p = strstr(input, ";;");
        if (p)
        {
            perror("syntax error near unexpected token `;;'");
        }
        else
        {
            tokens[token_count] = strtok(input, ";");
            INT length = strlen(input);
            // printf("%s\n",tokens[0]);
            while (tokens[token_count] != NULL)
            {
                token_count++;
                tokens[token_count] = strtok(NULL, ";");
            }
            //  printf("token count is %lld\n", token_count);
            for (INT i = 0; i < token_count; i++)
            {
                // printf("%s\n",tokens[i]);
                str_tok_and(tokens[i], relative_path, correct_path, previous_path, length, LIST);
            }
        }
        num_bg_processes = 0;
        time_t end_time;
        time(&end_time);
        long int U=end_time - start_seconds;
        if (U >= 1)
        {
            Time[0] = '\0';
            sprintf(Time,"took %lds",U);
        }
        else
        {
            Time[0]='\0';
        }
    }
}