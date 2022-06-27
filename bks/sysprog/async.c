#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <errno.h>

char* cdate(){
	time_t rawtime;
	char* fulltime;

	rawtime = time(NULL);
	return ctime(&rawtime);
}

int main(int argc, char* argv[]){
	int fd;
	char* datetime;
		
	datetime = (char*) malloc(sizeof(char)*27);
	datetime = cdate();

	fd = open("time_log", O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR);	
	write(fd, datetime, strlen(datetime));
	close(fd);
}

