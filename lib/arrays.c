#include <stddef.h>

void max_index(int *arr, size_t size, int *max, int *index){
	int i;

	*max = arr[0];
	*index = 0;
	
	for (i=0; i < size; i++)
		if (arr[i] >= *max){
			*max = arr[i];
			*index = i;
		}
}
