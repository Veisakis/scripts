#include <stdio.h>
#include "line.h"

char line[MAXLINE];
int lineLen;

int main(){
	while ((lineLen = getLine(line)) > 0)
		strip(lineLen, line);
}
