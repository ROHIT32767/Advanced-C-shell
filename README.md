# Assignment-3
# 2021101113
# Operating Systems and Networks, Monsoon 2022
# creating a user-defined interactive shell program 
# Gowlapalli Rohit

>##### All these commands are tested on Ubuntu Version 20.04.3 LTS (Focal Fossa) 
```
2021101113_Assignment3
├── autocompletion.c
├── autocompletion.h
├── bg.c
├── bg.h
├── cd.c
├── cd.h
├── ctrlc.c
├── ctrlc.h
├── ctrlz.c
├── ctrlz.h
├── discover.c
├── discover.h
├── echo.c
├── echo.h
├── fg.c
├── fg.h
├── headers.h
├── history.c
├── history.h
├── history.txt
├── io_redirection.c
├── io_redirection.h
├── jobs.c
├── jobs.h
├── linked_list.c
├── linked_list.h
├── linked_main.c
├── ls.c
├── ls.h
├── main.c
├── makefile
├── pinfo.c
├── pinfo.h
├── pipe.c
├── pipe.h
├── process_command.c
├── process_command.h
├── prompt.c
├── prompt.h
├── PWD.c
├── PWD.h
├── README.md
├── sig.c
├── sig.h
├── sig_handler.c
├── sig_handler.h
├── spec4.c
├── spec4.h
├── str_tok_and.c
└── str_tok_and.h

```

* >Commands to be executed

 `$ make`  
 `$ ./main`
* > Neglect all warnings during execution of make file-they are just errors due to unused variables
<hr>

* >
|File name|Purpose|Features|Related Functions|
|:--------:|:-----:|:------:|:---------------:|
|main.c|Extracts input from commandline and Runs Shell Loop|Tokenises the input with delimiter ";" & handles ctrld comand & handles invalid syntax|main() & strtok()|
|prompt.c|Prints Prompt|Handles time taken by a foreground process|prompt()|
|str_tok_and.c|Handles the criterion for an input commnad to be background/foreground|Tokenises its input with the delimiter "&"|str_tok_and(),strtok()|
|pipe.c|Handles Command PipeLines|Tokenises its input with the delimiter "\|\"|pipe_to_process_command() & str_tok_pipe() & strtok()|
|process_command.c|Calls all implemented command functions|Handles I/O Redirection & Tokenises its input with " "|str_tok_whitespaces() & strtok()|
|cd.c|Implements cd command|Changes the Directory|cd_func() & chdir() & getcwd()|
|PWD.c|Implements pwd command|Prints name of current working directory|pwd_func() & getcwd()|
|ls.c|Implements ls command|Lists Directory contents|print_ls() & scandir() & lstat() & qsort() & getpwuid() & getgrgid() & time()|
|echo.c|Implements echo command|Writes arguments to standard output|echo_func()|
|pinfo.c|Implements pinfo command|Reads info files|pinfo() & readlink() & fopen()|
|history.c|Implements history command|Displays GNU History Library|print_history() & readfromhistory() & writetohistory() & fopen()|
|discover.c|Implements discover command|Searches for files/directories in a directory hierarchy|discover() & dfs() & opendir() & readdir() & stat()|
|spec4.c|Implements commands in bg/fg|Runs/Terminates processes in bg/fg|bg_func() & fg_func() & signal() & fork() & execvp() & waitpid()|
|jobs.c|Prints info related to list of all currently running bg processes spawned by shell|Lists commandnames in alphabetical order with pid & status|jobs() & fopen()|
|sig.c|Takes job number of running job & sends signal corresponding to the signal number to process|Throws error if no job with given number exists|sig_func() & kill()|
|fg.c|Brings running/stopped bg job corresponding to job number to fg & changes its state to running|Throws an error if no job with given job number exists|FG() & signal() & tcsetpgrp() & setpgid() & kill() & getpgid()|
|bg.c|Changes the state of a stopped background job to running|Throws error if no background job corresponding to given job number exists|BG() & kill()|
|ctrlc.c|Interrupts any currently running fg job|Has no effect on the shell if no fg process is running|ctrlc() & sprintf() & write() & fflush()|
|ctrlz.c|pushes any currently running fg job into the bg & changes its state from running to stopped|Has no effect on the shell if no fg process is running|ctrlz() & sprintf() & write() & fflush()|
|autocompletion.c|When tab key is pressed ,it prints all files which have same starting letters as ls command and then again show the same prompt|If there is only 1 file/folder which has the same starting characters, the prompt will be filled with that|autocomplete() & scandir() & qsort() & stat()|
|history.txt|Used to implement history command|Stores each new command on a new line|-|


