#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/custom.h"


int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Usage: subnet <IP>/<CIDR>\n");
		return 1;
	}

	char *addr;
	char *cidr;

	addr = strtok(argv[1], "/");
	cidr = strtok(NULL, "/");

/*
	int ip[4];
	ip[0] = atoi(strtok(addr, "."));	
	for (int i=1; i < 4 ; i++)
		ip[i] = itob(atoi(strtok(NULL, ".")));
*/

	return 0;
}
