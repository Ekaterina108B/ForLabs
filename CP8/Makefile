all: compl_client
	valgrind --leak-check=yes -s ./client

compl_client: cp8.c object_iter object_linli
	gcc -std=c99 -pedantic -Wall -o client cp8.c iter.o linli.o

object_iter: iterator.c
	gcc -std=c99 -pedantic -Wall -c iterator.c -o iter.o

object_linli: linli.c
	gcc -std=c99 -pedantic -Wall -c linli.c -o linli.o

clean:
	rm -f iter.o
	rm -f linli.o
	rm -f client
