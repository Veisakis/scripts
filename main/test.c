#include <stdio.h>
#include <stdlib.h>

#include <custom.h>

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	int b[] = {0, 0, 0, 0, 0, 0, 0, 0};
	
	itob(n, b);

	for (int i=0; i < 8; i++)
		printf("%d", b[i]);
	printf("\n");
}
