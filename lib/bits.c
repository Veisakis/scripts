#include <stdio.h>
#include <stddef.h>
#include <math.h>

void itob(int value, int byte[]){
	if (value % 2 == 1)
		byte[7] = 1;

  for (int i=7; i > 0; i--)
    if (value / (int)pow(2,i) > 0){
      byte[7-i] = 1;
      value -= (int)pow(2,i);
    }
}

int bytecat(size_t n_bytes, int bytes[]){
	int result = 0;
	
	for (int i = 0; i < n_bytes; i++)
		result = (result << 8) + bytes[i];

	return result;
}

void printb(size_t n_bits, int bits[]){
	for (int i=0; i < n_bits; i++)
		printf("%d", bits[i]);
	printf("\n");
}
