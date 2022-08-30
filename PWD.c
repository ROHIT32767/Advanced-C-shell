#include "headers.h"
void pwd_func(INT arguments)
{
    // if(arguments!=0)
    // {
    //     perror("INcorrect number of arguments supplied to command pwd");
    //     return;
    // }
    char* PWD=(char*)calloc(400,sizeof(char));
    getcwd(PWD,400);
    printf("%s%s\033[0m\n",KYEL,PWD);
    free(PWD);
}