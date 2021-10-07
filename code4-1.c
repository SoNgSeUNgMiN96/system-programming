#include <sys/types.h>  /* unlink.c */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <mach/error.h>
#include <stdio.h>

int main()
{
  int fd, len;
  char buf[20];

  fd = open("tempfile", O_RDWR | O_CREAT | O_TRUNC, 0666);
  if (fd == -1) perror("open1");
  printf("before delete , fd num is %d\n",fd); 
  printf("unlink num is %d\n",unlink("tempfile"));  //tempfile이 삭제된다.
  printf("fd num is %d\n",fd); 
  len = write(fd, "How are you?", 12);  //삭제된 이후 fd 를 확인  
  if (len != 12) perror("write");
  printf("seek pointer is %lld\n",lseek(fd, 0L, SEEK_SET));
  printf("fd num is %d\n",fd); 
  len = read(fd, buf, sizeof(buf));
  if (len < 0) perror("read");
  buf[len] = '\0';
  printf("%s\n", buf);
  close(fd);
  fd = open("tempfile", O_RDWR);
  if (fd == -1) perror("open2");
  close(fd);
  return 0;
}

