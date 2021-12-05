#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;		//뮤텍스 객체 선언.
volatile int counter = 0;	//쓰레드의 공유자원 , counter변수를 공유하여 사용한다.

void *count(void *param)
{ 
  for ( int i=0; i<100; i++ )
  {
    pthread_mutex_lock( &mutex );		//mutex_lock을 사용하여 ,쓰레드들이 한 공유자원을 동시에 접근할 수 없게 만든다.
    counter++;
    printf( "Count = %i\n",counter);
    pthread_mutex_unlock(&mutex);		//mutex_lock상태를 unlock한다.
  }
	return NULL;
} 
 
int main() 
{ 

  pthread_t thread1, thread2; 		//쓰레드의 식별을 위한 변수성언
  pthread_mutex_init( &mutex, 0 );	// 뮤텍스 객체 초기화, 기본 특성으로 초기화 했음
  pthread_create( &thread1, 0, count, 0 ); 		//1번 쓰레드 생성
  pthread_create( &thread2, 0, count, 0 ); 		//2번 쓰레드 생성
  pthread_join( thread1, 0 ); 	//1번쓰레드의 종료를 기다린다.
  pthread_join( thread2, 0 ); 	//2번 쓰레드의 종료를 기다린다.
  pthread_mutex_destroy( &mutex );		//mutex를 사용종료한다.
  return 0; 
} 

