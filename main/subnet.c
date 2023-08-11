#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/custom.h"


void btos(int bits, char *ip);

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Usage: subnet <IP>/<CIDR>\n");
		return 1;
	}

	/* Get IP and CIDR from Input */
	int addr_split[4];
	char *addr_str;
	char *cidr_str;

	addr_str = strtok(argv[1], "/");
	cidr_str = strtok(NULL, "/");

	for (int i=0; i < 4 ; i++)
		if (i == 0)
			addr_split[0] = atoi(strtok(addr_str, "."));	
		else
			addr_split[i] = atoi(strtok(NULL, "."));

	/* Get Subnet */
	int mask_c = 32 - atoi(cidr_str);
	int mask = ~0 << mask_c;

	int address = bytecat(4, addr_split);
	int subnet = address & mask;

	/* Calculate Addresses */
	int gateway = address & mask;
	int broadcast = gateway | ~(~0 << mask_c);

	int n_addr = ~mask - 1;
	int start_addr = gateway + 1;
	int end_addr = gateway + n_addr;

	/* Print Results */
	char gateway_ip[16];
	char broadcast_ip[16];
	char start_ip[16];
	char end_ip[16];

	btos(gateway, gateway_ip);
	btos(broadcast, broadcast_ip);
	btos(start_addr, start_ip);
	btos(end_addr, end_ip);

	printf("Number of available IP addresses: %d\n\n", n_addr);
	printf("Default Gateway: %s\n", gateway_ip);
	printf("Broadcast: %s\n", broadcast_ip);
	printf("IP Range: %s - %s\n", start_ip, end_ip);

	return 0;
}

void btos(int bits, char *ip){
	int bytes[4];
	int mask = ~(~0 << 8);

	for (int i=3; i >= 0; i--){
		bytes[i] = bits & mask;
		bits = bits >> 8;
	}
	sprintf(ip, "%d.%d.%d.%d", bytes[0], bytes[1], bytes[2], bytes[3]);
}
