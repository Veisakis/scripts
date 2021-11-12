#include <stdio.h>

#define MAXLINE 100

int getLine(char *line){
	int c,i;

	for (i=0; (i < MAXLINE) && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	
	if (c == EOF)
		return 0;

/*if (c == '\n'){
		line[i] = c;
		++i;
	}*/

	line[i] = '\0';
	return i;
}
