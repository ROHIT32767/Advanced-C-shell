#include "headers.h"
void prompt(char *absolute, char *relative, char *correct, char *user, char *system,char* time)
{
   INT display_size = 1000;
   // printf("OS & NW TAs rock: ");
   char *display = (char *)calloc(display_size, sizeof(char));
   sprintf(display,"<%s%s@%s:%s%s>\033[0m",KMAG,user,system,relative,time);
   write(1,display,strlen(display));
}
/*
   // char *p = strstr(absolute, char3);

   // if (p)
   // {
   //    INT len1 = strlen(absolute);
   //    INT len2 = strlen(char3);
   //    char *curr_dir = (char *)calloc(len1 - len2 + 1, sizeof(char));
   //    curr_dir[0] = '-';
   //    INT i=1;
   //    for (i = 1; i <= len1 - len2; i++)
   //    {
   //       curr_dir[i] = absolute[len2 + i - 1];
   //    }
   //    curr_dir[i] = '\0';
   //    sprintf(display, "%s@%s:%s->", char4, char5,curr_dir);
   //    write(1, display, strlen(display));
   // }
   // else
   // {
   //    sprintf(display, "%s@%s:%s->", char4, char5, absolute);
   //    write(1, display, strlen(display));
   // }
*/