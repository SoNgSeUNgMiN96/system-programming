#include  <sys/types.h>  
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


static void charatatime(char *);

int main(void) {
  pid_t  pid;

  if ( (pid = fork()) < 0) perror("fork error");	//포크를 하고
  else if (pid == 0)  charatatime("output from child\n");	//자식일 경우 
  else                charatatime("output from parent\n");	//부모일경우
  exit(0);
}

static void charatatime(char *str) {
  char  *ptr;
  int    c;

  setbuf(stdout, NULL);      /* set unbuffered */
  for (ptr = str; c = *ptr++; )	//한 글자씩 읽어들여 출력한다.
    putc(c, stdout);
}
