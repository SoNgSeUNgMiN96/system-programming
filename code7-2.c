/*
 * fork에대한 실습 2번째입니다. fork 의 리턴값은 -1이 실패 , 0의경우 child가 받는 리턴값 , 이외의 경우는 부모가 자식의 pid를 받아옵니다. 
 * fork 된 자식 프로세스는 fork 라인부터 실행됩니다.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
        pid_t childpid;

        childpid = fork();
        if (childpid == -1){
                printf("Failed to fork");
                return 1;
        }
 	   if (childpid == 0)
                printf("hello from child %ld\n", (long)getpid());
        else
                printf("hello from parent %ld\nchildpid = %d\n", (long)getpid(),childpid);
        return 0;
}
