#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	struct stat md;
	
	if (argc != 2){
		fprintf(stderr, "Improper use of program!\n");
		return 1;
	}
	
	if (stat(argv[1], &md)){
		perror("Error");
		return 2;
	}
	
	printf("Filename: %s\tSize: %d bytes\n", argv[1], md.st_size);
	return 0;
}
