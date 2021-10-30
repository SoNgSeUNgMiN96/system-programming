/*
 * 부모 프로세스는 두 자식 프로세스를 생성하고, 각각의 자식은 echo커맨드를 실행하며 본인을 출력한다.
 * 부모는 자식을 기다리기 전과 후의 상태를 출력한다.
 * 추가로, 부모는 자식들의 상태를 출력한다.
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (){

	int *pids;
	int status;
	int i=-1;


	pids = (int*)malloc(sizeof(int)*2);		//pid들을 저장할 pids배열 선언


	printf("Parent: Wating for children\n");	//자식을 기다리기 전 부모프로세스가 출력
	
	while (pids[++i] =fork()){	//2개의 자식을 기다림
		
		waitpid(pids[i],&status,0);
		if(i==0&&pids[0]!=0){	//첫째 자식을 기다린 부모는 첫째의 상태를 출력
			printf("Parent: First Child: %d\n",status);
		}
		if(i==1){
			if(pids[1]!=0)	//둘째 자식을 기다린 부모는 둘째의 상태를 출력
				printf("Parent: Second Child: %d\n",status);
			break;
		}
	}

	if(pids[i]==0){	//자식프로세스는 각각 i 에 따라 child 1 과 2로 나누어 echo  출력
		if(i==0)
			execl("/bin/echo","echo","This is Child 1",(char*)0);
		else
			execl("/bin/echo","echo","This is Child 2",(char*)0);

	}else	//부모 프로세스는 자식을 모두 기다린 후 기다리는게 끝났다고 출력
		printf("Parent: All Children terminated\n");
	
	return 0;

}
