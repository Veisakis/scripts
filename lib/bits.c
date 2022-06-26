#include <stddef.h>
#include <math.h>

/*User must pass an all zero
array of 8 size_t elements */
size_t *dec_to_byte(size_t value, size_t *byte){
	if (value % 2 == 1)
		byte[7] = 1;

  for (size_t i=7; i > 0; i--)
    if (value / (size_t)pow(2,i) > 0){
      byte[7-i] = 1;
      value -= (size_t)pow(2,i);
    }
	return byte;
}
