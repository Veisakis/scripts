#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "arrays.h"

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
int counter[5];

int main(){
	int i, y;
	int max, index;
	char phrase[LINE_MAX];

	fgets(phrase, LINE_MAX, stdin);

	for (i = 0; i < 5; i++)		
		for (y = 0; y < sizeof(phrase); y++)
			if (vowels[i] == phrase[y])
				counter[i]++;

	maxAndIndex(counter, 5, &max, &index);
	printf("Letter %c was used %d times!\n", vowels[index], max);

	return 0;
}
