void maxAndIndex(int* arr, int size, int* max, int* index){
	*max = arr[0];
	*index = 0;
	
	for (int i=0; i < size; i++)
		if (arr[i] >= *max){
			*max = arr[i];
			*index = i;
		}
}
