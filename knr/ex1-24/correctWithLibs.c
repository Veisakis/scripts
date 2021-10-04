#include <stdio.h>
#include "line.h"
#include "correctLibs.h"

char line[MAXLINE];
int lineLen;

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
