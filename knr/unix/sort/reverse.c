#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]){
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; ++i, --j)
		c = s[i], s[i] = s[j], s[j] = c;
}

void reverser(char s[], int size){
	static int start = 0;
	int end = size;
	int buf;
	
	if (start < end){
		buf = s[start], s[start] = s[end], s[end] = buf;
		start++, end--;
		reverser(s, end);
	}

	if (start >= end)
		s[strlen(s)] = '\0';
}

#define MAXLEN 100

void reverseLines(char *lineptr[], int size){
	while (--size >= 0)
		printf("%s\n", lineptr[size]);
}
