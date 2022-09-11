#ifndef __PIPE_H
#define __PIPE_H
#include "headers.h"
long long int str_tok_pipe(char* string[],char* string1);
void pipe_to_process_command(char* string,char* string1,char* string2,char* string3,long long int len,long long int last,List* LIST);

#endif