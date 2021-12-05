/*
 * 부모 프로세스는 sample.txt에 있는 문자열의 길이만큼 자식 프로세스를 생성한 후 ,waitpid를 사용하여  생성된 순서대로 거두어 들이는 프로그램. 이때 자식 프로세스는 자신의 순서만큼 문자열을 복사해서 output.txt에 작성하고 종료하는 프로그램입니다.
 */


#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (){
	char buffer[512], buffer2[512];
	int *pids , fd ,fd2;
	int status,nread;
	int i=-1;	
	
	if ((fd = open("sample.txt",O_RDONLY))==-1){
		exit(1);
	}


	nread = read(fd,buffer,512);	//nread 에  읽어온 파일의 글자수를 저장 *(만약 512바이트보다 큰 파일이면 소스를 수정해야함.)
	pids = (int*)malloc(sizeof(int)*(nread-1));		//pid들을 저장할 pids배열 선언

	//printf("nread = %d\n",nread); 실제 글자수보다 nread가 1개 많이 나오는것을 확인. system인경우 nread는 7임. 이를 고려해서 다뤄야함

	if ((fd2 = open("output.txt",O_RDWR|O_CREAT,0644))==-1)	//output.txt 생성
		exit(1);

	while (pids[++i] =fork()){	//부모만 글자수만큼 자식생성 후 wait pid를 매번해줌
		
		waitpid(pids[i],&status,0);
		if(i==nread-2)
			break;
	}

	if(pids[i]==0){	//생성된 자신 프로세스는 읽을 파일과 , 쓸 파일을 모두 SEEK_SET으로 돌려놓음

		lseek(fd,0,SEEK_SET);
		read(fd,buffer2,i+1);	//처음으로 돌아간 fd에서 i+1글자만큼 읽음
		buffer2[i+1]=0;		//문자열의 종료를 세팅.
		printf("%s\n",buffer2);	//write하는 버퍼 출력
		lseek(fd2,0,SEEK_SET);	//쓸 파일 또한 SEEK_SET 으로 돌려서 write
		write(fd2,buffer2,i+1);	
		if(i!=nread-2)
			write(fd2,0,1);	//종료문자 세팅
	}
	close(fd);
	close(fd2);
	
	return 0;

}
