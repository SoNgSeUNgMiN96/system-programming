/*
 * setjmp , longjmp 를 학습하기위한 예제입니다.
 */

#include <setjmp.h>  
#include <stdio.h>
#include <stdlib.h>

static void  f1(int, int, int);	//f1 정의
static void  f2(void);	//f2 정의

static jmp_buf  jmpbuffer;	//jmp_buf 선언

int main(void) {
       int  count;
       int  val;
       int  sum;

       count = 2; val = 3; sum = 4;
       printf("Initial values: count = %d, val = %d, sum = %d\n", count, val, sum);
       if (setjmp(jmpbuffer) != 0) {
	       printf("after longjmp: count = %d, val = %d, sum = %d\n", count, val, sum);
	       exit(0);
       }
       count = 97; val = 98; sum = 99; /* changed after setjmp, before longjmp */
       f1(count, val, sum);   
}

static void f1(int i, int j, int k) {
	printf("in f1(): count = %d, val = %d, sum = %d\n", i, j, k);
	f2();
}

static void f2(void) {
  longjmp(jmpbuffer, 1);
}
