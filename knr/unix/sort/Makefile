# -*- MakeFile -*-

install: sort.o strcomp.o strtolower.o numcmp.o getLine.o qsort.o readlines.o alloc.o reverse.o
	gcc sort.o numcmp.o strcomp.o getLine.o strtolower.o qsort.o readlines.o alloc.o reverse.o -o sort

strcomp.o: strcomp.c
	gcc -c strcomp.c

strtolower.o: strtolower.c
	gcc -c strtolower.c

reverse.o: reverse.c
	gcc -c reverse.c

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
