/*
 * fork 7번째 예제입니다. 3번의 포크를 조건문을  사용하여 가지치기로 4가지 케이스로 나가는것을 확인하는 예제입니다.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void fork5()
{
    printf("L0\n");
    if (fork()==0){		//자식노드라면
	printf("L1\n");		//L1 출력
	if(fork()==0){		//자식노드라면
		printf("L2\n");	//L2를 출력 하고 포크를 한다. 
		fork();
	}
    }    
    printf("Bye\n");	//최종적으론 바이가 4번 출력된다.
}

int main(){
	fork5();
}
