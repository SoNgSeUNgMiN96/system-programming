#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/stat.h>
#include <sys/types.h> 
#include <fcntl.h>


int main() {

	int fd; 
	char buffer[BUFSIZ];
	
	mkfifo("/tmp/my_fifo2",0666);
	//fifo file을 만들고

	while (1) { 
			//fifo를 읽어서
		if((fd = open("/tmp/my_fifo2", O_WRONLY)) == -1) 
			perror("open"); 
		//입력값을 파이프에 넣어준다.
	       	scanf("%s",buffer);
	       	write(fd, buffer, strlen(buffer));	
	       	close(fd); 
		if (buffer[0]=='0')
			return 0;
	} 
	return 0; 
}

