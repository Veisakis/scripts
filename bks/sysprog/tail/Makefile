# -*- MakeFile -*-

install: tail.o isnumber.o getLine.o shiftarray.o
	gcc tail.o isnumber.o getLine.o shiftarray.o -o tail

tail.o: tail.c tail.h
	gcc -c tail.c

shiftarray.o: shiftarray.c
	gcc -c shiftarray.c

isnumber.o: isnumber.c
	gcc -c isnumber.c

getLine.o: getLine.c
	gcc -c getLine.c

clean:
	rm -f *.o tail tail.h.gch
