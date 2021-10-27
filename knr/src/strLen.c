#include <stdio.h>

int strLen(char *s);

int main(){
	char s[] = "Hello World!";

	printf("String length:\t%d\n", strLen(s));
}

int strLen(char *s){
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;

	return n;
}
