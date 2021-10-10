#include <stdio.h>

#define IN 1
#define OUT 0

void strip(int lineLen, char line[]){
	int i;
	int state = OUT;

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
