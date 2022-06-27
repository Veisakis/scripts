#include <stdio.h>
#include <stdlib.h>
#include "tail.h"

#define MAXLINE 100

int main(int argc, char *argv[]){
	int i = 0;
	int n = 0;
	int tailen = -1;
	char c, previousFlag, numInput[MAXLINE];

	int flagValue;
	while (--argc > 0){
		flagValue = isnumber(*++argv);
 		if (flagValue)
			tailen = flagValue;
		
		if ((*argv)[0] == '-')
			while (c = *++argv[0]){
				switch (c) {
				case 'n':
					n = 1;
					while (*++argv[0])
						numInput[i++] = *argv[0];
					break;
				}
			}
		}

	if (n == 1){
		if (tailen == -1)
			tailen = atoi(numInput);

		char newline[MAXLINE];
		char **buff;

		buff = (char**)malloc(tailen*sizeof(char*));

		for (i = 0; i < tailen; i++)
			buff[i] = (char*)malloc(MAXLINE*sizeof(char));
		
		while (getLine(newline) > 0){
			shiftarray(buff, tailen, newline);
		}	

		for (i = 0; i < tailen; i++)
			if (buff[i][0] != '\0')
				printf("%s\n", buff[i]);
	}
}
