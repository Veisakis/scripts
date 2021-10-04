#include <stdio.h>

#define MAXLINE 20

char line[MAXLINE];
int lineLen;

int getLine(char line[]);
int commentsCheck(int lineLen, char line[]);
int parenthesisCheck(int lineLen, char line[]);
int bracketsCheck(int lineLen, char line[]);
int abracketsCheck(int lineLen, char line[]);

int main(){
	int comState, comAdder, parState, parAdder, 
			braState, braAdder, abraState, abraAdder;

	comState = parState = braState = abraState = 0;

	while ((lineLen = getLine(line)) > 0){
		comAdder = commentsCheck(lineLen, line);
		comState += comAdder;

		parAdder = parenthesisCheck(lineLen, line);
		parState += parAdder;

		braAdder = bracketsCheck(lineLen, line);
		braState += braAdder;

		abraAdder = abracketsCheck(lineLen, line);
		abraState += abraAdder;
	}

	if (comState != 0)
		printf("Syntactical error regarding comments!\n");
	
	if (parState != 0)
		printf("Syntactical error regarding parenthesis!\n");

	if (braState != 0)
		printf("Syntactical error regarding brackets!\n");

	if (abraState != 0)
		printf("Syntactical error regarding angular brackets!\n");

}

int commentsCheck(int lineLen, char line[]){
	int i;
	int state = 0;

	for (i = 0; i < lineLen; ++i){
		if ((line[i] == '/') && (line[i+1] == '*'))
			state += 1;

		if ((line[i] == '*') && (line[i+1] == '/'))
			state += -1;
	}
	return state;
}

int parenthesisCheck(int lineLen, char line[]){
	int i;
	int state = 0;

	for (i = 0; i < lineLen; ++i){
		if (line[i] == '(')
			state += 1;

		if (line[i] == ')')
			state += -1;
	}
	return state;
}

int bracketsCheck(int lineLen, char line[]){
	int i;
	int state = 0;

	for (i = 0; i < lineLen; ++i){
		if (line[i] == '[')
			state += 1;

		if (line[i] == ']')
			state += -1;
	}
	return state;
}

int abracketsCheck(int lineLen, char line[]){
	int i;
	int state = 0;

	for (i = 0; i < lineLen; ++i){
		if (line[i] == '{')
			state += 1;

		if (line[i] == '}')
			state += -1;
	}
	return state;
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
