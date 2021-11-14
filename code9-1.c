#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *read_fp;
	char buffer[BUFSIZ +1]; 	//BUFSIZ는 최소256이되고,시스템이 효율적인 값을 선택함
	int chars_read;

	//printf("BUFSIZ = %d\n",BUFSIZ);

	memset(buffer, '\0', sizeof(buffer));
	read_fp = popen("uname -a", "r");	//uname -a 에대한 값을 파이프를통해 입력받음
	
	if(read_fp != NULL) {

		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);	//buffer에 파이프를통해 입력받은값을 저장함.

		if(chars_read > 0) {		//에러가 없다면, 버퍼 출력
			printf("output was:-\n%s\n", buffer);
		}

		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}else{
		printf("popen error\n");
	}
	exit(EXIT_FAILURE);
}
