#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/custom.h"

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Usage: subnet <IP>/<CIDR>\n");
		return 1;
	}

	/* Get IP and CIDR from Input */
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

	/* Get Subnet */
	int mask_bits = 32 - atoi(cidr);
	int mask = ~0 << mask_bits;

	int ip_bin = bytecat(4, ip);
	int subnet_bin = ip_bin & mask;

	printb(32, ip_bin);
	printb(32, subnet_bin);
	
	/* Results */
	int gateway = ip_bin & mask;
	int broadcast = gateway | ~(~0 << mask_bits);

	printb(32, gateway);
	printb(32, broadcast);
	
	/*
	int avail_ip1 = ip_bin;
	int avail_ip2 = ip_bin;

	printf("Number of available IP addresses: %d\n\n", mask_bits);

	printf("Default Gateway: %s\n", btos(gateway));
	printf("Broadcast: %s\n", btos(gateway));
	printf("Available IPs: %s - %s\n", btos(avail_ip1), btos(avail_ip2));
	*/	
	return 0;
}

/*
char *btos(int value){
	int ip[4];

	for (int i=3; i >= 0; i--)
		ip[i] = value;

	return ip;
}
*/
/*
TO-DO:
	btos
	calculat IPs
*/
