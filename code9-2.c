#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *write_fp;
	char buffer[BUFSIZ + 1];

	sprintf(buffer, "Once upon a time, there was…\n");	//sprintf는 뒷 출력값을 앞 버퍼에 저장한다.
	
	write_fp = popen("od -c", "w");	//od는  바이너리 파일의 내용을 확인하는 프로그램. -c옵션을 넣으면 문자 형태로 확인할 수 있다.

	if(write_fp != NULL) {

		fwrite(buffer, sizeof(char), strlen(buffer), write_fp);	//fwrite (스트림에 쓰여질 배열을 가리키는 포인터 , 그 배열의 원소크기 (int or char 등), 원소수,쓰여질 파일의 파일포인터 )
		pclose(write_fp);
		exit(EXIT_SUCCESS);

	}
	exit(EXIT_SUCCESS);
}
