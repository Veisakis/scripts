#include <stddef.h>

void max_index(int *arr, size_t size, int *max, size_t *index){
	*max = arr[0];
	*index = 0;
	
	for (size_t i=0; i < size; i++)
		if (arr[i] >= *max){
			*max = arr[i];
			*index = i;
		}
}
