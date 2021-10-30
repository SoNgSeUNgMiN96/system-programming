#include  <sys/types.h>  /* system.c */
#include  <sys/wait.h>
#include  <errno.h>
#include  <unistd.h>
#include <stdio.h>

int system(const char *cmdstring) 
{
  pid_t pid;  int status;

  if (cmdstring == NULL)
    return(1);    //명령이없으면 종료

  if ( (pid = fork()) < 0) {	//포크를 하고 실패하면 status값을 1로
    status = -1;  

  } else if (pid == 0) {        //자식이라면 
    execl("/bin/sh", "sh", "-c", cmdstring, (char *) 0);	//받아온 명령 실행 
    _exit(127);   
  } else {              //부모는 자식을 기다리고, 자식이 들어온다면 break ,  오류시 status =-1
    while (waitpid(pid, &status, 0) < 0)
      if (errno != EINTR) {
        status = -1; /* error other than EINTR from waitpid() */
        break;
      }
  }
  return(status);
}

int main(){	//ls 명령어로 테스트하기
	if(system("ls")==-1)		//만약 오류값이 리턴된다면 오류  출력
		perror("system error");
}
