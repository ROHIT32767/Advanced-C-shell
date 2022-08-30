flags = -pedantic -Wall -g

main: main.c prompt.o cd.o str_tok_and.o process_command.o PWD.o echo.o ls.o
	gcc main.c *.o -o main
# main: main.c getinfo.o prompt.o cd.o print_error.o command_helper.o pwd.o echo.o ls.o process_creation.o my_dll.o node.o

# getinfo.o: ./Helpers/getinfo.c
#     gcc $(flags) -c ./Helpers/getinfo.c

prompt.o: ./prompt.c
	gcc $(flags) -c ./prompt.c

cd.o: ./cd.c
	gcc $(flags) -c ./cd.c

str_tok_and.o: ./str_tok_and.c
	gcc $(flags) -c ./str_tok_and.c

process_command.o: ./process_command.c
	gcc $(flags) -c ./process_command.c

PWD.o: PWD.c
	gcc $(flags) -c ./PWD.c

echo.o: ./echo.c
	gcc $(flags) -c ./echo.c

ls.o: ./ls.c
	gcc $(flags) -c ./ls.c

# process_creation.o: ./Helpers/process_creation.c
#     gcc $(flags) -c ./Helpers/process_creation.c

# my_dll.o: ./Linked_list/my_dll.h ./Linked_list/my_dll.c
#     gcc $(flags) -c ./Linked_list/my_dll.c

# node.o: ./Linked_list/node.h ./Linked_list/node.c
#     gcc $(flags) -c ./Linked_list/node.c

# clean:
#     rm *.o