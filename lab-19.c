#include <pthread.h>	//항상 -lpthread 옵션을 줘야한다.
#include <stdio.h>
#include <semaphore.h>

sem_t sem_one, sem_two;	//semaphore 변수 두개 선언.

void *func1(void * param)
{
	sem_wait(&sem_two);		//sem_two가 1이면 접근이 가능하다. 처음엔 sem_two가 1이다. 0으로 바뀌며 실행
	printf( "Thread 1\n" );		//이것을 실행한 후
	sem_post(&sem_one);	//sem_one = 0 -> 1 이되어서 fun2에서 실행이된다 
}

void *func2(void * param)
{
  	sem_wait(&sem_one);	//sem_one이 1이되어서 실행이 되고, sem_one = 1->0으로 변경됨.
	printf( "Thread 2\n" );	//이것을 실행하고,
	sem_post(&sem_two);	//sem_two는 다시 증가시킨다. (func1을 1회만 실행할거라 필요없는과정)
}

void main()
{
  pthread_t threads[2]; 
  sem_init(&sem_one,0,0);	//sem_one은 0으로 초기화
  sem_init(&sem_two,0,1);	//sem_two 는 1로 초기화하여 sem_wait(&sem_two)부터 실행시킨다

  pthread_create( &threads[0], 0, func1, 0 );	//쓰레드 func1 생성 및 threads[0]에 쓰레드 저장
  pthread_create( &threads[1], 0, func2, 0 );	//쓰레드 func2 생성 및 threads[1]에 쓰레드 저장
  pthread_join( threads[0], 0 );		//쓰레드의 종료를 기다림.
  pthread_join( threads[1], 0 );		//쓰레드의 종료를 기다림.
	
  sem_destroy(&sem_one);	//sem 파괴
  sem_destroy(&sem_two);	//sem 파괴
}
