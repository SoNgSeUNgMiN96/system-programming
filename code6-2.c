#include <stdlib.h> /* viewenv.c */
#include <stdio.h>

extern char **environ;	//환경변수 배열을 가져온다.

int main()
{
	char **env = environ;		//문자배열에 포인터에 주소를 복사해온다..

	while(*env){	//요소가있는동안.
		printf("%s\n",*env);	//환경변수를 출력한다.
		env++;
	}
	exit(0);
}

