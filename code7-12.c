#include <unistd.h>

int main(int argc, char *argv[]){

	execl("/bin/ls","ls",argv[1],(char*)0);
	//   /bin/ls 경로의 ls 명령어와 뒤에 argv[1] 로 받은 명령어를 실행한다.
}
