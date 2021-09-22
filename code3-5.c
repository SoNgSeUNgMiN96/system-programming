#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (){
	if((write(1,"Welcome to System Programming",27))!=27)
		write(2,"A write error has occurred on file descriptor 1\n",47);
	exit(0);
}
