#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
*. 이 프로그램은 파일명을 변경해주는 프로그램입니다. ./실행파일명 원본파일명 변경할파일명 으로 실행하여 파일명을 수정합니다.
*/


int main(int argc, char *argv[]) {
    
	if (argc<3){
		printf("more argc\n");
		exit(1);
	}
	char *fname = argv[1];

   
    	if (link(fname, argv[2]) < 0) {
        	fprintf(stderr, "link error\n");
        	exit(1);
    	}

    	unlink(argv[1]);

    	exit(0);
}
