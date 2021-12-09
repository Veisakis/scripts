#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE 100

int main(int argc, char *argv[]){
	int fd, n;
	char buf[BUFSIZE];

	if (argc == 1)
		while ((n = read(0, buf, BUFSIZE)) > 0)
			write(1, buf, n); 
	else
		while (--argc > 0)
			if ((fd = open(*++argv, O_RDONLY, 0)) == -1){
				printf("cat: Cannot open %s\n", *argv);
				return 1;
			}
			else {
				while ((n = read(fd, buf, BUFSIZE)) > 0)
					if (write(1, buf, n) != n) 
						printf("cat: Error at writing %s\n", *argv);
				close(fd);
			}
	return 0;
}
