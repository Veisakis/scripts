#include <ctype.h>
#include <stdio.h>

int strcomp(char *s1, char *s2){
		char p1, p2;
		
		p1 = (char)tolower((int)*s1);
		p2 = (char)tolower((int)*s2);

		while(p1 == p2 != '\0'){
			if (p1 > p2)
				return 1;
			else if (p2 < p1)
				return -1;

			p1 = (char)tolower((int)*++s1);
			p2 = (char)tolower((int)*++s2);
			}
	 return 0;
}
