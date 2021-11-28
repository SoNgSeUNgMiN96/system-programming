#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* pthread_code( void * param )
{
  printf("In thread code\n");
}

int main()
{
  pthread_t thread;
  int status;
  int thr_id = pthread_create( &thread, 0, pthread_code, 0 );
  printf("In main thread\n");

  //pthread_join(thread,(void**)&status);	//쓰레드의 종료를 기다리지않으면, 메인함수가 먼저 종료됨
}

