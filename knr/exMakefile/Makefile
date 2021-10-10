# -*- MakeFile -*-

main: main.o strip.o getLine.o
	gcc main.o strip.o getLine.o -o main

main.o: main.c line.h
	gcc -c main.c

strip.o: strip.c
	gcc -c strip.c

getLine.o: getLine.c
	gcc -c getLine.c

clean:
	rm *.o main
