#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/custom.h"

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Usage: subnet <IP>/<CIDR>\n");
		return 1;
	}

	int ip[4];
	char *addr;
	char *cidr;

	addr = strtok(argv[1], "/");
	cidr = strtok(NULL, "/");

	for (int i=0; i < 4 ; i++)
		if (i == 0)
			ip[0] = atoi(strtok(addr, "."));	
		else
			ip[i] = atoi(strtok(NULL, "."));

	printb(32, bytecat(4, ip));
	return 0;
}