```

Specification 1:Input/Output Redirection

Assumptions:

1) It is assumed that a command belongs to only one of the following 9 possible commands
   a) arg1 > arg2
   b) arg1 < arg2
   c) arg1 >> arg2 
   d) arg1 > arg2 < arg3
   e) arg1 < arg2 > arg3
   f) arg1 >> arg2 < arg3
   g) arg1 >> arg2 > arg3
   h) arg1 > arg2 >> arg3
   i) arg1 < arg2 >> arg3
2) Input is tokenised with following delimiters in order (";","&","|"," ")
3) It is assumed that >/</>> are obtained as seperate tokens after tokenising through all delimiters


```
```

Specification 2: : Command Pipelines

Command format : arg1 | arg2 | arg3 |.........| argn  (where argi!=(/t+/r+/n+' ')* for all i such that 1<=i<=n)
Assumptions:
a) It is assumed that number of tokens obtained after tokenising input with "|" <=1000
b) Any error in pipelining would result in display of perror()
c) Piped commands are not executed concurrently (not using fork() as waitpid() must be used which is equivalent to not using fork())


```
```

Specification 3:  I/O Redirection within Command Pipelines
Assumptions:
a) Input is tokenised with following delimiters in order (";","&","|"," ")
b) Use of * may not be advisable

```
```

Specification 4:  User-defined Commands

Command Type-jobs:

Valid command : jobs / jobs -r / jobs -s

a) list of all currently running background processes is sorted w.r.t main-command (for example : "sleep" in "sleep 30")

b) It is assumed that if the state of a job is not "stopped",then its state is "running"

c) It is assumed that strlen(/proc/stat/<pid>)<=800

Command Type-sig:

Valid command : sig <job number> <signal number>

a) perror() is displayed if the supplied job number is invalid / invalid syntax in sig command

Command Type-fg:

Valid command : fg <job number> 

a) perror() is displayed if the supplied job number is invalid / invalid syntax in sig command

Command Type-bg:

Valid command : bg <job number> 

a) perror() is displayed if the supplied job number is invalid / invalid syntax in sig command


```
```

Specification 5: : Signal Handling 

Command Type- CTRL-Z:
a) New prompt is printed if there is no foreground process running
b) pushes any currently running foreground job into the background, and changes its state from ‘running’ to ‘stopped.’ 

Command Type- CTRL-C:
a) Only 1 currently running foreground job is interrupted in a set of multiple of foreground job commands per CTRL-C command
b) New prompt is printed if there is no foreground process running
c) interrupts any currently running foreground job, by sending it the SIGINT signal

Command Type- CTRL-D:
a) Code for CTRL-D is handled in the Raw-mode Driver code (^D is not displayed on executing this command)
b) logs out of the shell , without having any effect on the actual terminal.

```
```
Specification 6: Autocompletion

a) "." and ".." are omitted for consideration to match prefix of names of directory entries and these both directory entries are not autocompleted if tried to do so
b) <inbuilt command> <tab> cases are not handled (Like ls <tab> autocompletes to ls.txt if there is a file in the current directory called "ls.txt")
c) When <tab> key is pressed
  i) If there is only one file/folder which has the same starting characters, the prompt is filled with that
    I) If it's a file, a space is placed after the file 
    II) If it’s a folder, a ‘/’ is put after the folder name
  ii) else
     all directory_entry_names are printed which have the same starting letters (as the ls command) and then same prompt is showed again(autocompleted to common prefix)
d) Cases having spaces between tokens are also handled (except the cases in (b))
e) autocomplete involving '/' as path is not handled (root)
f) If no matching entries are found, cursor remains in its earlier position ( sound is not implemented )
g) If <tab> is pressed with an whitespace-string as input , then all directory entries are printed (except "." and "..")
h) hidden files are considered as valid directory entries unlike "." and ".."

```