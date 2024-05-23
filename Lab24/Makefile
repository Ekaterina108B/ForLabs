all: compl_client
	valgrind --leak-check=yes -s ./client

compl_client: lab24.c object_tree
	gcc -std=c99 -pedantic -Wall -o client lab24.c add.o leaf.o tree.o h.o

object_tree: addfuncs.c leaf.c tree.c h.c
	gcc -std=c99 -pedantic -Wall -c addfuncs.c -o add.o
	gcc -std=c99 -pedantic -Wall -c leaf.c -o leaf.o
	gcc -std=c99 -pedantic -Wall -c tree.c -o tree.o
	gcc -std=c99 -pedantic -Wall -c h.c -o h.o


clean:
	rm add.o
	rm leaf.o
	rm tree.o
	rm h.o
	rm -f client
