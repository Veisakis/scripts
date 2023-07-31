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

void printb(size_t n_bits, int value){
	for (int i=0; i < n_bits; i++){
		putchar(value & 1 ? '1' : '0');
		value = value >> 1;
	}	
	printf("\n");
}
