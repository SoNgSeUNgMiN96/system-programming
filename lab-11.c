#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void int_handler(int sig);

int main()
{
        int pid;
	int sum=0, status;

	pid = fork();
	
        signal(SIGINT, int_handler);
	if(pid==0){

		while(1){
			printf("i'm child\n");
			sleep(1);			
		}
	}
	
	sleep(1);	
	kill(pid,SIGINT);
	waitpid(pid,&status,0);

	
	if(WIFEXITED(status)){
		printf("정상종료, 리턴값 = %d\n",WEXITSTATUS(status));
	}

}

void int_handler(int sig)
{
        printf("prossess %d received signal  %d\n",getpid(), sig);
   	exit(0);
}
