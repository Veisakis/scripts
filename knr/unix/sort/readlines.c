#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

int getLine(char *);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while ((len = getLine(line)) > 0)
		if (nlines >= MAXLINES || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}	

void writelines(char *lineptr[], int nlines){
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}
