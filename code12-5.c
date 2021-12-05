/*
	int pthread_create(pthread_t *thread, const pthread_attr_t *attr ,void *(*start_routine)(void *), void *arg) 함수
 	쓰레드를 생성하고 , 첫번째 매개변수는 쓰레드를 식별하기위한 식별자이며, 두번째 인자는 쓰레드의 특성을 지정하기위한 pthread_attr_t이며, 
	세번째 인자는 분기시켜서 실행시킬 함수이고, 네번째 인자는 그 함수의 매개변수로 넘겨진다.
	성공시의 리턴값은 0이다.
 
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int cnt = 0; /* global */ 	//글global변수로 쓰레드가 변수를 공유할 수 있게 해준다.

void *thread(void *vargp);

int main(int argc, char **argv)
{
  int niters = atoi(argv[1]);	//첫번째 인자를 넘겨받아 int형으로 변환해준다.
  pthread_t tid1, tid2;	//두개의 쓰레드를 식별할 두개의 pthread_t	변수 선언.

  pthread_create(&tid1, NULL,thread, &niters);	//쓰레드를 하나 생성하고, thread함수를 돌리며niters만큼 cnt niters만큼 카운트한다. 식별자는 tid1이다.
  pthread_create(&tid2, NULL ,thread, &niters);	//쓰레드를 하나생성하고, thread함수를 돌리며niters만큼 cnt niters만큼 카운트한다. 식별자는 tid2이다.
  pthread_join(tid1, NULL);		//tid1의 종료를 기다린다.
  pthread_join(tid2, NULL);		//tid2의 종료를 기다린다.

  /* Check result */
  if(cnt != (2 * niters))	//쓰레드가 두개가 돌았는데 niters의 두배만큼 카운트된게 아니라면 오류가 난것이다.
	printf("BOOM! cnt=%d\n", cnt);
  else		//정상출력이며 cnt를 출력한다.
	printf("OK cnt=%d\n", cnt);
  exit(0);
}

void *thread(void *vargp)
{
  int i, niters = *((int *)vargp);

  for (i = 0; i < niters; i++)
    cnt++;                   

  return NULL;
}

