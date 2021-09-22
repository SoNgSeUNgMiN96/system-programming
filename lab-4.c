#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2)
        printf("usage: a.out <pathname>");
	
    int fd;

    if (access(argv[1], F_OK) < 0){
	if((fd = open(argv[1],O_RDWR|O_CREAT,0644))==-1){
		printf("Cannot create %s\n",argv[1]);
		exit(1);
	}
	if(write(fd,"hello world",11)!=11)
		printf("error");
	    
        
    }else{
	char buffer[20];
	if ((fd=open(argv[1],O_RDONLY))==-1)
		exit(1);
	read(fd,buffer,20);
	printf("%s\n",buffer);
    }
   
    return 0;
}
