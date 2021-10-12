#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

int getop(char s[]){
	int i, c, d;

	while ((s[0] = c = getch()) == ' ' || c == '\t');

	i = 0;
	if (c == '+' || c == '-'){
		d = getch();
		if (isdigit(d)){
			s[1] = c = d;
			i++;
		}
		else{
			s[1] == '\0';
			ungetch(d);	
		}
	}

	if (!isdigit(c) && c != '.')
		return c;

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()));

	if (c == '.')
		while (isdigit(s[++i] = c = getch()));

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("Error ungetch: Too many characters!");
	else
		buf[bufp++] = c;	
}

