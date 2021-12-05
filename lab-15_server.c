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
	//fifo 파일을만들고

	while (1) { 
		//fifo 를 읽어서
		if((fd = open("/tmp/my_fifo2", O_RDONLY)) == -1) 
			perror("open"); 

		memset(buffer, '\0', BUFSIZ);
	       	read(fd, buffer, BUFSIZ);
		if (buffer[0]=='0')
			return 0;
	       	write(STDOUT_FILENO, buffer, strlen(buffer));
		//파이프에서 읽어온 값을 출력
	       	close(fd); 
	} 
	return 0; 
}

