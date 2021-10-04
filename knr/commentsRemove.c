#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLINE 1000

void removeComments(int lineLen, char line[]);
int getLine(char line[]);

char line[MAXLINE];
int lineLen;

int main(){
	while ((lineLen = getLine(line)) > 0)
		removeComments(lineLen, line);
}

void removeComments(int lineLen, char line[]){
	int state = OUT; /* Keeping track of being in or out of a comment */
	int i;
	
	for (i=0; i < lineLen; ++i){
		if ((line[i] == '/') && (line[i+1] == '*'))
			state = IN;

		if ((line[i] == '*') && (line[i+1] == '/')){
			state = OUT;
			i += 3;
		}

		if (state == OUT)
			putchar(line[i]);
	}
}

int getLine(char line[]){
	int c,i;

	for (i=0; (i < MAXLINE) && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	
	if (c == '\n'){
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}
