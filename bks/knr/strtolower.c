#include <string.h>
#include <ctype.h>

void strtolower(char *s, char *t){
		int i;
		for (i = 0; i < strlen(s); i++)
			t[i] = tolower(s[i]);
}
