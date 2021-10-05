int htoi(char line[]){
	int i;
	int n = 0;

	for (i = 0; line[i] != '\0'; ++i){

		if (line[i] >= 'A' && line[i] <= 'F')
			n = 16 * n + (line[i] - 'A' + 10);

		if (line[i] >= 'a' && line[i] <= 'f')
			n = 16 * n + (line[i] - 'a' + 10);

		if (line[i] >= '0' && line[i] <= '9')
			n = 16 * n + (line[i] - '0');

	}
	return n;		
}
