#include "prompt.h"
#include "headers.h"
typedef long long int INT;
int main()
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
    relative_path = "-";
    while (1)
    {
        prompt(absolute_path, relative_path, correct_path, user_name, system_name);
        char a[20];
        scanf("%s", a);
        // TAKE INPUT HERE
    }
}