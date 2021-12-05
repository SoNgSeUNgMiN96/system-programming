#include <pthread.h>

pthread_spinlock_t lock;        //spinlock  변수 lock

void lockandunlock()
{
  int i = 10000;
  while ( i>0 )
  {
    pthread_spin_lock( &lock );     //spinlock을 한다.
    i--;
    pthread_spin_unlock( &lock );       //spin unlock을 한다.
  }
}

void main()
{
  pthread_spin_init( &lock, PTHREAD_PROCESS_PRIVATE );  //spinlock 초기화
  lockandunlock();
  pthread_spin_destroy( &lock );        
}