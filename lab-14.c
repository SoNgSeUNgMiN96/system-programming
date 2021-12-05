#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 

int main() { 

	FILE *read_fp, *write_fp; 

	char buffer[BUFSIZ]; 
	int failCode =1;

	read_fp = popen("who", "r"); 	//who 명령어의 결과를 읽어온다.
	write_fp = popen("sort", "w"); 		//who명령어로 읽어진 데이터를 sort에 써서 정렬하여 출력


	if(read_fp != NULL) { 	//read되었다면 
	
		fread(buffer, sizeof(char), BUFSIZ, read_fp); 	//버퍼에 who의 결과를 저장
		failCode =0;
		pclose(read_fp); 

	} 
	if(write_fp!=NULL && failCode==0){		//읽기와 쓰기가 성공하였다면
		
		fwrite(buffer, sizeof(char), strlen(buffer), write_fp); 	//버퍼에있는내용을 sort에 씀 (sort는 읽은 데이터를 정렬하여 출력해줌)
		pclose(write_fp);
		exit(EXIT_SUCCESS); 
	}	


	exit(EXIT_FAILURE); 
}

