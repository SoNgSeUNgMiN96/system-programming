/*
 *fork 9번쨰 예제입니다.  포크이후 자식일경우만 변수를 하나 더해주어서 실제 부모의 출력은 기존 변수 그래도 출력이됩니다.
 */

#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int    glob = 6;    

int main(void) {
  int    var;   
  pid_t  pid;

  var = 88;
  printf("before fork\n"); 

  if ( (pid = fork()) < 0)
    perror("fork error");
  else if (pid == 0) {    //자식만 변수를 더해준다.
    glob++;
    var++;
    _exit(0);       
  }

  //부모만 실행하는 구문
  printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
  exit(0);
}
