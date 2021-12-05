#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct 
{
  double      *a;
  double      *b;
  double     sum; 
  int     veclen; 
} DOTDATA;

#define NUMTHRDS 4
#define VECLEN 100

DOTDATA dotstr;
pthread_t callThd[NUMTHRDS];    //thread를 식별자를 담을 callThd배열을 생성한다 (4칸)
pthread_mutex_t mutexsum;   //쓰레드가 자원을 동시에 접근하지 못하게 막을 mutex선언

void *dotprod(void *arg)
{
  pthread_mutex_lock( &mutexsum );
  int i, start, end, len;
  long offset;
  double mysum, *x, *y;
  offset = (long)arg;     //arg는 0 1 2 3 이 들어온다.
  len = dotstr.veclen;
  start = offset*len;
  end   = start + len;
  x = dotstr.a;
  y = dotstr.b;
  mysum = 0;
  for (i=start; i<end ; i++) {
    mysum += (x[i] * y[i]);
  }
  
  int v = dotstr.sum;
  v += (int)mysum;
  dotstr.sum = v;
  pthread_mutex_unlock( &mutexsum);
  pthread_exit((void*) 0);
}

int main (int argc, char *argv[])
{
  pthread_mutex_init(&mutexsum,0);
  long i;
  double *a, *b;
  void *status;
  pthread_attr_t attr;

  a = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));    //400칸짜리 double 배열 선언
  b = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));    //400칸짜리 double 배열 선언

  for (i=0; i<VECLEN*NUMTHRDS; i++) {   //모두 1.0으로 초기화
    a[i]=1.0;
    b[i]=a[i];
  }

  dotstr.veclen = VECLEN;     //veclen 은 100
  dotstr.a = a;     //a배열 저장
  dotstr.b = b;     //b배열 저장
  dotstr.sum=0;   //sum 은 0으로 초기화.
  
	pthread_attr_init(&attr);   //attr 초기화.
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);    //다른 thread끝나고 동작하는 thread. 

  for(i=0; i<NUMTHRDS; i++) {
    pthread_create(&callThd[i], &attr, dotprod, (void *)i);
  }

  pthread_attr_destroy(&attr);

  for(i=0; i<NUMTHRDS; i++) {
    pthread_join(callThd[i], &status);
  }

  printf ("Sum =  %f \n", dotstr.sum);
  pthread_mutex_destroy( &mutexsum);		//mutex를 사용종료한다.
  free (a);
  free (b);
} 




