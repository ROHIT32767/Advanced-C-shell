#include "headers.h"
void prompt(char *absolute, char *relative, char *correct, char *user, char *system,char* time)
{
   INT display_size = 1000;
   // printf("OS & NW TAs rock: ");
   char *display = (char *)calloc(display_size, sizeof(char));
   sprintf(display,"%s<%s@%s:%s%s>\033[0m",KMAG,user,system,relative,time);
   write(1,display,strlen(display));
}
