#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define NUMBER 1

char buf[BUFSIZE];

int getop(char s[]){
	int i, c;
	static int bufp = 0;

	while ((s[0] = c = getch(bufp)) == ' ' || c == '\t');

	s[1] = '\0';
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch(bufp)));

	if (c == '.')
		while (isdigit(s[++i] = c = getch(bufp)));

	s[i] = '\0';

	if (c != EOF){
		if (bufp >= BUFSIZE)
			printf("Error ungetch: Too many characters!");
		else
			buf[bufp++] = c;	
	}

	return NUMBER;
}

int getch(int pos){
	return (pos > 0) ? buf[--pos] : getchar();
}

void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("Error ungetch: Too many characters!");
	else
		buf[bufp++] = c;	
}

