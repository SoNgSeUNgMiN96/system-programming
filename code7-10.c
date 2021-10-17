/*
 * waitpid 1번째 예제입니다. 자식의 정상종료와 , 정상종료가아니고 시그널을 보낸경우을 출력해봅니다. 
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
        pid_t pid;
        char *message;
        int n;
        int exit_code;

        printf("fork program starting\n");
        pid = fork();
        switch(pid)
        {
	  case -1:
                perror("fork failed");
                exit(1);
	  case 0:
                message = "This is the child";
                n = 5;
                exit_code = 37;
                break;
        default:
                message = "This is the parent";
                n = 3;
                exit_code = 0;
                break;
        }
	for(; n > 0; n--) {	//부모일경우 3번 자식일경우 5번 message 출력.
                puts(message);
                sleep(1);
        }

	if (pid != 0) {		//부모프로세스라면, (에러인경우 이미 exit)
        	int stat_val;
        	pid_t child_pid;
        	child_pid = wait(&stat_val);

        	printf("Child has finished: PID = %d\n", child_pid);
	

        	if(WIFEXITED(stat_val))	//자식이 정상종료했다면 , 
                	printf("Child exited with code %d\n",WEXITSTATUS(stat_val));	//자식의리턴값출력
        	else
                	printf("Child terminated abnormally\n");
        }
	exit(exit_code);
}
