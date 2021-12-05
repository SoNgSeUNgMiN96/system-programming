#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int res = mkfifo("/tmp/my_fifo", 0666);	//추후 사용할 FIFO 파일을 생성한다
	if (res == 0) 		//성공
		printf("FIFO created\n");
	exit(EXIT_SUCCESS);
}
