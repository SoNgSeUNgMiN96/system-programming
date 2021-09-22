#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 512

void main() 
{
	char buffer[BUFSIZE];
	int fd;
	ssize_t nread;
	long total = 0;

	if ((fd = open("test.txt" , O_RDONLY)) == -1)
		exit(1);

	if(lseek(fd,10,SEEK_SET)==-1)
		perror("lseek");

	while ((nread = read(fd, buffer, BUFSIZE)) > 0)
		printf("%s",buffer);
	

	if(lseek(fd,-6,SEEK_END)==-1)
		perror("lseek2");

	printf("\n");

	while ((nread = read(fd,buffer,BUFSIZE))>0)
		printf("%s",buffer);


	close(fd);
	exit(0);
}
