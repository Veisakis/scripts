#include <stdio.h>
#include <string.h>
#include "sort.h"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int nocaps = 0;

int main(int argc, char *argv[]){
	char c;
	int nlines;

	int numeric = 0;
	int reversed = 0;

	while (--argc > 0){
		if ( (*++argv)[0] == '-' )
			while (c = *++argv[0])
				switch (c){
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reversed = 1;
					break;
				case 'f':
					nocaps = 1;
					break;
				default:
					printf("Unknown flag");
					break;}
	}

	if ( (nlines=readlines(lineptr, MAXLINES)) >= 0 ){
		qsort(lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : (nocaps ? strcomp : strcmp)));
		

		if (reversed){
			reverseLines(lineptr, nlines);
			return 0;
		}

		writelines(lineptr, nlines);
		return 0;
	}
	else{
		printf("Too large input!");
		return 1;
	}
}
