#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]){
	
	if(argc!=2)
		printf("usage: a.out <pathname>");

	struct stat buf;
	int year, month, day, hour,min;
	

	stat(argv[1],&buf);

	printf("inode number = %d\n",(int)buf.st_ino);
	printf("파일 생성 시간 = %d (19700101로부터 흐른시간)\n",(int)buf.st_ctime);
	printf("파일 마지막 업데이트 시간 = %d\n",(int)buf.st_mtime);
	printf("파일 마지막 접근 시간 = %d\n",(int)buf.st_atime);


}
