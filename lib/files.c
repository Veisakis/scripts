#include <stdio.h>

#define MAXLINE 500

int fgetline(FILE *fp, char *buff){
	int c,i;

	for (i=0; i < MAXLINE && (c = fgetc(fp)) != EOF && c != '\n'; ++i)
		buff[i] = c;

	if (c == EOF)
		return 0;

	if (c == '\n')
		buff[i] = c; ++i;

	buff[i] = '\0';
	return i;
}
