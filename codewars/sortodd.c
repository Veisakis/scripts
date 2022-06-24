#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2){
	if (*(int*)p1 > *(int*)p2)
		return 1;
	else if (*(int*)p1 < *(int*)p2)
		return -1;
	else
		return 0;
}

int *sortOdd(size_t n, int arr[n]){
	int *odd;
	
	int i, y;
	int odd_counter = 0;
	
	for (i=0; i < n; i++)
		if ((arr[i] % 2) != 0)
			odd_counter++;

	odd = (int*)malloc(sizeof(int)*odd_counter);
	
	/*Add odd numbers to new array*/
	for (i=y=0; i < n; i++)
		if ((arr[i] % 2) != 0)
			odd[y++] = arr[i];

	qsort(odd, odd_counter, sizeof(int), comparator);

	printf("Original Array: {");
	for (i=0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\b}\n");
	
	printf("Odd Array: {");
	for (i=0; i < odd_counter; i++){
		printf("%d ", odd[i]);
	}
	printf("\b}\n");
	
	for (i=y=0; i < n; i++)
		if ((arr[i] % 2) != 0)
			arr[i] = odd[y++];

	printf("Final Array: {");
	for (i=0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\b}\n");

	return arr;
}

int main(){
	int array[] = {5, 3, 2, 8, 1, 4};
	sortOdd(6, array);
}
