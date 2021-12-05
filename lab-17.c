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
  
  int return_value[10];
  
  for ( int i=0; i<10; i++ )	//스레드를 순차적으로 기다리지않고 하단 포문으로 기다리면, 한 스레드를 기다리다 다른 스레드가 종료하여, 세그먼트 코어덤프발생
  {
	  pthread_create( &thread[i], 0, child_routine, (void*)(intptr_t)i );
	  pthread_join(thread[i] , (void**)&return_value[i]);
	  if (return_value[i]<0)
		  perror("pthread_join");
  }
	
  //for (int i=0;i<10;i++){
	
	  //pthread_join(thread[i] , (void**)&return_value[i]);
	  //printf("return = %d\n",return_value[i]);
  
  //}
  return 0;
}

