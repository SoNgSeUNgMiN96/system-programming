#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void int_handler(int sig);

char *command_name;

int main(int argc , char *argv[])
{
        int pid;
	int sum=0, status;
	char *rindex(const char *s,int c);


    	if ((command_name = rindex(argv[0], '/')) != NULL)  command_name++;
    	else command_name = argv[0];


	pid = fork();
	
        signal(SIGINT, int_handler);
	if(pid==0){
		if(execv("./lab-12-child",&argv[0])==-1)
			perror("execv");
	}
	else
		printf("parent: child initiated\n");
	

	sleep(1);
	kill(pid,SIGINT);
	waitpid(pid,&status,0);	
	printf("parent: child terminated\n");

}

void int_handler(int sig)
{
        printf("prossess %d received signal  %d\n",getpid(), sig);
   	exit(0);
}
