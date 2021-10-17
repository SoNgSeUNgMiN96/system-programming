/*
 *fork 8번쨰 예제입니다.  포크는 한번 하지만 부모일때 3초간 메시지를 , 자식일때 5초간 메시지를 1초에 한번씩 보냅니다.
 */

#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	char *message;
	int n;

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
			break;
		default:
			message = "This is the parent";
			n = 3;
			break;
	}
	for(;n > 0; n--) {
		puts(message);
		sleep(1);
	}
	exit(0);
}	
