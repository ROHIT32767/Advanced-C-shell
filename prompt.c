#include "prompt.h"
#include "headers.h"
typedef long long int INT;
void prompt() {
   INT display_size=1000;
   // printf("OS & NW TAs rock: ");   
   char* display = (char*)calloc(display_size,sizeof(char));
   char* user_name=(char*)calloc(200,sizeof(char));
   char* system_name=(char*)calloc(200,sizeof(char));
   char* curr_dir=(char*)calloc(200,sizeof(char));
   user_name=get_pwnam();
   sprintf(display,"%s@%s:%s->",user_name,system_name,curr_dir);
   write(1,display, strlen(display));
}