#include "prompt.h"
#include "headers.h"
#include <string.h>
void prompt(char *char1, char *char2, char *char3, char *char4, char *char5)
{
   INT display_size = 1000;
   // printf("OS & NW TAs rock: ");
   char *display = (char *)calloc(display_size, sizeof(char));
   char *p = strstr(char1, char3);

   if (p)
   {
      INT len1 = strlen(char1);
      INT len2 = strlen(char3);
      char *curr_dir = (char *)calloc(len1 - len2 + 1, sizeof(char));
      curr_dir[0] = '-';
      INT i=1;
      for (i = 1; i <= len1 - len2; i++)
      {
         curr_dir[i] = char1[len2 + i - 1];
      }
      curr_dir[i] = '\0';
      sprintf(display, "%s@%s:%s->", char4, char5,curr_dir);
      write(1, display, strlen(display));
   }
   else
   {
      sprintf(display, "%s@%s:%s->", char4, char5, char1);
      write(1, display, strlen(display));
   }
}