#include <stdio.h>

void swap(int *px, int *py);

int main(){
	int x = 5;
	int y = 2;

	swap(&x, &y);
	
	printf("x\t5\t%d\n", x);
}

void swap(int *px, int *py){
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}
