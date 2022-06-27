#include <ctype.h>
#include <stdlib.h>

int isnumber(char *s){
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if (!isdigit((int)s[i]))
			return 0;

	return atoi(s);
}
