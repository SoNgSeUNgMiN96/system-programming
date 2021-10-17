/*
 * fork 5번째 예제입니다. 3번 포크를 사용하여 가지치기로 8가지 케이스로 나가는것을 확인하는 예제입니다.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void fork3()
{
    printf("L0\n");
    fork();
    printf("L1\n");    
    fork();
    printf("L2\n");
    fork();
    printf("Bye\n");
}

int main(){
	fork3();
}
