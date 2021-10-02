#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLINE 1000

void stripText(int lineLen, char line[]);
int getLine(char line[]);

char line[MAXLINE];
int lineLen;
int state = OUT;

int main(){
	while ((lineLen = getLine(line)) > 0)
		stripText(lineLen, line);
}

void stripText(int lineLen, char line[]){
	int i;
	
	for (i=0; i <= lineLen; ++i){
		if ((line[i] == '<') && (line[i+1] == 'p') && (line[i+2] == '>')){
			state = IN;
 			i += 3;
		}

		if ((line[i] == '<') && (line[i+1] == '/') && (line[i+2] == 'p') && (line[i+3] == '>')){
			state = OUT;
		}

		if (state)
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
