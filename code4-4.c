#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>
#include <mach/error.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int    i;
  struct stat    statbuf;
  struct utimbuf  timebuf;

  for (i = 1; i < argc; i++) {
    if (stat(argv[i], &statbuf) < 0) 
      perror(argv[i]);

    if (open(argv[i], O_RDWR | O_TRUNC) < 0)  
      perror(argv[i]);

    timebuf.actime  = statbuf.st_atime;
    timebuf.modtime = statbuf.st_mtime;
    if (utime(argv[i], &timebuf) < 0) 
      perror(argv[i]);
  }
  return 0;
}

