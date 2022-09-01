#ifndef __HEADER_H
#define __HEADER_H
#include <stdio.h>    
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include "time.h"
#include <sys/wait.h>
#include "prompt.h"
#include "str_tok_and.h"
#include "process_command.h"
#include "spec4.h"
#include "cd.h"
#include "PWD.h"
#include "echo.h"
#include "ls.h"
#include "linked_list.h"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
typedef long long int INT;
#endif

