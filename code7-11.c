/*
 * waitpid 2번째 예제입니다. 자식의 정상종료와 , 정상종료가아니고 시그널을 보낸경우을 출력해봅니다. 
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    int pid;
    int status;
    pid = fork();
    if (pid < 0){
        perror("fork error : ");
        exit(0);
    }
    if (pid == 0){	//자식프로세스는 2초 기다렸다가 , 2를 리턴한다.
        printf("I am Child\n");
        sleep(2);
        return 2;
    }	
    else{	//부모 프로세스는 자식을 기다렸다가 상태를 판단한다.
        printf("Parent: wait (%d)\n", pid);
        waitpid(pid, &status, 0);	//자식의 종료를 기다림. status에 포인터를 리턴받음
        if (WIFEXITED(status)){		//정상종료일경우 WIFEXITED는 true를 리턴한다. 
            printf("정상종료\n");
            printf("리턴값 %d\n", WEXITSTATUS(status));	//WEXITSTATUS()는 자식의 리턴값을 리턴한다.
        }
        else if (WIFSIGNALED(status)){	//정상종료가 아니고 시그널을 받았을경우 //WIFSIGNALED는트루반환
            printf("신호받았음\n");
            printf("신호번호 %d\n", WTERMSIG(status)); //WTERMSIG 이 자식이 보낸 시그널을 리턴함.
        }
    }
    exit(0);
}
