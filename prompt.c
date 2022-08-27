#include "prompt.h"
#include "headers.h"
#include <string.h>
void prompt(char *char1, char *char2, char *char3, char *char4, char *char5)
{
   INT display_size = 1000;
   // printf("OS & NW TAs rock: ");
   char *display = (char *)calloc(display_size, sizeof(char));

   if (strstr(char1, char3) == 1)
   {
      char* curr_dir = (char *)calloc(300, sizeof(char));
      curr_dir.append
   }
   else
   {
      sprintf(display, "%s@%s:%s->", char4, char5, char1);
      write(1, display, strlen(display));
   }
}