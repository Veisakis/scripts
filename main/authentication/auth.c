#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define INPUT_SIZE 20
#define BUF_SIZE 100

int main(){
	char id[INPUT_SIZE], user[INPUT_SIZE], passwd[INPUT_SIZE];

	FILE *fd;
	char mode = 'r';

	size_t n = BUF_SIZE;
	char *line;
	line = (char*) malloc(BUF_SIZE * sizeof(char));

	printf("Username: ");
	scanf("%s", id);

	fd = fopen("/etc/shadow", &mode);

	while (getline(&line, &n, fd) > 0){
		sscanf(line, "%[^:]:%s", &user, &passwd);

		if (strcmp(id, user) == 0)
			printf("For user %s, his password is %s\n", user, passwd);
	}
}
