#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

pthread_barrier_t barrier;

void * work( void* param)
{
  int id=(intptr_t)param;
  printf("Thread arrived %i\n", id );
  pthread_barrier_wait( &barrier );
  printf("Thread departed %i\n", id );
}

void main()
{
  pthread_t threads[10];
  pthread_barrier_init( &barrier, 0, 10 );      //10개까지 쓰레드를 잠재우고, 10개가 되면 깨어남
  for ( int i=0; i<10; i++ )
  {
    pthread_create( &threads[i], 0, work, (void*)(intptr_t)i );
  }
  for ( int i=0; i<10; i++ )
  {
    pthread_join( threads[i], 0 );
  }
  pthread_barrier_destroy( &barrier );
}