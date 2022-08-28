#include "headers.h"
#include "prompt.h"
#include "process_command.h"
#include "cd.h"
#include "PWD.h"
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
    relative_path[0] = '-';
    relative_path[1] = '\0';
    char *input = (char *)calloc(1000, sizeof(char));
    char* ptr=input;
    while (1)
    {
        size_t size=100;
        char* semicolon=(char*)calloc(1,sizeof(char));
        semicolon[0]=';';
        prompt(absolute_path, relative_path, correct_path, user_name, system_name);
        
        char *tokens[1000];
        INT Y=getline(&ptr,&size,stdin);
        input[Y-1]='\0';
       //  printf("input is %s\n",input);
        INT token_count = 0;
        tokens[token_count] = strtok(input, semicolon);
       // printf("%s\n",tokens[0]);
        while (tokens[token_count] != NULL)
        {
            token_count++;
            tokens[token_count] = strtok(NULL, semicolon);
        }
        for(INT i=0;i<token_count;i++)
        {
            printf("%s\n",tokens[i]);
            process_command(tokens[i],relative_path,correct_path);
           // printf("Hello\n");
        }
        // TAKE INPUT HERE
    }
}