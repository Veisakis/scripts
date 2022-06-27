#include <stdlib.h>
#include "../headers/line.h"

int itoa(int n, char s[]){
	int i, sign;

	if (n < 0)
		sign = '-';

	i = 0;

	do
		s[i++] = abs(n % 10) + '0';
	while ( abs(n /= 10) > 0);

	if (sign == '-')
		s[i++] = '-';
	else
		s[i++] = '+';

	reverse(s);
	s[i] = '\0';
}
