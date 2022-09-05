#include <stdio.h>
#include <errno.h>
extern int errno;
int main(void)
{
    errno = 0;
    perror(NULL);
    return 0;
}
