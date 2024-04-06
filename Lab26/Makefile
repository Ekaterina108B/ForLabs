all: compl_client
	valgrind --leak-check=yes -s ./client

compl_client: lab26.c object_deq object_lab
	gcc -std=c99 -pedantic -Wall -o client client.c deq.o lab.o

object_deq: deq.c
	gcc -std=c99 -pedantic -Wall -c deq.c -o deq.o

object_lab: lab26.c
	gcc -std=c99 -pedantic -Wall -c lab26.c -o lab.o

clean:
	rm -f deq.o
	rm -f lab.o
	rm -f client
