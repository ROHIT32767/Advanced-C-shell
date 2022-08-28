#include "prompt.h"
#include "headers.h"
typedef long long int INT;
int main(int argc, char *argv[])
{
    char *absolute_path = (char *)calloc(300, sizeof(char));
    char *relative_path = (char *)calloc(300, sizeof(char));
    char *correct_path = (char *)calloc(300, sizeof(char));
    char *user_name = (char *)calloc(200, sizeof(char));
    char *system_name = (char *)calloc(200, sizeof(char));
    getcwd(absolute_path, 300);
    getcwd(correct_path, 300);
    user_name = getlogin();
    gethostname(system_name, 200);
    relative_path = "-";
    while (1)
    {
        prompt(absolute_path, relative_path, correct_path, user_name, system_name);
        char *input = (char *)calloc(1000, sizeof(char));
        char *tokens[1000];
        scanf("%s", input);
        INT token_count = 0;
        tokens[token_count] = strtok(input, ';');
        while (tokens[token_count] != NULL)
        {
            token_count++;
            tokens[token_count] = strtok(NULL, ';');
        }
        for(INT i=0;i<=token_count;i++)
        {
            process_command(tokens[i]);
        }
        // TAKE INPUT HERE
    }
}