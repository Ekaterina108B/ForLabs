all: compl_gen compl_print compl_exe
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./gen input output
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./print output
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output

tests: compl_gen compl_exe
	./gen input output
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
	./gen input2 output
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
	./gen input3 output
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
	./gen input4 output
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
	./gen input5 output
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
	

compl_gen: io.o generate.o
	gcc -std=c99 -pedantic -Wall -o gen io.o generate.o
	
compl_print: io.o generate.o print.o
	gcc -std=c99 -pedantic -Wall -o print io.o print.o

compl_exe:  io.o generate.o execute.o
	gcc -std=c99 -pedantic -Wall -o exe io.o execute.o

object_gen: generate.c
	gcc -std=c99 -pedantic -Wall -c generate.c -o generate.o

object_print: print.c
	gcc -std=c99 -pedantic -Wall -c print.c -o print.o

object_exe: execute.c
	gcc -std=c99 -pedantic -Wall -c execute.c -o execute.o

object_io: io.c
	gcc -std=c99 -pedantic -Wall -c io.c -o io.o

clean:
	rm -f *.o

cleanall:
	rm -f *.o
	rm -f gen print exe

