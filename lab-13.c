#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 

int main() { 

	int fd[2]; 
	int pid;

	if(pipe(fd) != 0) 
		perror("pipe"); 
	
	pid = fork();

	if(pid == -1) 
		perror("fork"); 
	else if(pid == 0) {	
	
		if(fd[0] != 0)  
			dup2(fd[0], 0); 	//표준입력을 pipe 입구로 redirect 합니다.
		execlp("grep", "grep", "telnet", (char*)0);
	
	} else {  
		if(fd[1] != 1) 
			dup2(fd[1], 1);		//표준 출력을 pipe 출구로 redirect 합니다. 
		execlp("ps" , "ps", "-ef" , (char*)0);
			
	}

	close(fd[1]); 
	close(fd[2]); 
}
