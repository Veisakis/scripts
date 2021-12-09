#include <stdio.h>

int upper(int c){
	return c >= 'a' && c <= 'z' ? c-'a'+'A' : c;
}

int lower(int c){
	return c >= 'A' && c <= 'Z' ? c+'a'-'A' : c;
}

int main(int argc, char *argv[]){
	char c;
	int r_flag = 0;

	while (--argc > 0)
		if ((*++argv)[0] == '-')
			while (c = *++argv[0]){
				switch (c){
				case 'r':
					r_flag = 1;
					break;
				default:
					printf("Unknown flag.\n");
					break;
				}
			}

	if (r_flag)
		while ((c = getchar()) != EOF)
			putchar(upper(c));
	else
		while ((c = getchar()) != EOF)
			putchar(lower(c));

}
	
	
