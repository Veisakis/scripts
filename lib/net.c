#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
	if (argc != 2){
		return 1;
	}

	char *ip;
	char *cidr;

	ip = strtok(argv[1], "/");
	cidr = strtok(NULL, "/");

	ip = atoi(ip);
	cidr = atoi(cidr);

	printf("%d\t%d\n", ip, cidr);
	return 0;
}
