#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
#define NAME "socket"

int main() 
{ 
	int	sock, length, fromlen;
	struct sockaddr_un name, from;
	char buf[1024];
	
	sock=socket(PF_UNIX, SOCK_DGRAM, 0);	//소켓은 로컬로 열어준다.
	name.sun_family=PF_UNIX;
	strcpy(name.sun_path, NAME); 
	bind(sock,(struct sockaddr*)&name, sizeof(struct sockaddr_un));//bind
	printf("socket %s\n", NAME);
	recvfrom(sock, buf, 1024, 0,(struct sockaddr*)&from, &fromlen); 	//클라이언트로부터 데이터수신한다 . 각 매개변수는 (소켓,저장할 버퍼 , 버퍼의길이 ,수신옵션,전송한곳의주소정보 , 전송한 주소의크기) 
	printf("%s\n", buf); 
	//printf("path = %s\n",from.sun_path);

	unlink(NAME); 
	close(sock);
}

