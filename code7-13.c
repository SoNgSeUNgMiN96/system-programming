#include <unistd.h>

int main(int argc, char *argv[]){

	char *av[3];

	av[0] = "ls";
	av[1] = "-l";
	av[2] = (char*)0;

	execv("/bin/ls",av);
	//   /bin/ls 경로의 ls 명령어와 뒤에 argv[1] 로 받은 명령어를 실행한다.
}
