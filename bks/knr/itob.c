#include "../headers/line.h"

void itob(int n, char s[], int b){
	int i = 0;
	int sign;

	if ((sign = n) < 0)
		n = -n;
	
	do {
		if (n % b < 10) 
			s[i++] = n % b + '0';
		else
			s[i++] = n % b - 10 + 'a';
	}	
	while ((n /= b) > 0);
	
	if (sign < 0)
		s[i++] = '-';

	reverse(s);
	s[i] = '\0';
}
