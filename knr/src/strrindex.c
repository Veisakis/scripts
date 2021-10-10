#include <stdio.h>
#include "../headers/line.h"

int strrindex(char s[], char t[]);

char s[MAXLINE];
char t[] = "an";
int pos;

int main(){
	while (getLine(s) > 0)
		if (strrindex(s, t) >= 0)
			printf("%s", s);
			printf("%i\n", pos);
}

int strrindex(char s[], char t[]){
	int i, j, k;
	pos = -1;

	for (i = 0; s[i] != '\0'; ++i){
		for (j=i, k=0; t[k] != '\0' && t[k] == s[j]; ++j, ++k);
		
		if (k > 0 && t[k] == '\0')
			pos = i;
	}

	if (pos >= 0)
		return pos;
	else
		return -1;
}
