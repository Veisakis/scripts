#include "../headers/line.h"

int itoagap(int n, char s[], int w){
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;

	do
		s[i++] = n % 10 + '0';
	while ((n /= 10) > 0);

	while (i < w)
		s[i++] = ' ';

	if (sign < 0)
		s[i++] = '-';

	reverse(s);
	s[i] = '\0';
}
