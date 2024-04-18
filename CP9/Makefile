all: compl_client
	valgrind --leak-check=yes -s ./client

compl_client: cp9.c object_table
	gcc -std=c99 -pedantic -Wall -o client cp9.c table.o

object_table: table.c
	gcc -std=c99 -pedantic -Wall -c table.c -o table.o


clean:
	rm -f table.o
	rm -f client
