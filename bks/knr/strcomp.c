#include <ctype.h>
#include <stdio.h>

int strcomp(char *s1, char *s2){
		char p1, p2;
		
		p1 = (char)tolower((int)*s1++);
		p2 = (char)tolower((int)*s2++);
		
		while(p1 == p2 != '\0'){
			p1 = (char)tolower((int)*s1++);
			p2 = (char)tolower((int)*s2++);
		}

		if (p1 > p2)
			return 1;
		else if (p1 < p2)
			return -1;
		else if (p1 == p2)
			return 0;
}

/*int main(){
	char s1[] = "Elia";
	char s2[] = "Lena";

	printf("%d\n", strcomp(s1, s2));
}*/
