#include "headers.h"
void str_tok_and(char *string, char *relative, char *correct, char *previous, INT len)
{
    char *tokens[1000];
    INT token_count = 0;
    INT Background = 0;
    INT found = 1;
    INT index = -1;
    INT string_length = strlen(string);
    for (INT i = string_length - 1; i >= 0; i--)
    {
        if ((string[i] == '&') && found)
        {
            Background = 1;
            found = 0;
            index=i;
            break;
        }
    }
    char * final_string=(char*)calloc(600,sizeof(char));
    strncpy(final_string,string,index);
    strcat(final_string," ");
    strcat(final_string,&string[index]);
    INT final_length=strlen(final_string);
    final_string[final_length]='\0';
    tokens[token_count] = strtok(final_string, "&");
    // printf("%s\n",tokens[0]);
    while (tokens[token_count] != NULL)
    {
        token_count++;
        tokens[token_count] = strtok(NULL, "&");
    }
    for (INT i = 0; i < token_count-1; i++)
    {
        // printf("%s\n",tokens[i]);
        process_command(tokens[i], relative, correct, previous, len,0);
    }
    process_command(tokens[token_count-1], relative, correct, previous, len,1);
}