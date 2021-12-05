#include  <sys/times.h>  /* times1.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void  pr_times(clock_t, struct tms *, struct tms *);
static void  do_cmd(char *);

int main(int argc, char *argv[]) {
  int    i;

  for (i = 1; i < argc; i++)
    do_cmd(argv[i]);  //읽어온 명령들을 순차 실행 
  
  exit(0);
}

static void do_cmd(char *cmd) {	//읽어온 명령을 가져와서 , 명령을 하는데 걸린 시간을 측정한다.
  struct tms  tmsstart, tmsend;
  clock_t    start, end;
  int      status;
  
  fprintf(stderr, "\ncommand: %s\n", cmd);

  if ( (start = times(&tmsstart)) == -1)  //시작시간 기록
    perror("times error");
  
  if ( (status = system(cmd)) < 0)    //명령 실행
    perror("system() error");
  
  if ( (end = times(&tmsend)) == -1)    //명령실행 후 시간 기록
    perror("times error");
  
  pr_times(end-start, &tmsstart, &tmsend);		//real에 명령실행에 걸린 시간을 넘겨주고, tmsstart와 tmsend를 넘겨준다

}


static void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend) {

  static long    clktck = 0;

  if (clktck == 0)  /* fetch clock ticks per second first time */
    if ( (clktck = sysconf(_SC_CLK_TCK)) < 0)		//초당 클럭 틱 수를 clktck에 저장 ,에러시 -1  , 그 경우 하단 에러메세지 출력
      perror("sysconf error");

  fprintf(stderr, "  real:  %7.2f\n", real / (double) clktck);		//걸린 시간을 출력
  
  fprintf(stderr, "  user:  %7.2f\n",
      (tmsend->tms_utime - tmsstart->tms_utime) / (double) clktck);	//걸린 유저  시간을 출력
  
  fprintf(stderr, "  sys:   %7.2f\n",
      (tmsend->tms_stime - tmsstart->tms_stime) / (double) clktck);	//걸린 시스템 시간을 출력
  
  fprintf(stderr, "  child user:  %7.2f\n",
      (tmsend->tms_cutime - tmsstart->tms_cutime) / (double) clktck);	//걸린 자식 유저 시간을 출력
  
  fprintf(stderr, "  child sys:   %7.2f\n",
      (tmsend->tms_cstime - tmsstart->tms_cstime) / (double) clktck);	//걸린 자식 시스템 시간을 출력

}

