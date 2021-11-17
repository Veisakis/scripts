# -*- MakeFile -*-

install: sort.o numcmp.o getLine.o qsort.o readlines.o alloc.o
	gcc sort.o numcmp.o getLine.o qsort.o readlines.o alloc.o -o sort

sort.o: sort.c sort.h
	gcc -c sort.c

qsort.o: qsort.c
	gcc -c qsort.c

numcmp.o: numcmp.c
	gcc -c numcmp.c

alloc.o: alloc.c
	gcc -c alloc.c

readlines.o: readlines.c
	gcc -c readlines.c

getLine.o: getLine.c
	gcc -c getLine.c

clean:
	rm -f *.o sort sort.h.gch
