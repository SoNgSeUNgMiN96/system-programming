#include <pthread.h>
#include <stdio.h>

int  main()
{
  size_t stacksize;
  pthread_attr_t attributes; 	//thread의 속성값을 담을 구조체변수 attributes을 선언한다.
  pthread_attr_init( &attributes );	//pthread_attr_init는 쓰레드 속성 객체인 attributes를 초기화. 
  pthread_attr_getstacksize( &attributes, &stacksize );	//stacksize를 받아와 stacksize변수에 저장해준다.
  printf( "Stack Size = %zu\n", stacksize);		//저장된 stacksize변수를 출력해준다.
  pthread_attr_destroy( &attributes );		//pthread_attr_init에 의해 생성된 thread attribute 객체인 attr을 제거한다. 
}

