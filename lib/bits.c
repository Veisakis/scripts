#include <stddef.h>
#include <math.h>

void *dec_to_byte(int value, int *byte){
	int i;

	if (value % 2 == 1)
		byte[7] = 1;

  for (i=7; i > 0; i--)
    if (value / (int)pow(2,i) > 0){
      byte[7-i] = 1;
      value -= (int)pow(2,i);
    }
}
