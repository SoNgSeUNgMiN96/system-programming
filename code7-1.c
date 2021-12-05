/*
 * fork 를 테스트하기 위한 학습용 실습입니다.
 */
#include <stdio.h>
#include <unistd.h>

int main(void){
        int x;
        
        x = 0;
        fork();
        x = 1;
        printf("I am process %ld and my x is %d\n", (long)getpid(), x);
        return 0;
}
