#include <ctype.h>
#include <math.h>

double atof(char s[]){
	double val, power;
	int i, sign;

	double esign, exp;

	for (i = 0; isspace(s[i]); i++);

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++){
			val = 10.0 * val + (s[i] - '0');
			power *= 10.0;
	}
	
	val = sign * val / power;

	if (s[i++] == 'e'){
		esign = (s[i++] == '-') ? 0.1 : 10.0;
		
		for (exp = 0; isdigit(s[i]); i++)	
			exp = 10.0 * exp + (s[i] - '0');
		
		return val * pow(esign, exp);
	}
		
	return val;
}
