#include <string.h>

void shiftarray(char *s[], int len, char t[]){
	int i = 1;
	while (i < len){
		strcpy(s[i-1], s[i]); 
		i++;
	}
	strcpy(s[--i], t);
}
