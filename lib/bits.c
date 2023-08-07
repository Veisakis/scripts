#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

void printb(size_t n_bits, int value){
	char *bits;
	bits = malloc(n_bits * sizeof(char));

	int i = 0;

	while (i < n_bits){
		bits[i++] = value & 1 ? '1' : '0';
		value = value >> 1;
	}

	while (i >= 0){
		if (i % 8 == 0 && i != 0 && i != n_bits)
			printf(".");

		printf("%c", bits[--i]);
	}
	printf("\n");
}

int bytecat(size_t n_bytes, int bytes[]){
	int n = 0;

	for (int i=0; i < 4; i++){
		/*printb(8, bytes[i]);*/
		n = (n << 8) | bytes[i];
	}
	return n;
}
