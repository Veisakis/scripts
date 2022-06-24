#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

extern int errno;

void handler(int signo){
	psignal(signo, "Caught a signal");
}

int main(){
	signal(SIGTSTP, handler);
	pause();
}
