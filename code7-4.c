/*
 * fork 4번째 예제입니다. 2번 포크를 사용하여 가지치기로 4가지 케이스로 나가는것을 확인하는 예제입니다.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void fork2()
{
    printf("L0\n");
    fork();
    printf("L1\n");    
    fork();
    printf("Bye\n");
}

int main(){
	fork2();
}
