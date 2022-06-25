#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "custom.h"

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
int counter[5];

int main(){
	size_t i, y,index;
	int max;
	char phrase[LINE_MAX];

	fgets(phrase, LINE_MAX, stdin);

	for (i = 0; i < 5; i++)		
		for (y = 0; y < sizeof(phrase); y++)
			if (vowels[i] == phrase[y])
				counter[i]++;
	
	max_index(counter, sizeof(vowels), &max, &index);
	printf("Letter %c was used %d times!\n", vowels[index], max);

	return 0;
}
