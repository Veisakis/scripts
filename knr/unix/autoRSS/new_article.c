#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1

int main(){
	int fd_article, fd_foot;
	char buf[BUFSIZE];	

	fd_article = open("article", O_WRONLY|O_APPEND, 0);
	fd_foot = open("footer", O_RDONLY, 0);

	if (fd_article < 0){
		printf("Article file not found.\n");
		printf("Exiting...\n");
	  exit(1);
	}
	else{
		while (read(0, buf, BUFSIZE) > 0)
			write(fd_article, buf, BUFSIZE);
	}

	if (fd_foot < 0){
		printf("Footer file not found.\n");
		printf("Exiting...\n");
	  exit(1);
	}
	else{
		while (read(fd_foot, buf, BUFSIZE) > 0)
			write(fd_article, buf, BUFSIZE);
	}

	close(fd_article);
	close(fd_foot);
}
