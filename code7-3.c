/*
 *fork 3번째 실습입니다. fork이후 각각 다른 조건문을 실행하게되는것을 테스트해봅니다.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void fork1();

int main(void) {
	fork1();
}

void fork1()
{
    int x = 1;
    pid_t pid = fork();
    if (pid == 0) {	//이경우는 자식일경우이다
	printf("Child has x = %d\n", ++x);
    } else {	//이경우는 부모일경우 자식의 pid를 리턴받아 해당된다. 또는 오류케이스
	printf("Parent has x = %d\n", --x);
    }
    printf("Bye from process %d with x = %d\n", getpid(), x);
}
