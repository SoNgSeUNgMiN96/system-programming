#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

void* child_routine(void * param )
{
  int id = (intptr_t)param;
  printf( "Detach thread %d\n", id );
  pthread_detach( pthread_self() );
}

int main()
{
  pthread_t thread[10];
  
  //void* return_value[10];
  
  for ( int i=0; i<10; i++ )
  {
     pthread_create( &thread[i], 0, child_routine, (void*)(intptr_t)i );
  }

  sleep(1);	//sleep 하지 않으면, 메인이 스레드의 실행이 다 되기전 종료됨.

  return 0;
}

