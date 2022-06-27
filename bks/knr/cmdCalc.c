#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int i;
	int result = 1;

	for (i = 1; i < argc; i++){
		int x = strtol(argv[i], NULL, 10);
	
		if (!x)
			continue;

		result *= x;
	}
	
	printf("%d\n", result);
}
