#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1

int main(){
	int fd, fd_foot;
	char buf[BUFSIZE];	

	fd = open("rss_blank", O_WRONLY|O_APPEND, 0);
	fd_foot = open("rss_foot", O_RDONLY, 0);

	if (fd < 0){
		printf("RSS file not found.\n");
		printf("Exiting...\n");
	  exit(1);
	}
	else{
		while (read(0, buf, BUFSIZE) > 0)
			write(fd, buf, BUFSIZE);
	}

	while (read(fd_foot, buf, BUFSIZE) > 0)
		write(fd, buf, BUFSIZE);

	close(fd);
	close(fd_foot);
}	
