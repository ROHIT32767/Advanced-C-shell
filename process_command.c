#include "headers.h"
INT str_tok_whitespaces(char *tokens[], char *input)
{
    long long int Token_count = 0;
    tokens[Token_count] = strtok(input, ';');
    while (tokens[Token_count] != NULL)
    {
        Token_count++;
        tokens[Token_count] = strtok(NULL, ';');
    }
    return Token_count;
}
void process_command(char *string,char* relative,char* correct)
{
    char *token[1000];
    INT num_tokens=str_tok_whitespaces(token, string);
    if(strcmp(token[0],"cd")==0)
    {
        cd_func(&token[1],num_tokens,relative,correct);
    }


}