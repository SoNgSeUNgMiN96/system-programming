#include  <sys/types.h>  /* tshm.c */
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define  ARRAY_SIZE   40000
#define  MALLOC_SIZE  100000
#define  SHM_SIZE  100000
#define  SHM_MODE  (SHM_R | SHM_W)  /* user read/write */

char  array[ARRAY_SIZE];  /* uninitialized data = bss */

int main(void) {
  int shmid;  char  *ptr, *shmptr;

  printf("array[] from %s to %s\n", &array[0], &array[ARRAY_SIZE]);
  printf("stack around %ls\n", &shmid);

  if ( (ptr = malloc(MALLOC_SIZE)) == NULL) perror("malloc error");
  printf("malloced from %s to %s\n", ptr, ptr+MALLOC_SIZE);

  if ( (shmid = shmget(IPC_PRIVATE, SHM_SIZE, SHM_MODE)) < 0)	//유저 리드 라이트 기능으로 사이즈 100000 크기의 공유메모리 생성  
     perror("shmget error");

  if ( (shmptr = shmat(shmid, 0, 0)) == (void *) -1)  perror("shmat error");	//공유메모리를 프로세스에 첨부
  printf("shared memory attached from %s to %s\n", shmptr, shmptr+SHM_SIZE);

  if (shmctl(shmid, IPC_RMID, 0) < 0) perror("shmctl error");
  exit(0);
}
