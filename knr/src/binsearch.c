int binsearch(int v[], int x, int n){
	int low, mid, high;

	low = 0;
	high = n - 1;
	
	while (low <= high){
		mid = (low+high) / 2;

		if (x < v[mid])
			high = v[mid] - 1;
		else
			low = v[mid] + 1;
		
		if (x == v[mid])
			return x
	}

	return -1
}
