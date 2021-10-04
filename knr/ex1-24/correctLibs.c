#include <stdio.h>

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
